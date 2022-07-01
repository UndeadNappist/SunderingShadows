


#include <std.h>
#include "../../graez.h"

inherit STORAGE"heavy_forest.c";

void create() {
    ::create();

set_exits(([

"north" : FOREST"27",
"southeast" : FOREST"8",
"west" : FOREST"6",

]));

}

