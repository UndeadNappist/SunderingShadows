//Fire Storm coded by Bane//
//removed from druids for balance after discussion with Ts and players ~Circe~ 8/5/13

#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int time,first_execute;


void create()
{
    ::create();
    set_spell_name("fire storm");
    set_spell_level(([ "cleric" : 7, "druid" : 7, "monk" : 17 ]));
    set_spell_sphere("invocation_evocation");
    set_monk_way("way of the elements");
    set_syntax("cast CLASS fire storm");
    set_circle("wildfire");
    set_damage_desc("AOE fire damage");
    set_description("When the fire storm spell is cast, the whole area is shot through with sheets of roaring flame. Any target in the area of effect takes damage every round while the spell is in effect, but it does not damage the caster. This spell does not work in conjunction with the monsoon priest spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("reflex");
    aoe_spell(1);
    set_aoe_message("%^CRST%^%^RESET%^%^C089%^(%^C196%^a%^C160%^b%^C124%^l%^C088%^a%^C052%^z%^C088%^e %^C052%^w%^C088%^i%^C124%^t%^C160%^h %^C166%^r%^C130%^o%^C124%^a%^C160%^r%^C196%^i%^C160%^n%^C124%^g %^C130%^f%^C166%^l%^C130%^a%^C124%^m%^C160%^e%^C196%^s%^C089%^)%^CRST%^");
    set_immunities( ({ "fire" }) );
}

void spell_effect(int prof)
{
    tell_object(caster, "%^RESET%^%^CRST%^%^C160%^You wave your hands around, unleashing the %^C088%^f%^C124%^u%^C088%^r%^C124%^y%^RESET%^%^C160%^ of the %^C088%^e%^C124%^l%^C160%^e%^C196%^m%^C160%^e%^C124%^n%^C088%^t%^C124%^a%^C160%^l %^C088%^p%^C124%^l%^C160%^a%^C196%^n%^C160%^e %^C124%^o%^C088%^f %^C124%^f%^C160%^i%^C196%^r%^C160%^e%^RESET%^%^C160%^!%^CRST%^");
    tell_room(place, "%^RESET%^%^CRST%^%^C160%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^ %^C160%^waves "+caster->query_possessive()+" %^C160%^hands around, unleashing the %^C088%^f%^C124%^u%^C088%^r%^C124%^y%^RESET%^%^C160%^ of the %^C088%^e%^C124%^l%^C160%^e%^C196%^m%^C160%^e%^C124%^n%^C088%^t%^C124%^a%^C160%^l %^C088%^p%^C124%^l%^C160%^a%^C196%^n%^C160%^e %^C124%^o%^C088%^f %^C124%^f%^C160%^i%^C196%^r%^C160%^e%^RESET%^%^C160%^!%^CRST%^", caster);
    place->set_property("spelled", ({TO}) );
    caster->set_property("spelled",({TO}));
    spell_duration = ROUND_LENGTH * (5 + clevel * 2);
    set_end_time();
    addSpellToCaster();
    spell_successful();
    execute_attack();
    call_out("dest_effect", spell_duration);
}


void execute_attack()
{
    string target_limb;
    object *foes;
    int i, damage;

    if(!objectp(place))
    {
        dest_effect();
        return;
    }
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }

    if (!first_execute)
    {
        first_execute++;
        ::execute_attack();
        return;
    }

    foes = target_selector();

    if (!present(caster,place))
    {
        dest_effect();
        return;
    }

    if (!present(caster,place))
    {
        dest_effect();
        return;
    }

    if(spell_type == "monk" && sizeof(foes)) { MAGIC_D->elemental_opportunist(caster, foes[0]); }

    damage = sdamage;

    tell_room(place, "%^CRST%^%^RESET%^%^C124%^S%^C088%^h%^C124%^e%^C160%^e%^C124%^t%^C088%^s %^C124%^o%^C160%^f %^C124%^f%^C088%^l%^C124%^a%^C160%^m%^C124%^e %^C088%^r%^C124%^a%^C160%^g%^C124%^e %^C088%^a%^C124%^c%^C160%^r%^C124%^o%^C088%^s%^C124%^s %^C160%^t%^C124%^h%^C088%^e %^C124%^a%^C160%^r%^C088%^e%^C124%^a%^C088%^, %^C124%^i%^C160%^n%^C124%^c%^C088%^i%^C124%^n%^C088%^e%^C124%^r%^C160%^a%^C124%^t%^C088%^i%^C124%^n%^C088%^g %^C160%^e%^C124%^v%^C088%^e%^C124%^r%^C160%^y%^C124%^t%^C088%^h%^C124%^i%^C088%^n%^C124%^g %^C160%^i%^C124%^n %^C088%^s%^C160%^i%^C124%^g%^C088%^h%^C124%^t%^C088%^!%^CRST%^");

    for(i=0;sizeof(foes),i<sizeof(foes);i++)
    {
        if(!objectp(foes[i])) continue;
        if(foes[i] == caster) continue;
        if(!present(foes[i],place)) continue;
        if(interactive(foes[i]) && foes[i]->query_level() < 6) continue;
        if(do_save(foes[i],0))
        {
            damage = damage/2;
        }

        target_limb = foes[i]->return_target_limb();
        damage_targ(foes[i], target_limb, damage,"fire");
        if(present(caster, place))
        {
            if (objectp(foes[i])) spell_kill(foes[i],caster);
        }
    }

    if (present(caster,place) && !caster->query_unconscious())
    {
        place->addObjectToCombatCycle(TO,1);
        return;
    }
    else
    {
        dest_effect();
        return;
    }
}


void dest_effect()
{
    if(objectp(place))
    {
        tell_room(place, "%^CRST%^%^RESET%^%^C124%^The fire storm weakens and dissipates.%^CRST%^");
        place->remove_property_value("spelled", ({TO}) );
    }
    if(objectp(caster))
    {
        caster->remove_property_value("spelled", ({TO}) );
    }
    remove_call_out("do_storm");
    ::dest_effect();
    if(objectp(TO)) { TO->remove(); }

}