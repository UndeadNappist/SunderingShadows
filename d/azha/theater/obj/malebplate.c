// updated cha bonus from the new system. Nienne, 09/07.
#include <std.h>
inherit "/d/common/obj/armour/breastplate.c";

void create(){
    ::create();
    set_name("arandur plate");
    set_id(({ "cuirass", "plate", "arandur cuirass", "arandur plate", "armor", "armour"}));
    set_short("%^BOLD%^%^BLUE%^A%^WHITE%^r%^GREEN%^a%^BLUE%^n%^WHITE%^d%^GREEN%^u%^BLUE%^r %^WHITE%^Cuirass%^RESET%^");
    set_obvious_short("%^BOLD%^%^WHITE%^A silver-%^BLUE%^blue%^WHITE%^ cuirass%^RESET%^");
    set_long( "%^BOLD%^%^WHITE%^This breastplate is molded into the shape of a muscular man's torso.  The breastplate is forged from arandur, a rare metal that when tempered becomes %^BLUE%^s%^WHITE%^i%^BLUE%^l%^WHITE%^v%^BLUE%^e%^WHITE%^r%^BLUE%^-%^WHITE%^b%^BLUE%^l%^WHITE%^u%^BLUE%^e%^WHITE%^ with a reflective %^RESET%^%^CYAN%^g%^GREEN%^r%^BOLD%^e%^RESET%^%^GREEN%^e%^CYAN%^n%^BOLD%^%^WHITE%^ sheen. The two sections of the breastplate, front and back, join together with a series of buckles. This gives the wearer some leeway in the fit of the armor, but not much. Since the cuirass is sculpted to look like a muscular man's torso, there is not much give in the way of fit.  This style of armor was popular in classical times. Though simple looking, the breastplate still looks as if it would protect the vital organs.%^RESET%^\n");
    //set_weight(40);
    set_value(3000);
    set_lore( "Thanks to Yaran Silverpage's friendship with a couple of blacksmiths, the armor used in his play All the Kings' Horsemen was actually made from authentic arandur. This rare natural metal is usually found in igneous rocks, usually as streaks of blue-green ore amid vitreous glass. When refined and forged, the metals is silver-blue with a green reflective shine. Yaran had breastplates for each knight, bishop, and rook made from this rare and exotic metal. A pricey endeavor that certainly paid off. - Pages of Silverpage - The Avant Garde Playwrite - Damona Silverpage");
    set_property("lore difficulty",14);
    set_size(2);
    set_property("enchantment",2);
    set_item_bonus("charisma",1);
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
}

int wear_func(){
    object player = environment(this_object());
    if(member_array((string)player->query_body_type(), ({ "frail", "gaunt" ,"scrawny", "skinny", "slight", "lean", "slender", "thin","slim","svelte" })) != -1 ){      
        tell_object(player,"%^BOLD%^%^BLUE%^With a steady diet of beer and beef, you might fit into the breastplate one day!");
      	return 0;
    }
    if((int)player->query_highest_level() < 15){
        tell_object(player, "%^BOLD%^%^BLUE%^No matter how hard you try, you just can't figure out how to buckle the breastplate!");
        return 0;
    }
    if((string)player->query_gender() == "female"){
        tell_object(player,"%^BOLD%^%^BLUE%^Seeing as the breastplate is made for a male, you think twice about wearing it.");
        tell_room(environment(player),"%^BOLD%^%^CYAN%^"+player->query_cap_name()+" looks over the breastplate and changes her mind.", player);
			return 0;
    }
    else{
        tell_room(environment(player),"%^BOLD%^%^WHITE%^"+player->query_cap_name()+" straps the breastplate on. The breastplate molds to his body for a tight fit.", player);
     	tell_object(player,"%^BOLD%^%^WHITE%^You strap the breastplate on, getting a secret thrill from how it molds to your torso.");
        return 1;
    }
}

int remove_func(){
    object player = environment(this_object());
    tell_room(environment(player),"%^BOLD%^%^BLUE%^"+player->query_cap_name()+" unbuckles the straps that hold the breastplate's sections together.%^RESET%^",player);
    tell_object(player,"%^BOLD%^%^BLUE%^You unbuckle the straps that hold the breastplate's sections together.%^RESET%^");
    return 1;
}

