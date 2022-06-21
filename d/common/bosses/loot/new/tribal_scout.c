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
    set_limbs( ({ "torso" }) );
    set_wear((:this_object(),"wear_fun":));
    set_remove( (: this_object(),"remove_fun" :) );
}

int is_metal() { return 0; }

int wear_fun()
{   
    if(!this_player()->is_class("druid"))
    {
        tell_object(this_player(), "!");
        return 0;
    }
    
    if(!strlen(owner))
    {
        owner = this_player()->query_name();
        tell_object(this_player(), "");
    }
    else
    {
        if(owner != this_player()->query_name())
        {
            tell_object(this_player(), "This is not your armor!");
            return 0;
        }
    }
    
    this_player()->set_property("additional_stealth_damage", ({ "force" }));
    tell_object(this_player(), "");
    
    return 1;
}

int remove_fun()
{
    tell_object(this_player(), "");
    this_player()->remove_property_value("additional_stealth_damage", ({ "force" }));
    return 1;
}