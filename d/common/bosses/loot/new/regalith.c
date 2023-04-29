/*
  regalith.c
  
  Krey-inspired dragon spear.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>

#define HIT_INTERVAL 2

inherit "/d/common/obj/weapon/spear_lg.c";

string owner;
int hit_count;

void create()
{
    ::create();
    
    set_name("spear");
    set_id( ({ "spear", "large spear", "dragon spear", "regalith spear", }) );
    set_short("");
    set_obvious_short("");
    set_long("");
    set_lore("");
    set_value(100000);
    set_weight(6);
    set_property("no_curse", 1);
    set_property("no steal", 1);
    set_property("lore difficulty", 40);
    set_property("id difficulty", 40);
    set_property("able to cast", 1);
    set_property("enchantment", 7);
    
    set_item_bonus("attack bonus", 7);
    set_item_bonus("damage bonus", 7);
    
    set_wield( (: this_object(), "wield_func" :) );
    set_unwield( (: this_object(), "unwield_func" :) );
    set_hit( (: this_object(), "hit_func" :) );
}

void init()
{
    object holder;
    
    ::init();
    
    holder = environment(this_object());
    
    if(!holder || !userp(holder))
        return;
    
    hit_count = 0;
    
    if(!owner)
    {          
        owner = holder->query_true_name();
        tell_object(holder, "ATTUNE MESSAGE");
    }
}

int hit_func(object target)
{
    int dam;
    string ename, pname;
    object holder;
    
    holder = environment(this_object());
    
    if(!objectp(holder) || !objectp(target))
        return 0;
    
    hit_count++;
    
    if(hit_count < HIT_INTERVAL)
    {
        target->cause_typed_damage(target, "torso", roll_dice(1, 10), "fire");
        return 0;
    }
    
    hit_count = 0;
    
    pname = holder->query_cap_name();
    ename = target->query_cap_name();
    
    tell_room(environment(holder), "HIT MESSAGE");
    target->cause_typed_damage(target, "torso", roll_dice(6, 10) + 10, "fire");

    //REND SPECIAL
    
    return 0;
}

int wield_func()
{
    object holder;
    
    holder = environment(this_object());
    
    if(holder->query_true_align() == 9 || holder->query_true_align() == 8 || holder->query_true_align() == 6 || holder->query_true_name() != owner)
    {
        tell_object(holder, "WIELD DENIED");
        holder->cause_typed_damage(holder, "torso", roll_dice(6, 10) + 10, "fire");
        return 0;
    }
    
    tell_object(holder, "WIELD MESSAGE");
    return 1;
}

int unwield_func()
{
    object holder;
    
    holder = environment(this_object());
    holder && tell_object(holder, "UNWIELD MESSAGE");
    return 1;
} 