/*
  tribal_scout.c
  
  Medium armor meant for druid. Does extra force damage to attacks made while stealth or invisible.
  
  -- Tlaloc --
*/

#include <std.h>

inherit ARMOUR;

string owner;

void create()
{
    ::create();
    set_name("tribal scout");
    set_short("");
    set_obvious_short("");
    set_long("");
    set_lore("");
    set_property("lore difficulty", 40);
    set_property("id difficulty", 40);   
    set_flag_required("boss avatar");
    set_max_dex_bonus(5);
    set_ac(7);
    set_weight(30);
    set_value(10000);
    set_armor_prof("medium");
    set_type("leather");
    set_property("repairtype", ({ "leatherworker" }));
    set_wear((:this_object(),"wear_fun":));
    set_remove( (: this_object(),"remove_fun" :) );
}

int is_metal() { return 0; }