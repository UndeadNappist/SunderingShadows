/*
  stick_snake.c
  
  Rebuilt to handle all snake types.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>

inherit MINION;

string type;

string set_type(string str) { return type = str; }

void create()
{
    ::create();
    set_name("snake");
    set_id( ({ "snake" }) );
    set_short("snake");
    set_long("This is a small common place snake. One of the many kinds you find in a garden or under a rock. Usually known to run whenever possible, it will, however, often give a nasty bite.");
	set_body_type("snake");
	set_hd(1,1);
	set_hp(1);
	set_exp(1);
	set_attack_limbs(({"mouth"}));
	set_damage(2,4);
	set_attacks_num(1);
	set_race("snake");
    set_property("no corpse", 1);
    set_hit_funcs( ([ "mouth" : (: this_object(), "bite_func" :) ]));
    set_func_chance(50);
}

int bite_func(object target)
{
    object room;
    
    if(!objectp(target))
        return 0;
    
    if(!strlen(type))
        return 0;
    
    if(target->query_poisoning())
        return 0;
    
    if(!objectp(room = environment(this_object())))
        return 0;
    
    if(!SAVING_THROW_D->fort_save(target, this_object()->query_level() + 10))
    {
	    tell_player(target,"%^BOLD%^%^RED%^You feel the horrid poison filter into your blood!"); 
	    target->add_poisoning(5);
        return 10;
    }
    if(!SAVING_THROW_D->reflex_save(target, this_object()->query_level() + 10))
    {
        tell_room(room, "The " + type + " wraps around " + target->query_cap_name() + "'s legs and trips " + target->query_objective() + " to the ground!", target);
        tell_object(target, "The " + type + " wraps around your legs and trips you to the ground!");
        target && target->set_tripped(6);
        return 0;
    }
       
}

