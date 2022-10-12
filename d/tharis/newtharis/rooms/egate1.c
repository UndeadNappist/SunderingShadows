#include <std.h>
#include "../tharis.h"
inherit CROOM;

void create(){
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",0);
    set_property("light",2);
    set_name("City Gates");
    set_short("%^RESET%^%^ORANGE%^City Gates%^RESET%^");
    set_long("%^RESET%^%^C244%^The city walls loom high above you. "
"The walls themselves are old, made up from giant blocks of %^RESET%^%^WHITE%^granite"
"%^BOLD%^%^BLACK%^ cut and placed carefully. Age has worn the stones smooth "
"and there is no purchase to climb. There are signs of repaired damage though, as "
"some spots are li%^RESET%^%^WHITE%^g%^BOLD%^%^BLACK%^hte%^RESET%^%^WHITE%^r"
"%^BOLD%^%^BLACK%^ than others. %^RESET%^%^GREEN%^Spar%^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^e "
"v%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^getation %^BOLD%^%^BLACK%^fights for survival along "
"the base of the wall. A giant %^RESET%^%^ORANGE%^set of gates%^BOLD%^%^BLACK%^ lead out "
"of the city.%^RESET%^\n");
    set_smell("default","%^RESET%^%^CRST%^%^C141%^The air carries a thousand scents of a busy city.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C099%^You hear the bustle of the citizens going about their day.%^CRST%^");

    set_exits(([
      "east" : ROOMS"egate2",
      "west" : ROOMS"elf4",
    ]));
    set_items (([
      "fortress" : "%^RESET%^%^C244%^Above the city looms the ever-present %^RESET%^%^C241%^Shadovar fortress%^RESET%^%^C244%^, casting the entire area into a state of perpetual %^RESET%^%^C057%^t%^C056%^w%^C055%^i%^C063%^l%^C062%^i%^C063%^g%^C055%^h%^C057%^t%^RESET%^%^C244%^.%^CRST%^",
      "vegetation" : "%^RESET%^%^GREEN%^Small shrubs and sparse grass fight for survival.%^RESET%^",
      "walls" : "%^RESET%^%^C244%^The walls themselves are old but sturdy, made up from giant blocks of %^RESET%^%^C246%^g%^C247%^r%^C248%^a%^C249%^n%^C248%^i%^C247%^t%^C246%^e %^RESET%^%^C244%^precisely cut and fit together.%^CRST%^",
      ({"cobblestones", "street", "road", "ground"}): "%^RESET%^%^CRST%^%^C244%^The streets here are freshly lain %^RESET%^%^C249%^cobblestones%^RESET%^%^C244%^, mostly in m%^RESET%^%^C246%^o%^C247%^t%^C249%^t%^C247%^l%^C246%^e%^C244%^d shades of %^RESET%^%^C249%^gray%^RESET%^%^C244%^. However, swaths of them have been painted with a %^RESET%^%^C022%^v%^C028%^e%^C029%^r%^C035%^d%^C041%^a%^C035%^n%^C029%^t %^RESET%^%^C028%^g%^C022%^l%^C028%^a%^C029%^z%^C035%^e%^RESET%^%^C244%^, making them stand out amongst the rest.%^CRST%^",
      "gates" : "%^BLACK%^%^BOLD%^Giant gates are held open, yet could lock down to close down the city.%^RESET%^",
    ]));
}

void reset(){
    ::reset();
    if(!present("golem")){new("/d/tharis/newtharis/mobs/bladegolem.c")->move(TO);}
}

void init() {
    ::init();
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}