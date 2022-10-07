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
    set_short("The desert guardian");
    set_obvious_short("Thick hide armor dusted in sand");
    set_long("This hide armor is unusally breathable for it's thickness. Soft golden furs dusted with sand are bound together with fine stips of leather, barely concealing the hardier scales beneath. Long sleeves end in cuffs adorned with the thick claws of a desert wyvern. Sand falls from the armor twisting and writhing around it as if caught in the desert wind, apparent waves of heat blend with the sand and in the briefest moments create the mirage of eyes surveying the area.");
    set_lore("In ages past the desert was even more inhospitible. A massive sand elemental raged against any it all creatures it could find. Many tried to hide in the ground or flee to the sky but it was as if the elemental could see through the grains of sand as if they were it's own eyes. A nomadic druid plead to the creatures of the desert to assist her in binding the elemental and restore harmony to the broken sands. The creatures gathered, each offering up one of their own for her own for the cause. When the elemental struck each of the creatures sacrificed themselves as the spell was woven. The sands tore at her flesh as she wound the creatures together, binding the elemental in chains of blood and soul. When the sandstorm calmed none of the participants could be found, their names lost to the sands. A piece of each still remains and their legacy the desert guardian endures.");
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