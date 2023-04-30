#include <std.h>
#include <daemons.h>
inherit SPELL;

int time,flag;

void create(){
    ::create();
    set_spell_name("hail of crystals");
    set_spell_level(([ "psion" : 6 ]));
    set_discipline("shaper");
    set_spell_sphere("metacreatvity");
    set_syntax("cast CLASS hail of crystals");
    set_description("This power will cause the shaper to fill the air with razor-sharp crystals, which churn and damage most things in the area. Due to the shaper's natural control over crytals, this power will not damage the shaper, his party members, or any beings following him. The power becomes longer lasting as the shaper grows stronger.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("fort");
    aoe_spell(1);
    set_aoe_message("%^C059%^(%^C243%^s%^C245%^h%^C247%^r%^C243%^e%^C245%^d%^C247%^d%^C243%^e%^C245%^d %^C059%^by shards of %^C206%^c%^C160%^r%^C208%^y%^C226%^s%^C046%^t%^C051%^a%^C020%^l%^C090%^s%^C059%^)%^CRST%^");
}

void spell_effect(int prof){
    tell_object(caster, "%^C255%^With a flick of your wrist, you send three %^C206%^c%^C160%^r%^C208%^y%^C226%^s%^C046%^t%^C051%^a%^C020%^l%^C090%^s %^C255%^hurtling through the air!%^CRST%^");
    tell_room(place, "%^C255%^"+caster->query_cap_name()+"%^C255%^ sends three %^C206%^c%^C160%^r%^C208%^y%^C226%^s%^C046%^t%^C051%^a%^C020%^l%^C090%^s %^C255%^hurtling into the air with a flick of "+caster->query_possessive()+" wrist!%^CRST%^", caster);
    time = 0;

    addSpellToCaster();
    spell_successful();
    execute_attack();
}


void execute_attack(){
    object *foes, *rooms_nearby, me;
    string target_limb;
    int i, damage;

    if(!objectp(caster)){
        dest_effect();
        return;
    }

    if(!objectp(me = this_object())) return;
    if(!objectp(place)) return;

    if (!flag){
        flag = 1;
        ::execute_attack();
        return;
    }

    foes = target_selector();
    foes -= ({caster});
    if(caster->query_followers()) foes -= caster->query_followers();
    if(time > clevel * 3){
        dest_effect();
        return;
    }

    if(arrayp(rooms_nearby = nearbyRoom(place, 2))) message("info", "%^C059%^Shards of %^C206%^c%^C160%^r%^C208%^y%^C226%^s%^C046%^t%^C051%^a%^C020%^l%^C090%^s %^C059%^slice through the sky, shearing everything within the storm!%^CRST%^", rooms_nearby);

    define_base_damage(0); //lazy re-roll
    damage = sdamage;

    for (i=0; sizeof(foes), i < sizeof(foes); ++i){
        if(!objectp(foes[i])) continue;
        if(!objectp(caster)){
            dest_effect();
            return;
        }
        if(!present(caster, place) && caster != target){
            dest_effect();
            return;
        }
        if(!present(foes[i], place)) continue;

        target_limb = foes[i]->return_target_limb();

        if(do_save(foes[i], 0)) damage_targ(foes[i], target_limb, damage/2, "slashing");
        else damage_targ(foes[i], target_limb, damage, "slashing");

        if(objectp(foes[i])) spell_kill(foes[i], caster);
    }

    ++time;

    if(present(caster, place)) environment(caster)->addObjectToCombatCycle(me, 1);
    else{
        dest_effect();
        return;
    }
}


void dest_effect(){
    object me;

    if(objectp(place)) tell_room(place, "%^C255%^The %^C206%^c%^C160%^r%^C208%^y%^C226%^s%^C046%^t%^C051%^a%^C020%^l%^C090%^s %^C255%^churning in the air grind to dust and are blown away by the wind.%^CRST%^");

    ::dest_effect();

    if(objectp(me = this_object())) me->remove();
}


string query_cast_string(){
    return "%^C255%^"+caster->query_cap_name()+" %^C255%^withdraws three %^C160%^t%^C167%^o%^C174%^u%^C181%^r%^C186%^m%^C191%^a%^C118%^l%^C155%^i%^C150%^n%^C145%^e %^C160%^g%^C174%^e%^C191%^m%^C118%^s %^C255%^from a pouch.%^CRST%^";
}

