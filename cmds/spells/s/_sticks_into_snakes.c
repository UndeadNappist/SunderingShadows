/*
  _sticks_into_snakes.c
  
  Functional rewrite.
  
  -- Tlaloc --
*/

#include <std.h>
#include <spell.h>
#include <magic.h>

inherit SPELL;

object *snakes;

void create()
{
    ::create();
    set_spell_name("sticks into snakes");
    set_spell_level( ([ "cleric" : 5, "druid" : 5 ]) );
    set_spell_sphere("alteration");
    set_syntax("cast CLASS sticks into snakes");
    set_damage_desc("");
    set_description("");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
    summon_spell();
}

int preSpell()
{
    if(place->query_property("no stick"))
    {
        tell_object(caster, "There are no sticks here.");
        return 0;
    }
}

void spell_effect()
{
    int num;
    
    if(!objectp(place = environment(caster)))
        return;
    
    num = 4 + clevel / 3;
    
}
