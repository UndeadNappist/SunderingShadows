/*
  _cleansing_flames.c
  
  AOE spell that also does a little damage to party and cleanses them.
  
  -- Tlaloc --
*/

#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("cleansing flames");
    set_spell_level(([ "innate" : 5 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS cleansing flames");
    set_damage_desc("radiant damage on friends and foes. cleanses friends");
    set_description("You unleash the cleansing flames of the sun on the area, causing radiant damage to enemies. Enemies that make a fortitude save take half damage. Party members and followers take radiant damage equal to caster level, but are cleansed as if hit with a restoration spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("fort");
    splash_spell(3);
}

string query_cast_string()
{
    tell_object(caster, "%^C032%^You gather the %^C214%^cleansing flames%^C032%^ of the %^C214%^sun%^C032%^ within you.%^CRST%^");
    return "%^C032%^" + caster->query_cap_name() + " gathers %^C214%^cleansing flames%^C032%^ of the %^C214%^sun%^C032%^ within " + caster->query_objective() + ".%^CRST%^";
}

void spell_effect(int prof)
{
    object *foes, *friends, cleanser;
    
    friends = ob_party(caster) + caster->query_followers() - caster->query_attackers() + ({ caster });
    foes = target_selector();
    
    if(!sizeof(foes) && !sizeof(friends))
    {
        tell_object(caster, "There are no targets here.");
        dest_effect();
        return;
    }
    
    spell_successful();
    
    tell_object(caster, "%^C214%^You unleash your %^C226%^radiant flames%^C214%^ on the area, cleansing friends and burning foes!%^CRST%^");
    tell_room(place, "%^C214%^Radiant %^C226%^flames%^C214%^ pour through the area, burning everyone in %^C191%^r%^C193%^a%^C194%^d%^C195%^i%^C191%^ant e%^C192%^n%^C193%^e%^C194%^r%^C191%^gy%^C214%^!%^CRST%^", ({ caster }));
    
    if(!catch(cleanser = load_object("/std/magic/cleanse")))
    {   
        foreach(object pal in friends)
        {
            if(!objectp(pal) || environment(pal) != place)
                continue;
            
            tell_object(pal, "%^C193%^The cleansing flames burn you deeply, causing intense pain but burning ailments from your body.%^CRST%^");
            pal->cause_typed_damage(pal, "chest", clevel, "radiant");
            cleanser->cleanse(pal);
        }
    }
    
    foreach(object foe in foes)
    {
        tell_object(foe, "%^C214%^You are struck with %^C226%^radiant energy%^C214%^, burning you to your very soul!%^CRST%^");
        
        if(do_save(foe))
            foe->cause_typed_damage(foe, "chest", sdamage / 2, "radiant");
        else
            foe->cause_typed_damage(foe, "chest", sdamage, "radiant");
    }
    
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(this_object())) this_object()->remove();
}   