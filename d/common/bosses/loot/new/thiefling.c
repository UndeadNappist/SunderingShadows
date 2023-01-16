/*
  thiefling.c
  
  Thiefling.
  
  Gives bonus to thievery and stealth. Gives more bonus if you're a Tiefling.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>

inherit RING;

sting owner;

void create()
{
    ::create();
    
    set_name("thiefling");
    set_id( ({ "ring", "thiefling ring", "thief ring", "thiefling" }) );
    set_short("a simple darksteel ring");
    set_obvious_short("%^RESET%^%^CRST%^%^C102%^A simple %^RESET%^%^C059%^d%^C060%^a%^C061%^r%^C060%^k%^RESET%^%^C059%^st%^C060%^e%^C061%^e%^C059%^l%^RESET%^%^C247%^ r%^RESET%^%^C249%^i%^C251%^n%^RESET%^%^C247%^g%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C102%^This ring is made of a %^RESET%^%^C250%^lightweight %^RESET%^%^C102%^but durable %^RESET%^%^C059%^d%^C060%^a%^C061%^r%^C060%^k%^RESET%^%^C059%^st%^C060%^e%^C061%^e%^C059%^l%^RESET%^%^C102%^. The interior of the piece has been %^RESET%^%^C255%^polished%^RESET%^%^C102%^, revealing a %^RESET%^%^C247%^s%^C249%^i%^C251%^l%^C253%^v%^C251%^e%^C249%^r%^RESET%^%^C247%^y h%^RESET%^%^C249%^u%^C251%^e%^RESET%^%^C102%^, while the exterior has been left %^RESET%^%^C060%^natural%^RESET%^%^C102%^, its surface a gleaming shade of %^RESET%^%^C060%^p%^C061%^u%^C062%^r%^C063%^p%^C061%^l%^RESET%^%^C060%^e%^RESET%^%^C102%^. Despite its austere appearance, the ring almost seems to %^RESET%^%^C060%^p%^C063%^u%^C061%^l%^C069%^s%^RESET%^%^C060%^e %^RESET%^%^C102%^with a peculiar %^RESET%^%^C063%^energy%^RESET%^%^C102%^.%^CRST%^");
    set_lore("");
    set_property("lore difficulty", 40);
    set_property("id difficulty", 40);
    set_value(10000);
    set_flag_required("boss avatar");
    //set_property("enchantment", 7); No enchantment
    //set_heart_beat(1);
    set_wear((:this_object(),"wear_fun":));
    set_remove( (: this_object(),"remove_fun" :) );
}

int wear_fun()
{
    int align;
    
    align = this_player()->query_true_align();
    
    if(!this_player()->is_class("thief"))
    {
        tell_object(this_player(), "The ring slips through your fingers!");
        return 0;
    }
    
    if(!strlen(owner))
    {
        owner = this_player()->query_name();
        tell_object(this_player(), "%^RESET%^%^CRST%^%^C102%^The %^RESET%^%^C247%^r%^C249%^i%^C251%^n%^RESET%^%^C247%^g %^RESET%^%^C060%^p%^C061%^u%^C062%^l%^C063%^s%^C061%^e%^RESET%^%^C060%^s %^RESET%^%^C102%^furiously for a moment as you put it on.%^CRST%^");
    }
    else
    {
        if(owner != this_player()->query_name())
        {
            tell_object(this_player(), "This is not your ring!");
            return 0;
        }
    }
    
    if(this_player()->query("subrace") == "tiefling")
    {
        set_item_bonus("dungeoneering", 7);
        set_item_bonus("thievery", 7);
    }
    else
    {
        set_item_bonus("dungeoneering", 6);
        set_item_bonus("thievery", 6);
    }
    
    tell_object(this_player(), "%^RESET%^%^CRST%^%^C102%^The %^RESET%^%^C247%^r%^C249%^i%^C251%^n%^RESET%^%^C247%^g %^RESET%^%^C102%^slides onto your finger, and you feel it %^RESET%^%^C060%^s%^C061%^h%^C062%^a%^C063%^r%^C062%^p%^C061%^e%^RESET%^%^C060%^n %^RESET%^%^C102%^your skills!%^CRST%^");
    
    return 1;
}

int remove_fun()
{
    tell_object(this_player(), "%^RESET%^%^CRST%^%^C102%^You remove the %^RESET%^%^C247%^r%^C249%^i%^C251%^n%^RESET%^%^C247%^g %^RESET%^%^C102%^and feel its %^RESET%^%^C059%^d%^C060%^a%^C061%^r%^RESET%^%^C059%^k %^RESET%^%^C060%^p%^C061%^o%^C062%^w%^C061%^e%^RESET%^%^C060%^r %^RESET%^%^C102%^leave you.");
    return 1;
}
    
    