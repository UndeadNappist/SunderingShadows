#include <std.h>
#include "../tharis.h"

inherit ROOM;

void create(){
	::create();
	set_property("indoors",1); 
    set_property("light",1);
	set_terrain(OLD_MOUNTS);
    set_travel(PAVED_ROAD);
	set_name("pathway to the bestiary");
	set_short("%^RESET%^%^CRST%^%^C244%^Pathway to the %^RESET%^%^C094%^b%^C130%^e%^C136%^s%^C142%^t%^C143%^i%^C136%^a%^C130%^r%^RESET%^%^C094%^y%^CRST%^");
	set_long("%^RESET%^%^CRST%^%^C244%^You stand upon a path ascending south into the %^RESET%^%^C058%^T%^C064%^h%^C070%^a%^C076%^r%^i%^C082%^s%^C070%^i%^C064%^a%^RESET%^%^C058%^n foothills%^RESET%^%^C244%^, the looming bulk of the hovering %^RESET%^%^C241%^Shadovar fortress %^RESET%^%^C244%^far in the sky above. An %^RESET%^%^C249%^e%^C250%^t%^C251%^h%^C252%^e%^C253%^r%^C251%^e%^C250%^a%^C249%^l fog %^RESET%^%^C244%^lingers here, an %^RESET%^%^C039%^o%^C045%^t%^C051%^h%^C087%^e%^C081%^r%^C075%^w%^C081%^o%^C087%^r%^C051%^l%^C045%^d%^C039%^l%^RESET%^%^C045%^y %^RESET%^%^C051%^c%^C087%^h%^C123%^i%^C087%^l%^RESET%^%^C051%^l %^RESET%^%^C244%^clawing at you. Within the %^RESET%^%^C252%^mist %^RESET%^%^C244%^are the %^RESET%^%^C241%^silhouettes %^RESET%^%^C244%^of trees, their %^RESET%^%^C101%^gnarled branches %^RESET%^%^C244%^thick with %^RESET%^%^C070%^foliage %^RESET%^%^C244%^and reaching like %^RESET%^%^C142%^z%^C148%^o%^C149%^m%^C150%^b%^C149%^i%^C148%^e%^RESET%^%^C142%^s %^RESET%^%^C244%^seeking to subsume the living. To the north, you can see the intimidating structure that is the temple of %^RESET%^%^C060%^L%^C061%^o%^C062%^r%^RESET%^%^C060%^d S%^RESET%^%^C061%^h%^C062%^a%^C063%^d%^C061%^o%^RESET%^%^C060%^w %^RESET%^%^C244%^and beyond that, the %^C141%^i%^C135%^n%^C141%^c%^C147%^a%^C153%^n%^C147%^d%^C141%^e%^C147%^s%^C153%^c%^C141%^e%^C135%^n%^C141%^t %^RESET%^%^C244%^metropolis of Tharis. \n\n%^RESET%^%^C244%^A monolithic %^RESET%^%^C094%^b%^C130%^e%^C136%^s%^C142%^t%^C143%^i%^C136%^a%^C130%^r%^RESET%^%^C094%^y %^RESET%^%^C244%^stands to the south; a titanic compound, bordered on all sides by towering walls. A %^RESET%^%^C059%^draconian portcullis %^RESET%^%^C244%^wreathed in %^RESET%^%^C161%^f%^C162%^a%^C163%^e%^C164%^r%^C165%^i%^C201%^e %^C200%^f%^C199%^i%^C198%^r%^C197%^e%^RESET%^%^C244%^ serves as its only obvious entrance.%^CRST%^\n");
	set_smell("default","%^RESET%^%^CRST%^%^C136%^The chill air is tinged with the musk of animals.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C094%^All around you are the disconcerting sounds of heavy footfalls and bestial cries.%^CRST%^");
	set_items(([
			({"portcullis","faerie fire"}) : "%^RESET%^%^CRST%^%^C244%^This %^RESET%^%^C059%^portcullis %^RESET%^%^C244%^itself is massive, towering over anyone who might approach it. It is made of thick, %^RESET%^%^C059%^black iron bars%^RESET%^%^C244%^, each one as thick as a man's arm, and reinforced with crossbars at regular intervals. The %^RESET%^%^C161%^f%^C162%^a%^C163%^e%^C164%^r%^C165%^i%^C201%^e %^C200%^f%^C199%^i%^C198%^r%^C197%^e%^RESET%^%^C244%^ that wreathes the portcullis is what truly sets it apart. The magical %^RESET%^%^C161%^f%^C162%^l%^C163%^a%^C164%^m%^C165%^e%^C201%^s %^RESET%^%^C244%^are not %^RESET%^%^C124%^h%^C160%^o%^C124%^t %^RESET%^%^C244%^to the touch, but they dance and flicker with a %^RESET%^%^C200%^l%^C199%^i%^C198%^f%^C197%^e %^RESET%^%^C244%^of their own, as if %^RESET%^%^C197%^alive %^RESET%^%^C244%^and %^RESET%^%^C199%^aware%^RESET%^%^C244%^. As one approaches the portcullis, they can feel the %^RESET%^%^C201%^e%^C200%^n%^C199%^e%^C198%^r%^C200%^g%^C201%^y %^RESET%^%^C244%^emanating from the faerie fire. It is as if the flames are alive and aware, watching their every move.%^CRST%^",
			"fortress" : "%^RESET%^%^CRST%^%^C244%^Above the city looms the ever-present %^C241%^Shadovar fortress%^C244%^, casting the entire area into a state of perpetual %^RESET%^%^C057%^t%^C056%^w%^C055%^i%^C063%^l%^C062%^i%^C063%^g%^C055%^h%^C057%^t%^RESET%^%^C244%^.%^CRST%^",
			]));
	set_exits(([
           "north" : "/d/magic/temples/lord_shadow/lord_shadowentry",
           "south" : "/d/tharis/newtharis/rooms/stable_courtyard"
			]));
}