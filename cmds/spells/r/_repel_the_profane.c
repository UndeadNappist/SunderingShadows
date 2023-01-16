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
    set_damage_desc("AOE cowering on evil aligned");
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
        return;
    }
    
    tell_room(place, "AOE message", caster);
    tell_object(caster, "caster message");
    
    foreach(object ob in attackers)
    {
        if(!do_save(ob))
        {
            "/std/effect/status/cowering"->apply_effect(ob, clevel / 14 + 1);
            tell_object(ob, "You're cowering message.");
            tell_room(place, "They're cowering message.");
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

