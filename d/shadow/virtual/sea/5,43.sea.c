// sea description for Isto Delmah, player owned island.

#include <std.h>

inherit ROOM;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dockentrance() { return 1; }

void create() {
    set_indoors(1);
    ::create();
    set_light(2);
    set_short("You are on the Saakrune Sea");
    set_property("no teleport",1);
    set_long(
@OLI
	%^BOLD%^You are on the Saakrune Sea.%^RESET%^
You see an imposing island in the water here.
OLI
	);
	set_exits(([
		"north":"/d/shadow/virtual/4,43.sea",
		"south":"/d/shadow/virtual/6,43.sea",
		"east":"/d/shadow/virtual/5,44.sea",
		"west":"/d/shadow/virtual/5,42.sea",
		"dock":"/d/shadow/virtual/sea/isto_delmah.dock"
		]));
	
	set_smell("default","You catch floral scents on the air flowing past the island.");
	set_listen("default","You can hear the crashing waves against the island's shores.");
}
		
