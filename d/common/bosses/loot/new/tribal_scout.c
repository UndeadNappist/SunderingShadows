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
    set_short("IDENTIFIED SHORT");
    set_obvious_short("NOT IDENTIFIED SHORT");
    set_long("LONG DESC");
    set_lore("LORE DESC - ADD IN WHAT IT DOES");
    set_property("lore difficulty", 40);
    set_property("id difficulty", 40);   
    set_flag_required("boss avatar");
    set_max_dex_bonus(10);
    set_ac(7);
    set_weight(30);
    set_value(10000);
    set_armor_prof("medium");
    set_type("leather");
    set_property("repairtype", ({ "leatherworker" }));
    set_limbs( ({ "torso" }) );
    set_wear((:this_object(),"wear_fun":));
    set_remove( (: this_object(),"remove_fun" :) );
    set_struck( (: this_object(), "strike_fun" :) );
    
    set_property("lore difficulty", 40);
    set_property("id difficulty", 40);
    
    set_property("enchantment", 7);    
    set_item_bonus("damage resistance", 10);
    set_item_bonus("athletics", 7);    
    
}

int is_metal() { return 0; }

int wear_fun()
{   
    if(!this_player()->is_class("druid"))
    {
        tell_object(this_player(), "Only a druid may wear this armor!");
        return 0;
    }
    
    if(!strlen(owner))
    {
        owner = this_player()->query_name();
        tell_object(this_player(), "FIRST TIME WEARING MESSAGE");
    }
    else
    {
        if(owner != this_player()->query_name())
        {
            tell_object(this_player(), "This is not your armor!");
            return 0;
        }
    }
    
    this_player()->set_property("additional stealth damage", ({ "force" }));
    tell_object(this_player(), "MESSAGE WHEN PUTTING THIS ON");
    
    return 1;
}

int remove_fun()
{
    tell_object(this_player(), "MESSAGE WHEN TAKING THIS OFF");
    this_player()->remove_property_value("additional stealth damage", ({ "force" }));
    return 1;
}

int strike_fun(int x, object wep, object attacker)
{
    int damage;
    object wearer, room;
    
    if(!random(3))
    {
        wearer = environment(this_object());
        wearer && room = environment(wearer);
        
        tell_object(attacker, "ATTACKER STRUCK MESSAGE");
        tell_object(wearer, "WEARER STRUCK MESSAGE");
        tell_room(room, "ROOM STRUCK MESSAGE", ({ source, wearer }));
        
        damage = roll_dice(1 + wearer->query_base_character_level() / 5, 6);
        attacker->cause_typed_damage(attacker, attacker->return_target_limb(), damage, "piercing");
    }
    
    return x;
}       