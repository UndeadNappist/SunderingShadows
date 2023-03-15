/*
  stick_snake.c
  
  Rebuilt to handle all snake types.
  
  -- Tlaloc --
*/

#include <std.h>

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
    set_hit_funcs( ([ "mouth" : (: this_object(), "bite_func" :) ]));
    set_func_chance(50);
}

int bite_func(object target)
{
    if(!objectp(target))
        return 0;
    
    if(!strlen(type))
        return 0;
    
    switch(type)
    {
    }
}

