/*
  dark_omen.c
  
  Dark Omen.
  
  Spontaneous caster specific item.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>

inherit RING;

int mana;

void create()
{
    ::create();
    
    set_name("dark omen");
    set_id( ({ "ring", "omen", "dark omen", "dark ring" }) );
    set_short("");
    set_obvious_short("");
    set_long("");
    set_lore("");
    set_property("lore difficulty", 40);
    set_property("id difficulty", 40);
    set_value(10000);
    set_flag_required("boss avatar");
    set_property("enchantment", 7);
    set_heart_beat(1);
    set_wear((:TO,"wear_fun":));
}