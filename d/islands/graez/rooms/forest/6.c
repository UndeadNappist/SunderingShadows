
#include <std.h>
#include "../../graez.h"

inherit STORAGE"heavy_forest.c";

void create() {
    ::create();

set_exits(([

"north" : FOREST"5",
"east" : FOREST"26",
"southeast" : FOREST"7",

]));

}

