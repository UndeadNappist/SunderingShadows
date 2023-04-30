//  Isto Delmah: Dock - Pandora, Mar 2023
//  Descriptions by Antoinette

#include <std.h>
#include <objects.h>

inherit DOCK;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }

void create() {
	::create();
	set_terrain(BEACH);
	set_travel(FOOT_PATH);
	set_property("light", 3);
	set_property("indoors", 0);
	set_property("no teleport",1);
	set_name("Dock of Isto’Delmah");
	set_short("%^RESET%^%^C241%^Dock of %^C007%^I%^C255%^st%^C007%^o%^C241%^’D%^C243%^e%^C244%^l%^C246%^m%^C251%^a%^C255%^h");
	set_long("%^RESET%^%^C229%^Wooden %^C240%^planks%^C229%^ make up a dock that lies built on the shore  and lead to a %^C072%^cobblestone path%^C229%^ ahead. A small %^C242%^shack%^C229%^ stands to the right side from the %^C242%^dock%^C229%^, keeping guard over the incoming and outgoing ships. The dock itself seems to contain one or two converted small merchant vessels. Small shells lie buried underneath the white sand and the terrain begins to rise up to the north and south, where %^C248%^cliffs%^C229%^ seem to block off any other natural access to the landmass of the island. A short distance to the east, the %^C072%^cobblestone path%^C229%^ leads to the beginnings of a %^C242%^strange forest%^C229%^ of %^C241%^black trees%^C229%^ and %^C242%^black vegetation%^C229%^ with %^C242%^black roots%^C229%^ and %^C242%^black leaves%^C229%^. Hundreds of %^C196%^colourful flowers%^C229%^ offer a stark contrast to the dark vegetation. The %^C039%^sea%^C229%^ lies to the west, still and quiet.\n");
	//  Wooden planks make up a dock that lies built on the shore  and lead to a cobblestone path ahead. A small shack stands to the right side from the dock, keeping guard over the incoming and outgoing ships. The dock itself seems to contain one or two converted small merchant vessels. Small shells lie buried underneath the white sand and the terrain begins to rise up to the north and south, where cliffs seem to block off any other natural access to the landmass of the island. A short distance to the east, the cobblestone path leads to the beginnings of a strange forest of black trees and black vegetation with black roots and black leaves. Hundreds of colourful flowers offer a stark contrast to the dark vegetation. The sea lies to the west, still and quiet.
	set_smell("default", "%^RESET%^%^C044%^A gentle breeze carries the scent of sea salt and seafoam.");
	set_listen("default", "%^RESET%^%^C039%^The sound of waves crashing against the shore never fades.");
	
	set_items(([
		({"ocean", "sea"}) : "%^RESET%^%^C039%^Gazing out to the ocean from the beach, one can see the crystal-clear waters shimmering in the sunlight, with waves gently lapping towards the shore. On the horizon there is the occasional glimpse of dolphins or other sea creatures frolicking in the distance.",
		({"flowers", "red flowers"}) : "%^RESET%^%^C196%^The strange red flowers are shaped like small, delicate bells, with a cluster of thin petals forming the bell and a long, slender stem reaching out from the center. Despite their delicate appearance, they seemed to be hardy and resilient, growing straight out of the sand with no visible source nutrients.",
		({"black trees", "black forest"}) : "%^RESET%^%^C242%^The trees in the garden are tall and slender, with black bark that appears almost glossy in certain lighting. They have many branches that are thin and stretch outwards, creating a canopy of sorts above the garden. The leaves of the trees are also black, but they have a slight sheen to them, almost like they are made of some kind of exotic material. The leaves rustle in the wind, and when they fall, they flutter to the ground like black snowflakes. Despite their dark appearance, the trees seem to have a certain elegance and mystique to them, adding to the overall enchanting atmosphere of the garden.",
		({"cobblestone", "road"}) : "%^RESET%^%^C072%^The cobblestone road shimmers with a very faint glimmer that gives it an otherworldly glow. Upon closer inspection, intricate designs are etched into the stones, resembling delicate patterns of leaves, vines, and other natural motifs. The stones themselves seem to shift and change colours slightly as they are traversed.",
		({"shack"}) : "The shack is a simple and rustic structure made of black wood, with a sloping roof that is covered in thick thatch. It appears to be a small, single-story building with a narrow, wooden door that faces the dock. A small window with shutters is situated on the front wall of the shack, offering a glimpse inside.",
		({"dock"}) : "The dock is made of sturdy and black wooden planks. It is built on the shore and extends out into the calm waters of the sea. The planks are smooth in places and look to be in good repair. The dock is wide enough to accommodate a few small boats, which would be tied up to the moorings along its sides. At the end of the dock, there is a small platform where passengers can disembark from the boats. The dock is flanked by a few lanterns that provide a soft, warm and purple glow at night.",
	]));

	set_exits(([
		"north" : "/d/player_houses/antoinette/rooms/beach1",
		"east" : "/d/player_houses/antoinette/rooms/forest1",
	]));	
}