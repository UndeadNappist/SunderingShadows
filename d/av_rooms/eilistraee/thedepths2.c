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
        set_short("A Strangely Serene Sea Bed");
        set_long("All around you, the ocean presses down upon you with the intensity of eternity, relentless and unyielding tidal forces that promise nothing but claustrophobic death unknown by man or beast. You know that you will die here, but even so, there is a strange scene before you that arrests your attention and draws the eye.  The sea bed is calm, clear and unmarked by detritus, a strange thing in and of itself, but curiously, though they fade with the lapping of the waves, there are signs of foot traffic. Off to one side, the carcass of a galleon rots, its side open to the elements and its sails drifting pathetically with the ebb and flow of the ocean depths. Below you stands a statue: Gigantic and with a strange alien majesty that is unseen in the world above, an enormity of stone carved and embellished into the likeness of a creature that simply can't be possible, a thing of nightmare and dreams. A being of such a nature that its very existance should be unheard of. Around it, fish swim lazily, their forms brilliant against another impossibility, rank upon rank of metal and crystaline figures that remain unmoved by the passage of time.  Amidst their number, nets of humanoid corpses float, only their weight and emaciated solidity stopping them from drifting. It is strange though, for all here offers a vision of worship, though to what remains in question.\n");
        set_taste("default","You taste only the brine of salt water.");
        set_listen("default","You hear nothing but the thundering of the waves against your ear drums.");
		    set_search("default","You find water.");
}