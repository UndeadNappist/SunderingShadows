//Faebala 02/19/23

#include <std.h>
#include "../tharis.h"

inherit STABLE;

void create(){
	::create();
	set_property("indoors",1); 
    set_property("light",1);
	set_terrain(OLD_MOUNTS);
    set_travel(PAVED_ROAD);
	set_name("the aviary");
	set_short("%^RESET%^%^CRST%^%^C244%^The %^RESET%^%^C087%^A%^C123%^v%^C159%^i%^C195%^a%^C123%^r%^RESET%^%^C087%^y%^CRST%^");
	set_long("%^CRST%^\n\n");
	set_smell("default","%^RESET%^%^CRST%^%^C136%^The air is thick with the scent of magic and the acrid aroma of the beasts held here.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C094%^All around you are the disconcerting sounds of heavy footfalls and bestial cries.%^CRST%^");
	set_items(([
			
			"training arena" : "%^RESET%^%^CRST%^%^C035%^The southeastern path leads to a vast arena ringed by steep, %^RESET%^%^C250%^r%^C249%^o%^C248%^c%^C249%^k%^C250%^y m%^C249%^o%^C248%^u%^C247%^n%^C248%^t%^C249%^a%^C250%^i%^C249%^n%^C248%^s%^RESET%^%^C035%^. It is there that the skilled %^RESET%^%^C060%^trainers %^RESET%^%^C035%^of the %^RESET%^%^C094%^b%^C130%^e%^C136%^s%^C142%^t%^C143%^i%^C136%^a%^C130%^r%^RESET%^%^C094%^y %^RESET%^%^C035%^teach and exercise the exotic beasts housed here.%^CRST%^",
			
			]));
	set_exits(([
           "down" : "/d/tharis/newtharis/rooms/stable_courtyard",
			]));
	set_animal(
        ({"lizard","bicorn"}),
        ({"/d/tharis/newtharis/mounts/riding_lizard","/d/tharis/newtharis/mounts/bicorn"})
        );
    set_animal_price(
        ({""}),
        ({500})
        );
   set_stalls(20);
   ::fill_stalls();
}