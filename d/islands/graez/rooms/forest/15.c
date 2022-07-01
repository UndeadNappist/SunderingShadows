
#include <std.h>
#include "../../graez.h"

inherit STORAGE"heavy_forest.c";

void create() {
    ::create();

set_exits(([

"south" : FOREST"16",
"west" : FOREST"18",

]));

}

