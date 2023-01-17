#include <std.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("repel the profane");
    set_spell_level( ([ "innate" : 4 ]) );
    set_spell_sphere("invocation_evocation");
    set_syntax("cast innate repel the profane");
    set_damage_desc("AOE cowering on evil aligned attackers");
    set_description("You unleash a blast of holy energy, laying all evil beings in the vicinity low. Each evil attacker must make a will save or be left cowering for a short time.");
    set_save("will");
    splash_spell(3);
}

void spell_effect(int prof)
{
    object *attackers;
    
    attackers = target_selector();
    
    attackers = filter_array(attackers, (: is_evil($1) :));
    
    if(!sizeof(attackers))
    {
        tell_object(caster, "There is no one here to repel.");
        dest_effect();
        return;
    }
    
    tell_room(place, "%^C045%^" + caster->query_cap_name() + "%^C032%^ casts forth " + caster->query_possessive() + " %^C214%^h%^C220%^o%^C226%^l%^C214%^y e%^C220%^n%^C226%^e%^C214%^rgy%^C032%^, seeking to repel the %^C045%^evil%^C032%^ here!%^CRST%^", caster);
    tell_object(caster, "%^C032%^You cast forth your %^C214%^h%^C220%^o%^C226%^l%^C214%^y e%^C220%^n%^C226%^e%^C214%^rgy%^C032%^, seeking to repel the %^C045%^evil%^C032%^ and %^C045%^corruptive%^C032%^ beings here!%^CRST%^");
    
    foreach(object ob in attackers)
    {
        if(!do_save(ob) && !PLAYER_D->immunity_check(ob, "fear"))
        {
            "/std/effect/status/cowering"->apply_effect(ob, clevel / 14 + 1);
            tell_object(ob, "%^C045%^The holy energy leaves you cowering in fright!%^CRST%^");
            tell_room(place, "%^C045%^" + ob->query_cap_name() + " is left cowering from the holy energies!%^CRST%^");
        }
    }
    spell_successful();
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}

