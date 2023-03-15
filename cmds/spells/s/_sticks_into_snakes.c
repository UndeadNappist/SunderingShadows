/*
  _sticks_into_snakes.c
  
  Functional rewrite.
  
  -- Tlaloc --
*/

#include <std.h>
#include <spell.h>
#include <magic.h>

#define TYPES ({ "adder", "asp", "boa", "cobra", "copperhead", "cottonmouth", "python", "rattlesnake" })

inherit SPELL;

object *snakes = ({  });

void create()
{
    ::create();
    set_spell_name("sticks into snakes");
    set_spell_level( ([ "cleric" : 5, "druid" : 5 ]) );
    set_spell_sphere("alteration");
    set_syntax("cast CLASS sticks into snakes");
    set_damage_desc("creates a bunch of snakes");
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
    object snake;
    string type;
    
    if(!objectp(place = environment(caster)))
        return;
    
    if(catch(load_object("/d/magic/mon/stick_snake")))
        return;
    
    spell_successful();
    tell_object(caster, "CASTER MESSAGE");
    tell_room(place, "ROOM MESSAGE", caster);
    
    num = 3 + clevel / 5;
    
    for(int x = 0; x < num; x++)
    {
        snake = new("/d/magic/mon/stick_snake");
        if(!objectp(snake)) continue;
        snakes += ({ snake });
        snake->set_owner(caster);
        snake->setup_minion(clevel, 5, "lesser");
        type = TYPES[random(sizeof(TYPES))];
        snake->add_id( ({ type }) );
        snake->set_short("%^GREEN%^" + type + "%^RESET%^");
    }
    
    call_out("check", ROUND_LENGTH);
}

void check()
{
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    
    snakes = filter_array(snakes, (: objectp($1) :));
    
    if(!sizeof(snakes))
    {
        dest_effect();
        return;
    }
    
    call_out("check", ROUND_LENGTH);
}

void dest_effect()
{
    remove_call_out("check");
    
    foreach(object ob in snakes)
        objectp(ob) && ob->remove();
    
    objectp(caster) && tell_object(caster, "DISMISS SNAKES MESSAGE");
    
    ::dest_effect();
    if(objectp(this_object())) destruct(this_object());
}