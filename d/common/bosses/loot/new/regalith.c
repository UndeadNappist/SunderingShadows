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
    set_id( ({ "spear", "large spear", "dragon spear", "regalith spear", "golden dragon spear" }) );
    set_short("Regalith, Spear of the Golden Dragon Emperor");
    set_obvious_short("long barbed golden spear");
    set_long("This imposing spear features a sharp, pointed end that glints with a golden hue, reminiscent of the scales of a mighty dragon. Its shaft is crafted from a sturdy material, and is adorned with intricate carvings and designs that reflect the majesty and power of the creature that inspired it. The spear's barbed edges give it an even more fearsome appearance, as if daring any foe to try and withstand its might. When wielded with skill and strength, this weapon can strike with incredible force, piercing through even the toughest of armor and striking fear into the hearts of all who oppose its wielder.");
    set_lore("According to legend, the Regalith spear was crafted by a legendary blacksmith who sought to create a weapon that would match the power and majesty of the golden dragons that roamed the land. Drawing upon the finest materials and the most skilled techniques, the blacksmith crafted a spear that glimmered like the sun and gleamed like the scales of a dragon. Its barbed edges were said to be inspired by the teeth and claws of the mighty beasts, while its shaft was adorned with intricate designs that reflected their regal nature. As the years passed, the Regalith spear became a symbol of strength and power, passed down from warrior to warrior who sought to uphold the values of justice and righteousness. In the hands of a worthy champion, it was said that the spear could channel the power of the dragons themselves, striking with force and precision that could level even the mightiest of foes. To this day, the Regalith spear remains a coveted artifact, sought after by those who would seek to uphold the values of justice and defend the innocent against the forces of darkness. It is said that those who wield it with honor and integrity will find themselves imbued with the power of the golden dragons, their strength and might unmatched by any other weapon.");
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
        tell_object(holder, "You feel the power and wisdom of the Golden Dragon Emperor flow through you as you take hold of Regalith, ready to conquer any foe."");
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
    
    tell_room(environment(holder), "As Regalith strikes your opponent, the barbs tear through flesh and bone with ease, while the golden dragon's power surges forth to smite your foes.");
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
        tell_object(holder, "You grasp the handle of Regalith, but the weapon refuses to respond to your touch, as if it senses an unworthy hand seeking to wield it.");
        holder->cause_typed_damage(holder, "torso", roll_dice(6, 10) + 10, "fire");
        return 0;
    }
    
    tell_object(holder, "As you wield Regalith, you feel the power of the Golden Dragon Emperor coursing through you, making you a formidable force on the battlefield.");
    return 1;
}

int unwield_func()
{
    object holder;
    
    holder = environment(this_object());
    holder && tell_object(holder, "As you release Regalith, its power lingers on, ready to be called upon once more.");
    return 1;
} 