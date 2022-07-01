
#include <std.h>
#include "../../graez.h"

inherit STORAGE"heavy_forest.c";

void create() {
    ::create();

set_exits(([

"east" : FOREST"15",
"west" : FOREST"19",
"south" : FOREST"17",

]));

}

