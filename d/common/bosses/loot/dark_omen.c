/*
  dark_omen.c
  
  Dark Omen.
  
  Spontaneous caster specific item. Should allow a spontaneous caster to use spell slots to cast specific spells on the ring.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>

inherit RING;

sting owner;

void create()
{
    ::create();
    
    set_name("dark omen");
    set_id( ({ "ring", "omen", "dark omen", "dark ring" }) );
    set_short("");
    set_obvious_short("");
    set_long("");
    set_lore("A truly dark and forbidding ring filled with forbidding power. The origin of this ring is unknown, but its dark nature seems to suggest it was wrought in the Plane of Shadows. The ring itself lends its power to spontaneous casters of the weave, allowing them to cast fear, ray of exhaustion, waves of fatigue, ray of enfeeblement, and cause fear as if they were mastered. Using this ring will consume the appropriate prepared spell slot.");
    set_property("lore difficulty", 40);
    set_property("id difficulty", 40);
    set_value(10000);
    set_flag_required("boss avatar");
    set_property("enchantment", 7);
    set_heart_beat(1);
    set_wear((:this_object(),"wear_fun":));
    set_remove( (: this_object(),"remove_fun" :) );
}

int wear_fun()
{
    int align;
    
    align = this_player()->query_true_align();
    
    if(align == 1 || align == 4 || align == 7)
    {
        tell_object(this_player(), "Your conscience pulls your hand away from the evil ring with revulsion!");
        return 0;
    }
    
    if(!strlen(owner))
    {
        owner = this_player()->query_name();
        tell_object(this_player(), "The dark ring binds itself with your soul!");
    }
    
    this_player()->set_property("bonus_mastered", ({ "fear", "ray of exhaustion", "waves of fatigue", "ray of enfeeblement", "cause fear" }));
    tell_object(this_player(), "The ring slides onto your finger, lending you its dark power!");
    
    return 1;
}

int remove_fun()
{
    this_player()->remove_property_value("bonus_mastered", ({ "fear", "ray of exhaustion", "waves of fatigue", "ray of enfeeblement", "cause fear" }));
    tell_object(this_player(), "You remove the ring and feel its dark power leave you.");
    return 1;
}
    
    