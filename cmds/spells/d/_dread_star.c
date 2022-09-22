#include <std.h>
#include <spell.h>
#include <daemons.h>

inherit SPELL;

int amount;

void create()
{
    ::create();
    
    set_spell_name("dread star");
    set_spell_level( ([ "warlock" : 2 ]) );
    set_heritage("astral");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS dread star on TARGET");
    set_damage_desc("radiant on ranged touch attack. Failed save stunned temporarily");
    set_description("");
    set_target_required(1);
    set_save("will");
    set_immunities( ({ "radiant" }) );
}

string query_cast_string()
{
    return "Cast Message";
}

int preSpell()
{
    if(!caster->ok_to_kill(target))
    {
        dest_effect();
        return 0;
    }

    return 1;
}

void spell_effect(int prof)
{
    int roll;
    string my_name, your_name, my_poss;
       
    if(!objectp(target))
    {
        tell_object(caster, "Your target is no longer here.");
        return;
    }
    
    spell_successful();
    
    roll = (int)BONUS_D->process_hit(caster, target, 1, 0, 0, 1);
    
    my_name = caster->query_cap_name();
    my_poss = caster->query_possessive();
    your_name = target->query_cap_name();
    
    if(roll < 1)
    {
        tell_object(caster, "Miss message caster");
        tell_object(target, "Miss message target");
        tell_room(place, "Miss message room", ({ caster, target }));
        dest_effect();
        return;
    }
    
    tell_object(caster, "Hit message caster");
    tell_object(target, "Hot message target");
    tell_room(place, "Hit message room", ({ caster, target }));
    
    target->cause_typed_damage(target, target->return_target_limb(), sdamage, "radiant");
    spell_kill(target, caster);
    
    if(do_save(target, 0))
        return;
    
    tell_object(target, "Stunned message");
    tell_object(caster, "Stunned message");
    target->set_paralyzed(6);    
    
    dest_effect();
}

void dest_effect()
{
    
    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}
    

