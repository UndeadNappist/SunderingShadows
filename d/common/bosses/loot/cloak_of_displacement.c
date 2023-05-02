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
    set_id( ({ "cape", "displacement cloak", "cloak of displacement", "wispy cloak", "cloak" }) );
    set_short("%^C141%^C%^C147%^l%^C153%^o%^C147%^a%^C141%^k of D%^C147%^i%^C153%^s%^C159%^p%^C153%^l%^C147%^a%^C141%^cement%^CRST%^");
    set_obvious_short("%^C141%^a cloak made from %^C153%^wispy material%^CRST%^");
    set_long("%^C141%^This cloak is a finely crafted garment, made from an %^C153%^otherworldly material%^C141%^ that seems to be both soft and ethereal at the same time. When held, the cloak feels weightless and cool to the touch, almost as if it were made from a %^C153%^cloud%^C141%^ or a %^C153%^wisp of mist%^C141%^. The fabric is a pale, almost translucent gray color, and it %^C159%^shimmers%^C141%^ and %^C159%^glimmers%^C141%^ in the light, as if reflecting a thousand %^C159%^tiny stars%^C141%^. The cloak is hooded, with the hood tapering to a point and lined with a %^C129%^dark%^C141%^, %^C129%^velvety%^C141%^ material. When the hood is raised, it almost completely obscures the wearer's face, making it difficult to identify them. The cloak itself extends down to just below knee-level, and it is fastened at the neck with a delicate silver clasp that bears the symbol of an %^C153%^arcane rune%^C141%^.%^CRST%^");
    set_lore("%^C159%^The Cloak of Displacement is said to have been created by a powerful wizard who was obsessed with the idea of never being where his enemies expected him to be. Using his mastery of arcane arts, he imbued the cloak with a powerful enchantment that would cause it to shimmer and blur, making it nearly impossible for an attacker to land a blow. The wizard himself disappeared soon after creating the cloak, but rumors persisted that he had been hunted down and slain by enemies who were determined to discover the secrets of his cloaking magic. Over time, the Cloak of Displacement passed from hand to hand, becoming a treasured possession of rogues and adventurers who sought to use its powers to stay one step ahead of their foes. As the years passed, the true origins of the cloak were lost to legend, but its powers remained undiminished. To this day, those who possess the Cloak of Displacement are able to move with a speed and agility that seems almost supernatural, allowing them to evade even the most skilled opponents. But the price of this power is a heavy one, for those who wear the cloak too often may find themselves becoming increasingly isolated and detached from the world around them, as though they are forever displaced from reality itself.%^CRST%^");
    set_property("lore difficulty", 40);
    set_property("id difficulty", 40);
    set_ac(0);
    set_value(10000);
    set_weight(1);
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
            tell_object(holder, "%^C159%^You feel an otherworldly power suffusing your body as you attune to the cloak, granting you mastery over stealth and deception.%^CRST%^");
        }
        else{
            if(owner != holder->query_true_name()){
                tell_object(holder, "%^C135%^You sense that the cloak is not meant for you, and that its power could overwhelm and consume you if you are not careful.%^CRST%^");
                return 0;
            }
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
      
    tell_object(holder, "%^C141%^As you slip on the %^C153%^Cloak of Displacement%^C141%^, you feel its insubstantial fabric envelop you, granting you the ability to %^C153%^blur%^C141%^ your form and move through the world like a phantom.%^CRST%^");
    
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
    
    tell_object(this_player(), "%^C147%^As you remove the Cloak of Displacement, you feel the weight of the world settle back upon you, and the world snaps back into focus around you.%^CRST%^");
    return 1;
}


    
    

