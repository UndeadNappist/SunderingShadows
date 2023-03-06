//Faebala 02/19/23

#include <std.h>
#include "../tharis.h"

inherit STABLE;

void create(){
	::create();
	set_property("indoors",0); 
    set_property("light",1);
	set_terrain(OLD_MOUNTS);
    set_travel(PAVED_ROAD);
	set_name("courtyard of the bestiary");
	set_short("%^RESET%^%^CRST%^%^C244%^Courtyard of the %^RESET%^%^C094%^b%^C130%^e%^C136%^s%^C142%^t%^C143%^i%^C136%^a%^C130%^r%^RESET%^%^C094%^y%^CRST%^");
	set_long("%^RESET%^%^CRST%^%^C244%^As you step into the courtyard of the stable, your senses are immediately overwhelmed by the %^RESET%^%^C033%^b%^C039%^u%^C045%^s%^C051%^t%^C087%^l%^C045%^i%^C039%^n%^C033%^%^g a%^RESET%^%^C039%^c%^C045%^t%^C051%^i%^C087%^v%^C045%^i%^C039%^t%^C033%^y %^RESET%^%^C244%^around you. This area is teeming with %^RESET%^%^C060%^trainers %^RESET%^%^C244%^hurrying to and fro, carrying %^RESET%^%^C094%^equipment%^RESET%^%^C244%^, leading enormous riding %^RESET%^%^C094%^b%^C130%^e%^C136%^a%^C142%^s%^C143%^t%^C136%^s%^RESET%^%^C244%^, and giving orders to %^RESET%^%^C061%^stable hands%^RESET%^%^C244%^. The animals themselves are everywhere, tied to %^RESET%^%^C059%^hitching posts%^RESET%^%^C244%^, being led to and from the %^RESET%^%^C243%^training arena%^RESET%^%^C244%^, or being groomed. Some of them are %^RESET%^%^C015%^s%^C255%^n%^C253%^o%^C252%^r%^C250%^t%^C253%^i%^C255%^n%^C015%^g %^RESET%^%^C244%^and pawing the ground, eager to get to work, while others are placidly standing by, seemingly unperturbed by the chaos. Despite the frenzied activity, there is a sense of order and routine to the proceedings. Trainers are busy putting their charges through their paces, making sure that they are fit and ready for whatever challenges lie ahead. The various %^RESET%^%^C064%^p%^C071%^a%^C078%^d%^C071%^d%^C064%^o%^C071%^c%^C078%^k%^C071%^s %^RESET%^%^C244%^and %^RESET%^%^C144%^stalls %^RESET%^%^C244%^required to house an extensive menagerie of exotic riding beasts are located to the west and east, while a vast %^RESET%^%^C028%^t%^C035%^r%^C042%^a%^C035%^i%^C028%^n%^C035%^i%^C042%^n%^C035%^g %^RESET%^%^C028%^a%^C035%^r%^C042%^e%^C035%^n%^C028%^a %^RESET%^%^C244%^is nestled amidst the mountains to the southeast. A set of %^RESET%^%^C250%^s%^C249%^t%^C248%^o%^C249%^n%^C250%^e s%^RESET%^%^C249%^t%^C248%^e%^C249%^p%^C250%^s %^RESET%^%^C244%^has been carved directly into the base of a sheer rock wall to the south. A %^RESET%^%^C059%^draconian portcullis %^RESET%^%^C244%^wreathed in %^RESET%^%^C161%^f%^C162%^a%^C163%^e%^C164%^r%^C165%^i%^C201%^e %^C200%^f%^C199%^i%^C198%^r%^C197%^e%^RESET%^%^C244%^ appears to be the most obvious way to leave this place.%^CRST%^\n\n%^RESET%^%^CRST%^%^C244%^There is a %^RESET%^%^C144%^sign %^RESET%^%^C244%^displaying what sort of mounts can be purchased here.\n\n%^CRST%^");
	set_smell("default","%^RESET%^%^CRST%^%^C136%^The smell of hay, manure, and sweat is pungent and distinct.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C094%^All around you are the disconcerting sounds of heavy footfalls and bestial cries.%^CRST%^");
	set_items(([
			({"portcullis","faerie fire"}) : "%^RESET%^%^CRST%^%^C244%^This %^RESET%^%^C059%^portcullis %^RESET%^%^C244%^itself is massive, towering over anyone who might approach it. It is made of thick, %^RESET%^%^C059%^black iron bars%^RESET%^%^C244%^, each one as thick as a man's arm, and reinforced with crossbars at regular intervals. The %^RESET%^%^C161%^f%^C162%^a%^C163%^e%^C164%^r%^C165%^i%^C201%^e %^C200%^f%^C199%^i%^C198%^r%^C197%^e%^RESET%^%^C244%^ that wreathes the portcullis is what truly sets it apart. The magical %^RESET%^%^C161%^f%^C162%^l%^C163%^a%^C164%^m%^C165%^e%^C201%^s %^RESET%^%^C244%^are not %^RESET%^%^C124%^h%^C160%^o%^C124%^t %^RESET%^%^C244%^to the touch, but they dance and flicker with a %^RESET%^%^C200%^l%^C199%^i%^C198%^f%^C197%^e %^RESET%^%^C244%^of their own, as if %^RESET%^%^C197%^alive %^RESET%^%^C244%^and %^RESET%^%^C199%^aware%^RESET%^%^C244%^. As one approaches the portcullis, they can feel the %^RESET%^%^C201%^e%^C200%^n%^C199%^e%^C198%^r%^C200%^g%^C201%^y %^RESET%^%^C244%^emanating from the faerie fire. It is as if the flames are alive and aware, watching their every move.%^CRST%^",
			"fortress" : "%^RESET%^%^CRST%^%^C244%^Above the city looms the ever-present %^C241%^Shadovar fortress%^C244%^, casting the entire area into a state of perpetual %^RESET%^%^C057%^t%^C056%^w%^C055%^i%^C063%^l%^C062%^i%^C063%^g%^C055%^h%^C057%^t%^RESET%^%^C244%^.%^CRST%^",
			"tethering posts" : "%^RESET%^%^CRST%^%^C059%^This iron post is several feet tall and designed to withstand the force of a massive animal pulling against it, buried deep in the %^RESET%^%^C058%^ground %^RESET%^%^C059%^for stability. It is cylindrical in shape, with a diameter of several inches. At the top of the post, there is a large, sturdy iron ring, which is where the animal's tether is attached. This ring is made of the same heavy-duty iron as the post itself, %^RESET%^%^C088%^w%^C124%^e%^C160%^l%^C196%^d%^C124%^e%^RESET%^%^C088%^d %^RESET%^%^C059%^securely into place to ensure it can withstand the animal's weight and strength.%^CRST%^",
			"trainers" : "%^RESET%^%^CRST%^%^C060%^Throughout it all, the trainers themselves are a study in %^RESET%^%^C061%^concentration %^RESET%^%^C060%^and %^RESET%^%^C062%^focus%^RESET%^%^C060%^. They move with purpose and precision, their eyes fixed on the %^RESET%^%^C094%^b%^C130%^e%^C136%^a%^C142%^s%^C143%^t%^C136%^s%^RESET%^%^C060%^, analyzing their movements, and making subtle adjustments to their training as they go. Despite the constant noise and movement around them, they remain unflappable and completely absorbed in their work.%^CRST%^",
			"training arena" : "%^RESET%^%^CRST%^%^C035%^The southeastern path leads to a vast arena ringed by steep, %^RESET%^%^C250%^r%^C249%^o%^C248%^c%^C249%^k%^C250%^y m%^C249%^o%^C248%^u%^C247%^n%^C248%^t%^C249%^a%^C250%^i%^C249%^n%^C248%^s%^RESET%^%^C035%^. It is there that the skilled %^RESET%^%^C060%^trainers %^RESET%^%^C035%^of the %^RESET%^%^C094%^b%^C130%^e%^C136%^s%^C142%^t%^C143%^i%^C136%^a%^C130%^r%^RESET%^%^C094%^y %^RESET%^%^C035%^teach and exercise the exotic beasts housed here.%^CRST%^",
			({"paddocks", "stalls", "pens"}) : "%^RESET%^%^CRST%^%^C144%^An expansive series of %^RESET%^%^C064%^p%^C071%^a%^C078%^d%^C071%^d%^C064%^o%^C071%^c%^C078%^k%^C071%^s%^RESET%^%^C144%^, %^RESET%^%^C244%^stalls%^RESET%^%^C144%^, and %^RESET%^%^C143%^pens %^RESET%^%^C144%^are designed to ensure the safety and comfort of the animals as well as their handlers. While still quite large in order to hold the sizeable %^RESET%^%^C094%^b%^C130%^e%^C136%^a%^C142%^s%^C143%^t%^C136%^s%^RESET%^%^C144%^, these stalls and pens are typically smaller than the paddocks, and contain soft bedding of %^RESET%^%^C229%^hay %^RESET%^%^C144%^and %^RESET%^%^C087%^w%^C123%^a%^C159%^t%^C123%^e%^C087%^r tr%^C123%^o%^C159%^u%^C123%^g%^C087%^hs%^RESET%^%^C144%^ to ensure the animals are comfortable and well-cared for.%^CRST%^",
			]));
	set_exits(([
           "north" : "/d/tharis/newtharis/rooms/stable_path",
           "up" : "/d/tharis/newtharis/rooms/stable_aviary"
			]));
	set_animal(
        ({"lizard","bicorn","hell boar"}),
        ({"/d/tharis/newtharis/mounts/riding_lizard","/d/tharis/newtharis/mounts/bicorn","/d/tharis/newtharis/mounts/hell_boar"})
        );
    set_animal_price(
        ({"lizard","bicorn","hell boar"}),
        ({500,700,1000})
        );
   set_stalls(20);
   ::fill_stalls();
}