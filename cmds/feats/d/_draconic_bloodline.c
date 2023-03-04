#include <std.h>
#include <daemons.h>
#include <dirs.h>

#define VALID ({ "black", "blue", "brass", "bronze", "copper", "gold", "green", "red", "silver", "white" }) 

inherit FEAT;

string affinity;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("Presence");
    feat_name("draconic_bloodline");
    feat_syntax("draconic_bloodline");
    feat_desc("This feat allows a sorcerer with the draconic bloodline to choose their chosen dragon blood. This will determine things like immunity granted and spell damage bonuses.
    
%^CYAN%^BOLD%^The choices for draconic bloodline are as follows: \n\%^RED%^" + implode(VALID,"\n") + "%^RESET%^");
    permanent(1);
    allow_tripped(1);
}

int allow_shifted()
{
    return 1;
}

int cmd_draconic_bloodline(string args)
{   
    if(this_player()->query("draconic_bloodline"))
    {
        tell_object(TP,"%^BOLD%^%^WHITE%^You already have your draconic bloodline set.");
        return 1;
    }

    tell_object(TP,"%^BOLD%^%^WHITE%^Select your draconic bloodline:\n");
    tell_object(TP,"%^BOLD%^%^MAGENTA%^" + implode(map_array(VALID, (:"  " + $1:)), "\n"));
    tell_object(TP,"%^BOLD%^%^WHITE%^\nEnter anything else to abort.");
    input_to("select_bloodline", 0);
    return 1;
}

void select_bloodline(string args)
{
    if(member_array(args, VALID) == -1)
    {
        tell_object(TP,"%^BOLD%^%^WHITE%^Aborting...");
        return;
    }
    
    affinity = args;

    tell_object(TP,"%^BOLD%^%^WHITE%^You have selected %^CYAN%^" + affinity + "%^WHITE%^ as your draconic bloodline.");
    tell_object(TP,"%^BOLD%^%^WHITE%^Is this a correct choice? Type %^GREEN%^yes%^WHITE%^ to confirm, anything else to abort.");
    input_to("confirm_selection", 0);
    return;
}

void confirm_selection(string args)
{
    if (args != "yes") {
        tell_object(this_player(), "%^BOLD%^%^WHITE%^Aborting...");
        return;
    }

    this_player()->set("draconic_bloodline", affinity);
    tell_object(TP,"%^BOLD%^%^WHITE%^Your draconic bloodline has been set.");
    return;
}

int prerequisites(object ob)
{
    if (!objectp(ob))
        return 0;
        
    if (!ob->is_class("sorcerer"))
    {
        return 0;
    }
    
    if(ob->query_mystery() != "draconic")
        return 0;
    
    return ::prerequisites(ob);
}

void permanent_effects(object ob)
{
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void reverse_permanent_effects(object ob)
{
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
