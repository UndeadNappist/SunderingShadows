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
    //set_spell_level( ([ "cleric" : 5, "druid" : 5 ]) );
    set_spell_level( ([ "classless" : 5 ]) );
    set_spell_sphere("alteration");
    set_domains( ({ "animal" }) );
    set_circle("grove");
    set_syntax("cast CLASS sticks into snakes");
    set_damage_desc("creates a bunch of snakes");
    set_description("With this spell, you turn various sticks in the area into writhing, biting snakes that will attack your foe. These snakes have a chance of poisoning or tripping your enemy as they attack. These snakes will only last for a relatively short time, scaling with caster level. The snakes are lesser summons and will only take one hit before dying. The number of snakes scales with caster level as well. Some areas have no sticks and will render this spell ineffective.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
    summon_spell();
}

int preSpell()
{
    if(place->query_property("no sticks"))
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
        snake->setup_minion(clevel, spell_level, "lesser");
        type = TYPES[random(sizeof(TYPES))];
        snake->add_id( ({ type }) );
        snake->set_short("%^GREEN%^" + type + "%^RESET%^");
    }
    
    spell_duration = (ROUND_LENGTH * 5) + (ROUND_LENGTH * clevel / 10);
    set_end_time();
    
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
    
    objectp(caster) && tell_object(caster, "Your snakes twist and writh and turn back into sticks.");
    
    ::dest_effect();
    if(objectp(this_object())) destruct(this_object());
}