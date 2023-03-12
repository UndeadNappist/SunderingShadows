#include <std.h>
#include <daemons.h>
#include "../inherit/ruins.h"
inherit ARMOUR;


void create()
{
    ::create();
    set_name("cloudy-gray gloves");
    set_short("%^BLACK%^%^BOLD%^gloves of %^YELLOW%^thu%^WHITE%^n%^YELLOW%^derc%^WHITE%^l%^YELLOW%^ap%^RESET%^");
    set_obvious_short("%^BLACK%^%^BOLD%^cloudy-gray gloves%^RESET%^");
    set_id(({"gloves","Gloves","gray gloves","cloudy gloves","cloudy gray gloves","cloudy-gray gloves","gloves of thunderclap","thunder gloves","thunderclap gloves"}));
    set_long("%^CYAN%^%^BOLD%^These gloves are very thin, and cover the hands very comfortably.  The "
"material is a %^BLACK%^dull gray%^CYAN%^ shade, but the colour is imperfect, fading from "
"%^RESET%^%^WHITE%^light%^CYAN%^%^BOLD%^ to %^BLACK%^dark%^CYAN%^ patches across the gloves.  Strangely "
"enough, these patches almost seem to move, and if you watch them long enough, you can see an occasional "
"streak of %^YELLOW%^yellow%^CYAN%^ that dashes across the surface of the garment and vanishes again.  "
"Upon the underside of the gloves are words embroidered in %^WHITE%^white%^CYAN%^ thread.%^RESET%^\n");
    set_weight(4);
    set_value(6340);
    set_size(2);
    set_type("clothing");
    set_limbs(({"right arm", "left arm"}));
    set_lore("%^WHITE%^%^BOLD%^The crafting of these gloves is attributed to a certain Lachlan Crenulon, "
"a mage of no small skill.  Despite his primary skills in magecraft being those of abjuration, he was "
"also quite knowledgeable of enchantments.  Captured within these gloves was rumoured to be the power of "
"the storm itself, able to be unleashed upon the wearer's command, although such powers needed a good "
"deal of time to recharge after use.%^RESET%^\n");
    set_property("lore difficulty", 15);
    set_read("%^BLACK%^%^BOLD%^Simply think of a %^YELLOW%^<thunderclap>%^BLACK%^ to call forth the "
"gloves' power.%^RESET%^");
    set_language("common");
    set_property("enchantment", 0);
    set_wear((:this_object(), "wear_fun":));
    set_remove((:this_object(), "remove_fun":));
}

void init()
{
    object me, player, wearer;
    ::init();

    if (!objectp(me = this_object()))
        return;

    if (!objectp(player = this_player()))
        return;

    if (!objectp(wearer = environment(me)))
        return;

    if(player != wearer)
        return;

    if(interactive(player) && !avatarp(player))
        set_size(player->query_size());

    add_action("thunder_fun","thunderclap");
}

int wear_fun()
{
    object me, wearer, wearers_environment;

    if (!objectp(me = this_object()))
        return;

    if (!objectp(wearer = environment(me)))
        return;

    if (!objectp(wearers_environment = environment(wearer)))
        return;

    if((int)wearer->query_lowest_level() < 15)
    {
        tell_object(wearer, "%^BOLD%^%^WHITE%^You need more training to use this item!");
        tell_room(wearers_environment, "%^BOLD%^%^WHITE%^The gloves don't seem to fit "+wearer->query_cap_name()+".", wearer);
        return 0;
    }

    tell_object(wearer, "%^BLACK%^%^BOLD%^The cloudy surface of the gloves almost seems to move as you slip them on.%^RESET%^");
    tell_room(wearers_environment, "%^BLACK%^%^BOLD%^"+wearer->query_cap_name()+" slips the cloudy gloves over each hand.%^RESET%^", wearer);
    return 1;
}

int remove_fun()
{
    object me, wearer, wearers_environment;

    if (!objectp(me = this_object()))
        return;

    if (!objectp(wearer = environment(me)))
        return;

    if (!objectp(wearers_environment = environment(wearer)))
        return;

    tell_object(wearer, "%^BLACK%^%^BOLD%^The gloves' patterning becomes still again as you remove them.%^RESET%^");
    tell_room(wearers_environment, "%^BLACK%^%^BOLD%^"+wearer->query_cap_name()+" gently removes the cloudy gloves.%^RESET%^", wearer);

    return 1;
}

int thunder_fun(string str)
{
    object me, wearer, wearers_environment, *pplz;
    int i;

    if (!objectp(me = this_object()))
        return;

    if (!objectp(wearer = this_player()))
        return;

    if (!objectp(wearers_environment = environment(wearer)))
        return;

    if(wearer->query_bound() || wearer->query_unconscious())
    {
        wearer->send_paralyzed_message("info", wearer);
        return 1;
    }

    if(!query_worn())
    {
        write("Wearing the gloves might help.\n");
        return 1;
    }

    if(wearer->cooldown("Item -- Gloves o' Thunder"))
    {
        write("The gloves fail to respond.\n");
        return 1;
    }

    pplz = all_living(wearers_environment);

    if (!arrayp(pplz))
        return 1;

    wearer->add_cooldown("Item -- Gloves o' Thunder", 86400);

    tell_object(wearer, "%^BLACK%^%^BOLD%^You clap your hands together, and a great peal of thunder shakes the area around you!%^RESET%^\n");
    tell_room(wearers_environment,"%^BLACK%^%^BOLD%^"+wearer->query_cap_name()+" claps "+wearer->query_posessive()+" hands together, and a great peal of thunder shakes the area around you!%^RESET%^\n", wearer);

    for(i = 0; i < sizeof(pplz); ++i)
    {
        if(pplz[i] != wearer && !pplz[i]->query_true_invis() && objectp(pplz[i]))
        {
            tell_object(pplz[i],"%^BLACK%^%^BOLD%^The force of the thunderclap shakes you from your feet!%^RESET%^\n");
            pplz[i]->set_paralyzed(18,"You are still trying to stand!\n");
        }
    }

    return 1;
}

int isMagic()
{
  int i;
  i = ::isMagic();
  i = i + 1;
  return i;
}
