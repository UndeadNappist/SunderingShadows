/*
  indorak.c
  
  Scythe weapon dropped by the Nightwalker Boss.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>

//Hit interval instead of proc chance. Procs every 3 hits.
#define HIT_INTERVAL 3

inherit "/d/common/obj/weapon/scythe.c";

string owner;
int hit_count, hb_count;

string color(string str)
{
    return CRAYON_D->color_string(str, "ice blue");
}

void create()
{
    ::create();
    
    set_name("scythe");
    set_id( ({ "indorak", "scythe", "chill of the grave", "indorak, the chill of the grave" }) );
    set_short("%^BOLD%^%^BLACK%^I%^RESET%^%^GREEN%^n%^BOLD%^d%^BLACK%^o%^RESET%^%^CYAN%^r%^BOLD%^a%^BLACK%^k%^WHITE%^, %^BLACK%^the C%^RESET%^%^CYAN%^h%^BOLD%^i%^WHITE%^l%^BLACK%^l of the G%^RESET%^%^GREEN%^r%^BOLD%^a%^WHITE%^v%^BLACK%^e%^RESET%^");
    set_obvious_short(color("A chill-wrapped scythe"));
    set_long("This is a large scythe, with a curved haft made of deep ebony wood. The blade of the scythe is long and jagged, with a bluish metal blade encased in a rime of ice. The entire weapon gives off the chill of death and icicles are formed, seeming to drip and solidify from almost the entire length of the weapon. There is a cold mist that seems to be wrapped around the scythe and a palpable aura of cold can be felt, even from 10 feet away.");
    set_lore("Indorak was made in the aftermath of the ritual which summoned the Nightwalker to this world from the Plane of Shadows. It is said that after the crafting of the ritual summoning blade, there were additional unused souls left over. The supplicants of Nilith took these unfortunate souls and formed a blade with a strong connection of the grave, that would be worthy of Nilith's champion in this world. A scythe was made and filled with the unfortunate souls, and permanently bound to the Plane of Shadows. The weapon became known as Indorak, the Chill of the Grave, and its mere presence almost seems to suck the heat and life energy from those around it. It is said that only a being enconsed in the energies of the Shadow Plane can effectively wield this weapon.");
    set_value(100000);
    set_weight(10);
    set_property("no_curse", 1);
    set_property("no steal", 1);
    set_property("lore difficulty", 40);
    set_property("id difficulty", 40);
    set_property("able to cast", 1);
    set_property("enchantment", 7);
    set_flag_required("boss avatar");        
    set_item_bonus("attack bonus", 7);
    set_item_bonus("damage bonus", 7);
    set_item_bonus("negative energy resistance percent", -25);
    set_item_bonus("cold resistance percent", 25);
    
    set_wield( (: this_object(), "wield_func" :) );
    set_unwield( (: this_object(), "unwield_func" :) );
    set_hit( (: this_object(), "hit_func" :) );
    
    set_heart_beat(1);
}

void init()
{
    object holder;
    
    ::init();
    
    holder = environment(this_object());
    
    if(!holder || !userp(holder))
        return;
    
    hit_count = 0;
    hb_count = 0;
    
    if(!owner)
    {
        if((!holder->is_undead() &&
        !holder->query_property("negative energy affinity")) ||
        holder->query_character_level() < 40)
        {
            tell_object(holder, "The icy scythe rejects your grasp, slipping from your hand!");
            this_object()->move(environment(holder));
            return;
        }      
               
        owner = holder->query_true_name();
        tell_object(holder, "As you lift the icy scythe for the first time, you feel it's power seep into your very soul and you become one with the mighty weapon.");
    }
}

int wield_func()
{
    if(this_player()->query_true_name() != owner)
    {
        tell_object(this_player(), "The scythe rejects your touch!");
        return 0;
    }
    
    tell_object(this_player(), color("You feel the chill of the grave seep into your bones as you wield aloft the might scythe!"));
    tell_room(environment(this_player()), color(owner->query_cap_name() + "'s scythe suddenly glows with the chill of the grave!"), owner);
    return 1;
}

int unwield_func()
{
    this_player() && tell_object(this_player(), "%^CYAN%^You feel the chill of the grave leave you as you unwield the scythe.");
    return 1;
}

void heart_beat()
{
    object *enemies, holder;
    int damage_done;
    
    holder = environment(this_object());
    
    if(!holder || !living(holder))
        return;
    
    hb_count ++;
    
    if(hb_count < 3)
        return;
    
    hb_count = 0;
    
    enemies = holder->query_attackers();
    damage_done = 0;
    
    if(sizeof(enemies) && !random(5))
    {
        tell_object(holder, color("The chill aura of the scythe saps the heat from your enemies!"));
        
        foreach(object ob in enemies)
        {
            if(ob->is_undead() || ob->is_shade())
                continue;
            
            tell_object(ob, color("The chill aura of the scythe saps the heat from you!"));
            damage_done += ob->cause_typed_damage(ob, ob->return_target_limb(), roll_dice(6, 10) + 10, "cold");
        }
        
        if(damage_done)
        {
            tell_object(holder, "%^BOLD%^GREEN%^The stolen heat from the scythe restores some of your wounds.%^RESET%^");
            holder->cause_typed_damage(holder, "torso", damage_done, "negative energy");
        }
    }
}

int hit_func(object target)
{
    int damage;
    string pname, ename;
    object holder;
    
    holder = environment(this_object());

    if(!target || !holder)
        return 0;
    
    if(environment(target) != environment(holder))
        return 0;
    
    hit_count++;
            
    if(hit_count < HIT_INTERVAL)
    {
        target->cause_typed_damage(target, "torso", roll_dice(1, 10), "cold");
        return 0;
    }
    
    pname = holder->query_cap_name();
    ename = target->query_cap_name();
    
    hit_count = 0;   
    damage = roll_dice(10, 10) + 20;
    
    tell_object(holder, color("Your scythe shears deep into " + ename + " and blasts " + target->query_objective() + " with an icy chill!"));
    tell_object(target, color(pname + "'s scythe shears deep into you and blasts you with an icy chill!"));
    tell_room(environment(holder), color(pname + "'s scythe shears deep into " + ename + " and blasts " + target->query_objective() + " with an icy blase!"), ({ holder, target }));
    target->cause_typed_damage(target, target->query_target_limb(), damage, "cold");
    
    return 0;
}