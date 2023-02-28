#include <std.h>
#include "../outpost.h"

inherit ROOM;

void create() {
    ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("Torch Lit Room");
    set_long("This room, unlike most of the rest of the city of Kinaro, is bare and plain. The walls look to have been recently excavated and lack the refinement and decoration of the rest of the buildings. Torches rest in holders on the wall and provide enough light for most to see. In the middle of the room stands a massive archway made of some unknown rock.");
	set_smell("default", "%^RESET%^%^ORANGE%^You can smell pipe smoke. ");
    set_listen("default", "%^RESET%^%^GREEN%^You can hear little here.");
    set_items(([
	"torches" : "The torches provide the room with enough light to navigate, but is a departure from the rest of Kinaro. The torches sputter as they burn.",
	"walls" :  "The walls here are mostly bare, as if they were recently excavated. ",

	     ]));
    set_exits(
      (["northwest" : "/d/dagger/kinaro/church"]) );

}

void reset() {
    ::reset();
    if(!present("archway"))
	new(OBJ"archway1")->move(this_object());
}

