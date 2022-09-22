#include <spell.h>
#include <magic.h>
inherit SPELL;

int power;

void create()
{
    ::create();
    set_spell_name("pull of the grave");
    set_spell_level(([ "warlock" : 4 ]));
    set_spell_sphere("necromancy");
    set_heritage("gloom");
    set_syntax("cast CLASS pull of the grave on TARGET");
    set_damage_desc("Death or negative energy and shaken");
    set_description("You condemn your target to the cold, unrelenting oblivion of the grave. Shards of necrotic steel swirl around them, forming a dark and forbidding coffing from whence few will ever return. On a failed combat death save, the target will obey the call and die instantly. On a successful save, the target is shaken by their close brush with death and take normalized negative energy damage as they wallow in their blackened steel tomb.");
    set_verbal_comp();
    set_save("fort");
    set_somatic_comp();
    set_target_required(1);
}

string query_cast_string()
{
    return "Cast string";
}

void spell_effect()
{   
    int dur;
    
    spell_successful();
    
    tell_object(caster, "Spell cast string to caster");
    tell_object(target, "Spell cast string to target");
    tell_room(place, "Spell cast string to room");
    
    if(combat_death_save(target, 0))
    {
        tell_object(caster, "Successful save to caster");
        tell_object(target, "Successful save to target");
        tell_room(place, "Successful save to room");
        damage_targ(target, target->return_target_limb(), sdamage, "negative energy");
        
        if(!target || !objectp(target))
            return;
        
        dur = 6 * (clevel / 10 + roll_dice(1, 4));        
        //target->set_paralyzed(dur, "You are weighed down by the pull of the grave");
        "/std/effect/status/shaken"->apply_effect(target, dur, caster);
    }
    else
    {
        tell_object(caster, "Failed save to caster. DIE");
        tell_object(target, "Failed save to target. DIE");
        tell_room(place, "Failes to save to room. DIE");
        target->set_hp(-100);
    }
    
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}
