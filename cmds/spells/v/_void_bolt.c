/*
  _void_bolt.c
  
  Innate spell for Clerics with the Void Domain.
  Ranged attack for hit.
  
  -- Tlaloc --
*/

#include <std.h>
#include <spell.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    
    set_spell_name("void bolt");
    set_spell_level( ([ "innate" : 5 ]) );
    set_domains("void");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast innate void bolt on TARGET");
    set_damage_desc("Void damage to target on successful ranged touch attack");
    set_description("Clerics with the void domain learn, by the grace of their deity, how to attack their opponents with bolts of pure void energy. This spell uses a ranged touch attack to do void damage. This spell requires one Divine Grace point to use.");
    set_target_required(1);
    set_immunities( ({ "void" }) );
}

string query_cast_string()
{
    return "%^CYAN%^BOLD%^" + caster->QCN+" shouts out words of a divine plea while pointing with "+caster->QP+" finger.%^RESET%^";
}

int preSpell()
{
    if(!caster->ok_to_kill(target))
    {
        dest_effect();
        return 0;
    }
    
    if(!(int)USER_D->spend_pool(this_player(), 1, "grace"))
    {
        tell_object(caster, "You don't have the Divine Grace to cast Void Bolt!");
        return 0;
    }

    return 1;
}

void spell_effect(int prof)
{
    int roll;
       
    if(!objectp(target))
    {
        tell_object(caster, "Your target is no longer here.");
        return;
    }
    
    spell_successful();
    
    roll = (int)BONUS_D->process_hit(caster, target, 1, 0, 0, 1);
    
    if(roll < 1)
    {
        tell_object(caster, "You fire a void bolt at " + target->QCN + " but miss!");
        return;
    }
    
    tell_object(caster, "%^BLACK%^BOLD%^A bolt of pure void energy shoots out of your finger and squarely strikes " + target->QCN + " with an insidious hiss!%^RESET%^");
    tell_room(place, "%^RED%^BOLD%^" + caster->QCN + " shoots a bolt of pure void energy out of " + caster->QP + " finger, striking " + target->QCN + " with an insidious hiss.%^RESET%^", ({ caster })); 
    
    target->cause_typed_damage(target, target->return_target_limb(), sdamage, "void");
    spell_kill(target, caster);
}
    
    

