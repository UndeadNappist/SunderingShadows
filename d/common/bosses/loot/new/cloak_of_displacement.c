/*
  cloak_of_displacement.c
  
  An attempt at making an actual cloak of displacement.
  
  -- Tlaloc --
*/


#include <std.h>

inherit "/d/common/obj/clothing/cloak.c";

string owner;
int i_buffed_you;

void create()
{
    ::create();
    set_name("cape");
    set_id( ({ "cape", "displacement cloak", "cloak of displacement", "dark cloak", "cloak" }) );
    set_short("cloak of displacement");
    set_obvious_short("cloak of displacement");
    set_long("");
    set_lore("");
    set_property("lore difficulty", 40);
    set_property("id difficulty", 40);
    set_ac(0);
    set_value(10000);
    set_weight(2);
    set_limbs( ({ "neck" }) );
    set_type("clothing");
    set_wear((:TO,"wear_fun":));
    set_remove( (: this_object(),"remove_fun" :) );
}

int wear_fun()
{
    object holder;
    string *buffs;
    
    holder = this_player();
    
    if(!archp(holder) && !avatarp(holder))
    {
        if(!strlen(owner))
        {
            owner = holder->query_true_name();
            tell_object(holder, "ATTUNE MESSAGE");
        }
        else
        {
            tell_object(holder, "YOURE NOT OWNER MESSAGE");
            return 0;
        }
    }
    
    buffs = holder->query_property("spell_bonus_type");
    
    if(!pointerp(buffs)) buffs = ({  });
    
    if(member_array("concealment", buffs) < 0)
    {
        tell_object(holder, "YOU GAIN CONCEALMENT MESSAGE");
        holder->add_property_value("spell_bonus_type", ({ "concealment" }));
        holder->set_missChance(holder->query_missChance() + 35);
        i_buffed_you = 1;
    }
      
    tell_object(holder, "WIELD SUCCESS MESSAGE");
    
    return 1;
}

int remove_fun()
{
    string *buffs;
    object holder;
    
    holder = this_player();
    buffs = holder->query_property("spell_bonus_type");
    if(!pointerp(buffs)) buffs = ({  });
    
    if(i_buffed_you && member_array("concealment", buffs) >= 0)
    {
        i_buffed_you = 0;
        holder->remove_property_value("spell_bonus_type", ({ "concealment" }));
        holder->set_missChance(holder->query_missChance() - 35);
        tell_object(holder, "YOU REMOVE BUFF");
    }   
    
    tell_object(this_player(), "REMOVE MESSAGE");
    return 1;
}


    
    

