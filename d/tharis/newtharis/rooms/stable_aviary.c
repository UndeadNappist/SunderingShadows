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
	set_long("%^RESET%^%^CRST%^%^C244%^This aviary sits atop a craggy peak and is constructed from the ancient, %^RESET%^%^C059%^dark stone %^RESET%^%^C244%^of the mountain and %^RESET%^%^C240%^g%^C242%^l%^C244%^e%^C242%^a%^C240%^m%^C242%^i%^C244%^n%^C242%^g%^RESET%^%^C244%^, twisted %^RESET%^%^C240%^metalwork %^RESET%^%^C244%^that forms the framework for the massive structure. It features sweeping views of the lower level of the %^RESET%^%^C094%^b%^C130%^e%^C136%^s%^C142%^t%^C143%^i%^C136%^a%^C130%^r%^RESET%^%^C094%^y %^RESET%^%^C244%^and %^RESET%^%^C028%^t%^C035%^r%^C042%^a%^C035%^i%^C028%^n%^C035%^i%^C042%^n%^C035%^g %^RESET%^%^C028%^a%^C035%^r%^C042%^e%^C035%^n%^C028%^a%^RESET%^%^C244%^, as well as %^RESET%^%^C141%^i%^C135%^n%^C141%^c%^C147%^a%^C153%^n%^C147%^d%^C141%^e%^C147%^s%^C153%^c%^C141%^e%^C135%^n%^C141%^t %^RESET%^%^C244%^metropolis of Tharis. The mountain is shrouded in %^RESET%^%^C250%^m%^C255%^i%^C015%^s%^C250%^t %^RESET%^%^C244%^and %^RESET%^%^C240%^s%^C241%^h%^C242%^a%^C243%^d%^C241%^o%^C240%^w%^RESET%^%^C244%^, with jagged rocks, making it impossible to access but by the stairs that have been carved into the stone or those riding atop one of the flying mounts that can be purchased here.%^CRST%^%^\n\n%^RESET%^%^C244%^Inside the aviary, the space is %^RESET%^%^C242%^dimly lit%^RESET%^%^C244%^, with %^RESET%^%^C161%^f%^C162%^l%^C163%^i%^C164%^c%^C165%^k%^C201%^e%^C200%^r%^C199%^i%^C198%^n%^C197%^g %^RESET%^%^C196%^t%^C160%^o%^C161%^r%^C162%^c%^C163%^h%^C164%^e%^C165%^s %^RESET%^%^C244%^casting %^RESET%^%^C240%^e%^C241%^e%^C242%^r%^C241%^i%^RESET%^%^C240%^e shadows %^RESET%^%^C244%^across the walls. The ceilings are high, and the walkways narrow, creating a sense of height and danger. The aviary features a series of %^RESET%^%^C059%^perches %^RESET%^%^C244%^and %^C144%^roosts%^RESET%^%^C244%^, with tall, %^RESET%^%^C094%^twisting branches %^RESET%^%^C244%^and a series of %^RESET%^%^C248%^shallow pools%^RESET%^%^C244%^, each one filled with %^RESET%^%^C241%^dark%^RESET%^%^C244%^, %^RESET%^%^C242%^r%^C246%^e%^C248%^f%^C249%^l%^C244%^e%^C246%^c%^C248%^t%^C242%^i%^C244%^v%^C246%^e %^RESET%^%^C244%^w%^C246%^a%^C248%^t%^C244%^e%^C246%^r %^RESET%^%^C244%^that amplifies the %^RESET%^%^C240%^darkness %^RESET%^%^C244%^above. This is a place of %^RESET%^%^C060%^p%^C061%^o%^C062%^w%^C061%^e%^C060%^r %^RESET%^%^C244%^and %^RESET%^%^C088%^d%^C124%^a%^C160%^n%^C196%^g%^C124%^e%^C088%^r%^RESET%^%^C244%^, where only the bravest and most skilled adventurers would dare to venture.%^CRST%^%^CRST%^\n\n");
	set_smell("default","%^RESET%^%^CRST%^%^C136%^The air is thick with the scent of magic and the acrid aroma of the beasts held here.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C094%^All around you are the disconcerting sounds of heavy footfalls and bestial cries.%^CRST%^");
	set_items(([
			({"faerie fire", "torches"}) : "%^RESET%^%^CRST%^%^C244%^The torches burning with %^RESET%^%^C161%^f%^C162%^a%^C163%^e%^C164%^r%^C165%^i%^C201%^e %^C200%^f%^C199%^i%^C198%^r%^C197%^e %^RESET%^%^C244%^fl%^RESET%^%^C162%^i%^C244%^ck%^C201%^e%^C244%^r and d%^RESET%^%^C165%^a%^C244%^nc%^C196%^e %^RESET%^%^C244%^in the %^RESET%^%^C242%^dimly lit %^RESET%^%^C244%^aviary, bathing the space in an %^RESET%^%^C163%^ethereal glow %^RESET%^%^C244%^and %^RESET%^%^C240%^e%^C242%^e%^C244%^r%^C242%^i%^C240%^e shadows%^RESET%^%^C244%^. The %^RESET%^%^C059%^dark stone %^RESET%^%^C244%^of the aviary is slick with %^RESET%^%^C195%^moisture%^RESET%^%^C244%^, and the torches' light makes it gleam like polished %^RESET%^%^C240%^obsidian%^RESET%^%^C244%^. The stone walls rise up to a high arched ceiling, which is lost in %^RESET%^%^C241%^darkness%^RESET%^%^C244%^, giving the aviary a sense of vastness and mystery.%^CRST%^",
			"roosts" : "%^RESET%^%^CRST%^%^C136%^These %^RESET%^%^C144%^roosts %^RESET%^%^C136%^are spacious and well-padded, with a thick layer of soft, fragrant %^RESET%^%^C229%^straw %^RESET%^%^C136%^for cushion. The walls of the roosts are made of sturdy, %^RESET%^%^C094%^woven branches%^RESET%^%^C136%^, with narrow gaps that allow %^RESET%^%^C159%^fresh air %^RESET%^%^C136%^to circulate throughout the space.%^CRST%^",
			"training arena" : "%^RESET%^%^CRST%^%^C035%^The southeastern path leads to a vast arena ringed by steep, %^RESET%^%^C250%^r%^C249%^o%^C248%^c%^C249%^k%^C250%^y m%^C249%^o%^C248%^u%^C247%^n%^C248%^t%^C249%^a%^C250%^i%^C249%^n%^C248%^s%^RESET%^%^C035%^. It is there that the skilled %^RESET%^%^C060%^trainers %^RESET%^%^C035%^of the %^RESET%^%^C094%^b%^C130%^e%^C136%^s%^C142%^t%^C143%^i%^C136%^a%^C130%^r%^RESET%^%^C094%^y %^RESET%^%^C035%^teach and exercise the exotic beasts housed here.%^CRST%^",
			"perches" : "%^RESET%^%^CRST%^%^C244%^These %^RESET%^%^C059%^perches %^RESET%^%^C244%^are situated in high, open spaces, with commanding views of the surrounding %^RESET%^%^C064%^l%^C070%^a%^C076%^n%^C082%^d%^C083%^s%^C082%^c%^C076%^a%^C070%^p%^C064%^e%^RESET%^%^C244%^. Constructed from thick, heavy %^RESET%^%^C059%^iron bars%^RESET%^%^C244%^, each one is carefully crafted and welded to form a strong and stable structure that would support even a drake. The surface of each perch is lined with rough, durable %^RESET%^%^C094%^leather%^RESET%^%^C244%^, providing a tough and resilient surface for the animals' claws to cling to.%^CRST%^"
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