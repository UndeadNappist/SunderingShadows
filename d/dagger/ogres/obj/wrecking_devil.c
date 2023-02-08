/*
  wrecking_devil.c
  
  Magical gnome hooked hammer.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>

inherit "/d/common/obj/weapon/gnome_hooked_hammer.c";

#define MIN_LEVEL     20
#define HIT_INTERVAL   4

int sundered, hit_count, amount
object holder;

void remove_sunder() { sundered = 0; } 

void create()
{
    ::create();
    set_name("hammer");
    set_id( ({ "hammer", "gnome hammer", "gnome hooked hammer", "wrecking devil", "wrecking hammer" }) );
    set_short("wrecking devil");
    set_obvious_short("wicked looking gnome hooked hammer");
    set_long("");
    set_lore("");
    set_value(2000);
    set_weight(6);
    
    set_property("enchantment", 4);
    
    set_hit( (: this_object(), "hit_func" :) );
    set_wield( (: this_object(), "wield_func" :) );
    set_unwield( (: this_object() ,"unwield_func":) );
}

int hit_func(object target)
{
    int damage, room, my_dex_bonus;
    
    holder = environment(this_object());
    
    if(!objectp(holder) || !objectp(target))
        return 0;
    
    room = environment(holder);
    
    if(!objectp(room) || room != environment(target))
        return 0;
    
    hit_count++;
    
    if(hit_count < HIT_INTERVAL)
        return 0;
    
    hit_count = 0;
    my_dex_bonus = BONUS_D->query_stat_bonus(holder, "dexterity");
    
    switch(random(3))
    {
        case 0: //Trip
        tell_object(holder, "PROC TRIP MESSAGE");
        tell_room(room, "PROC TRIP MESSAGE ROOM", holder);
        if(BONUS_D->combat_maneuver(target, holder, 0))
            target->set_tripped(roll_dice(1, 4));
        break;
        default: //Sunder or damage
        if(!sundered && BONUS_D->combat_maneuver(target, holder, 0))
        {
            target->add_ac_bonus(-10);
            tell_object(holder, "PROC SUNDER MESSAGE");
            tell_room(room, "PROC SUNDER MESSAGE ROOM", holder);
            sundered = 1;
            call_out("remove_sunder", 30);
        }
        else
        {
            tell_object(holder, "PROC DAMAGE MESSAGE");
            tell_room(room, "PROC DAMAGE ROOM", holder);
            target->cause_typed_damage(target, "torso", roll_dice(1, 6) + 5, "bludgeoning");
        }
        break;
    }
}   

int wield_func()
{
    holder = environment(this_object());
    
    if(!objectp(holder))
        return 0;
    
    if(holder->query_base_character_level() < MIN_LEVEL)
    {
        tell_object(holder, "You aren't experience enough to handle this weapon!");
        return 0;
    }
    
    tell_object(holder, "WIELD MESSAGE");
    
    return 1;
}

int unwield_func()
{
    holder = environment(this_object());
    
    if(!objectp(holder))
        return 0;
    
    tell_object(holder, "UNWIELD MESSAGE");
    
    return 1;
}
    