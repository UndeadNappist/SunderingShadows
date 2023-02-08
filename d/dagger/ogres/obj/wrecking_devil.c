/*
  wrecking_devil.c
  
  Magical gnome hooked hammer.
  
  -- Tlaloc --
*/

#include <std.h>

inherit "/d/common/obj/weapon/gnome_hooked_hammer.c";

#define MIN_LEVEL     20
#define HIT_INTERVAL   5

int sundered, hit_count;
object holder;

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
    int damage, room;
    
    holder = environment(this_object());
    
    if(!objectp(holder) || !objectp(target))
        return 0;
    
    room = environment(holder);
    
    if(!objectp(room) || room != environment(target))
        return 0;
    
    
    

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
    