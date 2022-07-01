
#include <std.h>
#include "../../graez.h"

inherit STORAGE"heavy_forest.c";

void create() {
    ::create();

set_exits(([

"northwest" : FOREST"4",
"northeast" : FOREST"28",
"south" : FOREST"6",

]));

}

