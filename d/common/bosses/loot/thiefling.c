/*
  thiefling.c
  
  Thiefling.
  
  Gives bonus to thievery and dungeoneering. Gives more bonus if you're a Tiefling.
  
  -- Tlaloc --
*/

#include <std.h>

#define MAX_CHARGES 10
#define TICKER_INTERVAL 600

inherit "/d/common/obj/jewelry/ring.c";

string owner;
int charges = MAX_CHARGES;
int ticker;

int query_charges() { return charges; }

void create()
{
    ::create();
    
    set_name("thiefling");
    set_id( ({ "ring", "thiefling ring", "thief ring", "thiefling" }) );
    set_short("a simple darksteel ring");
    set_obvious_short("%^RESET%^%^CRST%^%^C102%^A simple %^RESET%^%^C059%^d%^C060%^a%^C061%^r%^C060%^k%^RESET%^%^C059%^st%^C060%^e%^C061%^e%^C059%^l%^RESET%^%^C247%^ r%^RESET%^%^C249%^i%^C251%^n%^RESET%^%^C247%^g%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C102%^This ring is made of a %^RESET%^%^C250%^lightweight %^RESET%^%^C102%^but durable %^RESET%^%^C059%^d%^C060%^a%^C061%^r%^C060%^k%^RESET%^%^C059%^st%^C060%^e%^C061%^e%^C059%^l%^RESET%^%^C102%^. The interior of the piece has been %^RESET%^%^C255%^polished%^RESET%^%^C102%^, revealing a %^RESET%^%^C247%^s%^C249%^i%^C251%^l%^C253%^v%^C251%^e%^C249%^r%^RESET%^%^C247%^y h%^RESET%^%^C249%^u%^C251%^e%^RESET%^%^C102%^, while the exterior has been left %^RESET%^%^C060%^natural%^RESET%^%^C102%^, its surface a gleaming shade of %^RESET%^%^C060%^p%^C061%^u%^C062%^r%^C063%^p%^C061%^l%^RESET%^%^C060%^e%^RESET%^%^C102%^. Despite its austere appearance, the ring almost seems to %^RESET%^%^C060%^p%^C063%^u%^C061%^l%^C069%^s%^RESET%^%^C060%^e %^RESET%^%^C102%^with a peculiar %^RESET%^%^C063%^energy%^RESET%^%^C102%^.%^CRST%^");
    set_lore("%^RESET%^%^C102%^This ring was once used by a group of tiefling thieves, known as the Thieflings. This group was famous for carrying out various heists, successful in part to their clever use of magical items to aid them in their operations. It is said that if the wearer is a tiefling, it imbues additional benefit. This ring can cast %^C120%^<mirror>%^C102%^ image using two charges, and %^C120%^<timestop>%^C102%^ using nine charges. The ring has a maximum of %^C120%^" + MAX_CHARGES + "%^C102%^ on it which will slowly recover. You can check the %^C120%^<charges>%^C102%^ if you wish.%^CRST%^");
    set_property("lore difficulty", 40);
    set_property("id difficulty", 40);
    set_value(10000);
    set_weight(2);
    set_flag_required("boss avatar");
    set_wear((:this_object(),"wear_fun":));
    set_remove( (: this_object(),"remove_fun" :) );
    set_heart_beat(1);
}

void init()
{
    ::init();
    
    add_action("mirror", "mirror");
    add_action("timestop", "timestop");
    add_action("show_charges", "charges");
}

int consume_charges(int x)
{
    if(x > charges)
        return 0;
    
    charges -= x;
    
    return 1;
}

int refresh_charges(int x)
{
    charges = min( ({ charges + x, MAX_CHARGES }) );
    charges = max( ({ charges, 0 }) );
    
    return charges;
}

void heart_beat()
{   
    ticker++;
    
    if(!environment())
        return;
    
    if(!query_worn())
        return;
    
    if(ticker < TICKER_INTERVAL)
        return;
    
    ticker = 0;
    refresh_charges(1);
}
   
int mirror(string str)
{
    object spell;
    
    if(!query_worn())
        return 0;
    
    if(catch(spell = new("/cmds/spells/m/_mirror_image")))
        return 0;
    
    if (this_player()->query_bound() || this_player()->query_unconscious() || this_player()->query_paralyzed())
    {
        this_player()->send_paralyzed_message("info", this_player());
        return 1;
    }
    
    if(!consume_charges(2))
        return notify_fail(sprintf("The ring only has %d %s.", charges, charges > 1 ? "charges" : "charge"));
    
    objectp(spell) && spell->use_spell(this_player(), 0, this_player()->query_level(), 100, "mage");
    
    return 1;
}

int timestop(string str)
{
    object spell;
    
    if(!query_worn())
        return 0;
    
    if(catch(spell = new("/cmds/spells/t/_timestop")))
        return 0;
    
    if (this_player()->query_bound() || this_player()->query_unconscious() || this_player()->query_paralyzed())
    {
        this_player()->send_paralyzed_message("info", this_player());
        return 1;
    }
    
    if(!consume_charges(9))
        return notify_fail(sprintf("The ring only has %d %s.", charges, charges > 1 ? "charges" : "charge"));
    
    objectp(spell) && spell->use_spell(this_player(), 0, this_player()->query_level(), 100, "mage");
    
    return 1;
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

int show_charges()
{
    printf("You can tell the ring currently has %d out of %d charges available.\n", charges, MAX_CHARGES);
    return 1;
}

    
    