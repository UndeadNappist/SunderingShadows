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
    set_long("The Cloak of Displacement is a finely crafted garment, made from an otherworldly material that seems to be both soft and ethereal at the same time. When held, the cloak feels weightless and cool to the touch, almost as if it were made from a cloud or a wisp of mist. The fabric is a pale, almost translucent gray color, and it shimmers and glimmers in the light, as if reflecting a thousand tiny stars. The cloak is hooded, with the hood tapering to a point and lined with a dark, velvety material. When the hood is raised, it almost completely obscures the wearer's face, making it difficult to identify them. The cloak itself extends down to just below knee-level, and it is fastened at the neck with a delicate silver clasp that bears the symbol of an arcane rune.");
    set_lore("The cloak is said to have been crafted by ancient wizards using long-forgotten magical techniques, and its true nature and origins remain a mystery to this day. Some say that the cloak is cursed, and that it carries a terrible price for those who dare to use its power. Nonetheless, many adventurers seek out the Cloak of Displacement in the hope that it will aid them in their quests for treasure and glory.");
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
            tell_object(holder, "You feel an otherworldly power suffusing your body as you attune to the Cloak of Displacement, granting you mastery over stealth and deception.");
        }
        else
        {
            tell_object(holder, "You sense that the cloak is not meant for you, and that its power could overwhelm and consume you if you are not careful.");
            return 0;
        }
    }
    
    buffs = holder->query_property("spell_bonus_type");
    
    if(!pointerp(buffs)) buffs = ({  });
    
    if(member_array("concealment", buffs) < 0)
    {
        //tell_object(holder, "YOU GAIN CONCEALMENT MESSAGE");
        holder->add_property_value("spell_bonus_type", ({ "concealment" }));
        holder->set_missChance(holder->query_missChance() + 35);
        i_buffed_you = 1;
    }
      
    tell_object(holder, "As you slip on the Cloak of Displacement, you feel its insubstantial fabric envelop you, granting you the ability to blur your form and move through the world like a phantom.");
    
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
        //tell_object(holder, "YOU REMOVE BUFF");
    }   
    
    tell_object(this_player(), "As you remove the Cloak of Displacement, you feel the weight of the world settle back upon you, and the world snaps back into focus around you.");
    return 1;
}


    
    

