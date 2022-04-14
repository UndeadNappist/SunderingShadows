// Chernobog (3/15/22)
// Yniam Waystation - Hub

#include <std.h>
#include "../defs.h"
inherit VAULT;

void create(){
    ::create();
    set_terrain(GRASSLANDS);
    set_travel(DIRT_ROAD);
    set_property("indoors", 0);
    set_property("light", 2);
    set_name("A waystation in the Yniam Plains");
    set_short("%^RESET%^%^CRST%^%^C046%^The %^C130%^hub %^C046%^of the %^C144%^Yniam waystation%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C101%^The tall pointed walls of the %^C058%^palisade %^C101%^encircle this small outpost, offering some manner of protection. %^C059%^Smoke %^RESET%^%^C101%^and the sharp %^C255%^ri%^C252%^n%^C255%^gi%^C252%^n%^C255%^g %^C101%^of %^C243%^m%^C245%^e%^C247%^t%^C245%^a%^C243%^l %^RESET%^%^C101%^encroach from the north, next to a wooden building serving as a %^C136%^meeting hall%^C101%^. On the opposite end of the outpost there is another %^C130%^structure%^C101%^, though it appears to be windowless, and is flanked by a %^C195%^gl%^C231%^as%^C195%^s gre%^C231%^enh%^C195%^o%^C231%^u%^C195%^se %^RESET%^%^C101%^on the side.  A large %^C245%^r%^C248%^i%^C245%^n%^C248%^g %^C245%^of %^C248%^s%^C245%^t%^C248%^o%^C245%^n%^C248%^e%^C245%^s %^RESET%^%^C101%^rests in the middle of the clearing, a large firepit ready for a bonfire. Workers move about several projects in this clearing, building along the periphery and using the wooden walls as support in construction. %^CRST%^\n");
    set_smell("default", "%^RESET%^%^CRST%^%^C144%^A strange %^C156%^acrid scent %^C144%^is carried on the breeze.%^CRST%^");
    set_listen("default", "%^RESET%^%^CRST%^%^C126%^The sounds of people at work fill the air.%^CRST%^");
    set_items(([
        ({"walls", "palisade"}) : "%^RESET%^%^CRST%^%^C058%^The palisade is a %^C136%^wooden wall %^C058%^comprised of logs sunk end-first into the earth and lashed together with strips of %^C130%^leather%^C058%^. It is a simple defense meant more to buy time than to actually keep someone out.%^CRST%^",
        ({"meeting hall", "hall"}) : "",
        ]));
    set_exits(([
        "southwest" : ROOMS"palisade1",
        "northeast" : ROOMS"palisade2",
        "southeast" : ROOMS"palisade3",
        "northwest" : ROOMS"meetinghall",
        "north" : ROOMS"forge",
        "east" : ROOMS"lab",
        ]));
}

