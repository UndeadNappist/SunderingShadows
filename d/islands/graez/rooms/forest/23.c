
#include <std.h>
#include "../../graez.h"

inherit STORAGE"heavy_forest.c";

void create() {
    ::create();

set_exits(([

"south" : FOREST"9",
"northeast" : FOREST"20",
"northwest" : FOREST"22",



]));

}

