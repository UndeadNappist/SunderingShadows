#include <std.h>
inherit ROOM;

void create() {
        ::create();
        set_property("indoors",1);
        set_property("light",1);
        set_property("no sticks",1);
        set_property("no teleport",1);
        set_terrain(DEEP_WATER);
        set_travel(PAVED_ROAD);
        set_short("A Seemingly Eternal Expanse of Ocean");
        set_long("Far, far above, where mortals make their homes, the sun shines on verdant fields and creates a vista of beauty over the landscapes of humanity, but here, there is nothing but endless blue. Deep and dark, there is no sign of sun, because that which dwells beneath needs not the perceptive stimulus that it would provide. All around you there is naught but ocean, dark and intimidating, claustrophobic in its infinity and lack of visible landmarks. It is a lonely sensation as you float here, clawing and mysterious in the depths of the world. There is no way to tell up from down, or right from left, and the experience is alien and hideously disorientating.\n");
        set_smell("default","You smell nothing but the brine of the depths and taste only salt water.");
        set_listen("default","You hear nothing but the water as it thunders relentlessly against your ear drums.");
        set_exits(([
            "down" : "/d/av_rooms/eilistraee/thedepths2";
		    set_search("default","You find water.");
		]));
}