#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

int mod, duration, extra;

void create(){
    ::create();
    feat_type("instant");
    feat_category("ArcaneArcher");
    feat_name("timestop volley");
    feat_syntax("timestop_volley");
    feat_prereq("Arcane Archer L4");
    feat_desc("For a while, the very time around the archer slows as she reloads and shoots her weapon, increasing her rate of fire for a short while. The caster moves faster, her reflexes improve, and she shoots more arrows in turn.");
    set_target_required(0);
}

int allow_shifted(){ return 0; }

int prerequisites(object ob){
    if(!objectp(ob)){ return 0; }
    if((int)ob->query_class_level("arcane_archer") < 4){
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_timestop_volley(string str){
    object feat;
    if(!objectp(this_player())){ return 0; }
    feat = new(base_name(this_object()));
    feat->setup_feat(this_player(), str);
    return 1;
}

void execute_feat(){
    int i,intelligence;
    if((int)caster->query_property("timestop_volley")){ //won't stack with the Prescience power
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^You are already enjoying the effects of timestop volley!%^CRST%^");
        this_object()->remove();
        return;
    }
    ::execute_feat();
    
    if((int)caster->query_property("using instant feat")){
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^You are already in the middle of using a feat!%^CRST%^");
        dest_effect();
        return;
    }
    
    caster->set_property("using instant feat",1);
    tell_object(caster, "%^RESET%^%^CRST%^%^C100%^You murmur a few %^C101%^s%^C144%^yl%^C101%^l%^C144%^ab%^C101%^l%^C144%^es %^RESET%^%^C100%^and the very time around you %^C058%^slows %^C100%^as you reload.%^CRST%^");
    tell_room(place, "%^RESET%^%^CRST%^%^C100%^It seems as if "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C100%^ reloads with unnatural speed!%^CRST%^", caster);
    mod = 1 + clevel / 16;
    duration = 120 + (clevel * 10);
    caster->set_property("fighter_attacks_mod",mod);
    caster->add_skill_bonus("athletics",mod);
    caster->add_saving_bonus("reflex",mod);

    caster->set_property("timestop_volley",1);
    call_out("check",ROUND_LENGTH);
    call_out("dest_effect",duration);
    return;
}


void execute_attack() 
{
    if(!objectp(caster)) 
    {
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");
    ::execute_attack();
}


void check()
{
    object *weapons;
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    ::execute_attack();

    weapons = caster->query_wielded();
    if(sizeof(weapons))
    {
        if(!weapons[0]->is_lrweapon())
        {
            tell_object(caster, "%^RESET%^%^CRST%^%^C059%^You can't use timestop volley feat unless you are wielding a ranged weapon!%^CRST%^\n");
            dest_effect();
            return;
        }
    }

    if(sizeof(caster->query_attackers()))
    {
        tell_object(caster, "%^RESET%^%^CRST%^%^C100%^A missile shot in the past reaches its target!%^CRST%^");
        caster->execute_attack();
        if(!random(2))
        {
            tell_object(caster, "%^RESET%^%^CRST%^%^C100%^Another missile from the past arrives at target!%^CRST%^");
            caster->execute_attack();
        }
    }
    call_out("check",ROUND_LENGTH);
}


void dest_effect(){
    ::dest_effect();
    if(!objectp(caster)){
        remove_feat(this_object());
        return;
    }
    tell_object(caster, "%^RESET%^%^CRST%^%^C058%^Everything around you begins to %^C100%^s%^C101%^p%^C144%^e%^C101%^e%^C100%^d %^C058%^back up, and time around you returns to %^C101%^normal%^C058%^.%^CRST%^");
    caster->set_property("fighter_attacks_mod",-mod);
    caster->add_skill_bonus("athletics",-mod);
    caster->add_saving_bonus("reflex",-mod);
    caster->remove_property("timestop_volley");
    remove_feat(this_object());
    return;
}

