/*
  dryad_hammer.c
  
  Hammer weapon dropped by the Nightwalker Boss.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>

//Hit interval instead of proc chance. Procs every 5 hits.
#define HIT_INTERVAL 5

inherit "/d/common/obj/weapon/dagger.c";

object owner;
int hit_count;

string color(string str)
{
    return CRAYON_D->color_string(str, "lightning yellow");
}

void create()
{
    ::create();
    
    set_name("hammer");
    set_id( ({ "hammer" }) );
    set_short("Novelty, the unbound surge");
    set_obvious_short(color(""));
    set_long("This hammer has been constructed wholly from pure gold, with the handle and staff of the hammer appearing to be made from a single, large piece of gold. The head of the hammer blunts out and protrudes on one side while the other spikes out in a sharp and long leaf-bladed shape. Where both sides meet, small little flames glow in a dimly crimson color among smaller engravings of roots that grow along of the center of the bladed side while towards the hammer, small floral shapes bloom out. The pole of the hammer shows leather wrappings for a sturdier hold and little engravings of roots glide along of it until growing out into a red, phoenix like feather at the bottom of the pole.");
    set_lore("");
    set_value(100000);
    set_property("no_curse", 1);
    set_property("no steal", 1);
    set_property("lore difficulty", 40);
    set_property("id difficulty", 40);
    set_property("able to cast", 1);
    set_property("enchantment", 7);
    
    set_item_bonus("positive energy resistance percent", -25);
    set_item_bonus("fast healing", 3);
    
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
        if((holder->query_true_align() != 1 &&
           holder->query_true_align() != 4 &&
           holder->query_true_align() != 7) ||
           holder->query_character_level() < 40)
        {
            tell_object(holder, "The wooden handle rejects your hand and you drop it!");
            this_object()->move(environment(holder));
            return;
        }      
               
        owner = holder;
        tell_object(holder, color("As you lift the hammer, you feel it entwine itself with your life force."));
    }
}

int hit_func(object target)
{

}

int unwield_func()
{
    owner && tell_object(owner, "%^CYAN%^You feel the warmth of the hammer disappate as you release it.");
    return 1;
} 