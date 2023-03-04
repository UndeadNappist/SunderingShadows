#include <std.h>
#include <daemons.h>
#include <dirs.h>

#define VALID ({ "black", "blue", "brass", "bronze", "copper", "gold", "green", "red", "shadow", "silver", "white" }) 

inherit FEAT;

string affinity;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("Presence");
    feat_name("dragon affinity");
    feat_syntax("dragon_affinity");
    feat_desc("This feat allows an oracle with the dragon mystery to choose their chosen dragon affinity. This will determine things like resistance granted and damage types for breath weapons.
    
%^CYAN%^BOLD%^The choices for dragon affinity are as follows: \n\%^RED%^" + implode(VALID,"\n") + "%^RESET%^");
    permanent(1);
    allow_tripped(1);
}

int allow_shifted()
{
    return 1;
}

int cmd_dragon_affinity(string args)
{   
    if(this_player()->query("dragon_affinity"))
    {
        tell_object(TP,"%^BOLD%^%^WHITE%^You already have your dragon affinity set.");
        return 1;
    }

    tell_object(TP,"%^BOLD%^%^WHITE%^Select your dragon affinity:\n");
    tell_object(TP,"%^BOLD%^%^MAGENTA%^" + implode(map_array(VALID, (:"  " + $1:)), "\n"));
    tell_object(TP,"%^BOLD%^%^WHITE%^\nEnter anything else to abort.");
    input_to("select_affinity", 0);
    return 1;
}

void select_affinity(string args)
{
    if(member_array(args, VALID) == -1)
    {
        tell_object(TP,"%^BOLD%^%^WHITE%^Aborting...");
        return;
    }
    
    affinity = args;

    tell_object(TP,"%^BOLD%^%^WHITE%^You have selected %^CYAN%^" + affinity + "%^WHITE%^ as your dragon affinity.");
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

    this_player()->set("dragon_affinity", affinity);
    tell_object(TP,"%^BOLD%^%^WHITE%^Your dragon affinity has been set.");
    return;
}

int prerequisites(object ob)
{
    if (!objectp(ob))
        return 0;
        
    if (!ob->is_class("oracle"))
    {
        return 0;
    }
    
    if(ob->query_mystery() != "dragon")
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
