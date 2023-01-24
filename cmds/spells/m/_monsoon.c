//Monsoon - Istishian fire storm alternative, coded by Nienne, 05/05//
//changed to general priest spell for a fire storm ascetic alternative. Nienne, 05/07
//removed from druids for balance after discussion with Ts and players ~Circe~ 8/5/13

#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int time;


void create()
{
    ::create();
    set_spell_name("monsoon");
    set_spell_level(([ "mage" : 8, "monk" : 17]));
    set_spell_sphere("conjuration_summoning");
    set_monk_way("way of the elements");
    set_syntax("cast CLASS monsoon");
    set_description("When the monsoon spell is cast, the surrounding area is engulfed in a raging storm of water. Any target in the area of effect takes damage every round while the spell is in effect, but does not damage the caster. This spell does not work in conjunction with the fire storm spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("reflex");
	set_aoe_message("%^RESET%^%^CRST%^%^C021%^(%^C031%^f%^C032%^l%^C033%^o%^C027%^o%^C026%^d%^C025%^e%^C031%^d %^C032%^b%^C033%^y %^C027%^p%^C026%^o%^C025%^u%^C031%^r%^C032%^i%^C033%^n%^C027%^g %^C026%^r%^C025%^a%^C031%^i%^C032%^n%^C021%^)%^CRST%^");
    aoe_spell(1);
}



void spell_effect(int prof)
{
    tell_object(caster, "%^CRST%^%^RESET%^%^C032%^You wave your hands around, unleashing the %^C025%^fury%^RESET%^%^C032%^ of a %^C020%^w%^C026%^a%^C032%^t%^C026%^e%^C020%^r%^C026%^y %^C020%^s%^C026%^t%^C032%^o%^C026%^r%^C020%^m%^RESET%^%^C032%^ from the %^C020%^s%^C026%^k%^C032%^i%^C026%^e%^C020%^s%^RESET%^%^C032%^ above!%^CRST%^");
    tell_room(place, "%^CRST%^%^RESET%^%^C032%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^ %^C032%^waves "+caster->query_possessive()+" %^C032%^hands around, unleashing the %^C025%^fury%^RESET%^%^C032%^ of a %^C020%^w%^C026%^a%^C032%^t%^C026%^e%^C020%^r%^C026%^y %^C020%^s%^C026%^t%^C032%^o%^C026%^r%^C020%^m%^RESET%^%^C032%^ from the %^C020%^s%^C026%^k%^C032%^i%^C026%^e%^C020%^s%^RESET%^%^C032%^ above!%^CRST%^", caster);
    place->set_property("spelled", ({this_object()}) );
    time = 0;
    addSpellToCaster();
    spell_successful();
    call_out("do_storm",5);
}


void do_storm()
{
    object *foes;
    string target_limb;
    int i,damage;

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

    foes = target_selector();

    if(time > clevel * 2 || !present(caster,place))
    {
        dest_effect();
        return;
    }

    if(spell_type == "monk" && sizeof(foes)) { MAGIC_D->elemental_opportunist(caster, foes[0]); }

    define_base_damage(0); // lazy re-roll
    damage = sdamage;

    tell_room(place, "%^CRST%^%^RESET%^%^C057%^A raging storm of %^C031%^w%^C032%^i%^C033%^n%^C027%^d%^RESET%^%^C057%^ and %^C031%^w%^C032%^a%^C033%^t%^C027%^e%^C026%^r%^RESET%^%^C057%^ roars through the area, damaging everything in sight!%^CRST%^");
    foes -= ({caster});
    for (i=0;sizeof(foes),i<sizeof(foes);i++)
    {
        if(!objectp(foes[i])) continue;
        if(foes[i] == caster) continue;
        if(!present(foes[i],place)) continue;
        if (interactive(foes[i]) && foes[i]->query_level() < 6) continue;

        if(do_save(foes[i],0)) { damage = damage/2; }
        target_limb = foes[i]->return_target_limb();
        damage_targ(foes[i], target_limb, damage,"cold");
        if(present(caster, place))
        {
            if (objectp(foes[i])) spell_kill(foes[i],caster);
        }
    }

    time++;

    if(present(caster,place) && !caster->query_unconscious())
    {
        call_out("do_storm",10);
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
        tell_room(place, "%^CRST%^%^RESET%^%^C057%^The monsoon weakens and dissipates.%^CRST%^");
        place->remove_property_value("spelled", ({this_object()}) );
    }
    if(objectp(caster))
    {
        caster->remove_property_value("spelled", ({this_object()}) );
    }
    remove_call_out("do_storm");
    ::dest_effect();
    if(objectp(this_object())) this_object()->remove();
}