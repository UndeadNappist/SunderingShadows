
#include <std.h>
#include "../../graez.h"

inherit STORAGE"heavy_forest.c";

void create() {
    ::create();

set_exits(([

"east" : FOREST"12",
"south" : FOREST"11",

]));

}

