#include <std.h>
#include <daemons.h>

#define DELAY 300

inherit FEAT;

void reverse_shape();

void create()
{
    ::create();
    feat_type("instant");
    feat_category("CrimsonTemplar");
    feat_name("banishing blade");
    feat_prereq("Crimson Templar L7");
    feat_syntax("banishing_blade");
    feat_desc("With this feat, the Crimson Templar instills their weapon with holy power, granting it the ability to banish unworthy souls with a mere touch. When using this active feat, your normal weapon strikes will automatically destroy any minion beloning to an evil or chaotic caster/summoner. This feat has a cooldown and limited duration.");
    set_target_required(0);
    allow_blind(1);
    set_required_for(({}));
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("crimson_templar") < 7)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_banishing_blade(string str)
{
    object feat;
    if(!objectp(this_player())) { return 0; }
    feat = new(base_name(this_object()));
    feat->setup_feat(this_player(),str);
    return 1;
}

void execute_feat()
{
    if (FEATS_D->is_active(caster, "banishing blade "))
    {
        tell_object(caster, "%^CYAN%^You release the banishing power from your weapons.%^RESET%^");
        dest_effect();
        return;
    }    
    if(caster->query_casting())
    {
        tell_object(caster,"%^BOLD%^You can't use banishing blade while casting a spell.");
        dest_effect();
        return;
    }   
    if(caster->query_property("using instant feat"))
    {
        tell_object(caster,"You are already in the middle of using a feat!");
        dest_effect();
        return;
    }    
    if(caster->cooldown("banishing blade"))
    {
        tell_object(caster, "You aren't ready to use banishing blade yet.");
        dest_effect();
        return;
    }
    if(!sizeof(caster->query_wielded()))
    {
        tell_object(caster, "You need to be wielding a weapon to use banishing blade.");
        dest_effect();
        return;
    }
    
    ::execute_feat();

    tell_object(caster,"%^C039%^You channel your given power and %^C051%^instill%^C039%^ your weapon with %^C051%^holy energy%^CRST%^.");
    caster->set_property("using instant feat",1);
    caster->set_property("active_feats", ({ this_object() }));
}

void execute_attack()
{
    object shape;
    string pact, file;

    if(!objectp(caster)) { return; }

    caster->remove_property("using instant feat");
    ::execute_attack();
    
    if(!sizeof(caster->query_wielded()))
    {
        tell_object(caster, "You need to be wielding a weapon to use banishing blade");
        dest_effect();
        return;
    }
        
    
    tell_object(caster, "%^C039%^You feel white hot energy course through your weapon as you instill it with banishing power.%^CRST%^");
    tell_room(place, "%^BOLD%^" + caster->query_cap_name() + " instills " + caster->query_possessive() + " with banishing power!%^RESET%^", caster);
    caster->set_property("banishing blade", 1);
    
    caster->add_cooldown("banishing blade", DELAY);
    call_out("dest_effect", 60);
    
    return;
}

void dest_effect()
{   
    if(objectp(caster))
    {
        caster->remove_property("banishing blade");
        tell_object(caster, "%^CYAN%^The banishing energy fades from your weapon.%^RESET%^");
    }
    
    ::dest_effect();
    remove_feat(this_object());
    return;
}
