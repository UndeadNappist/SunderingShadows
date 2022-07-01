
#include <std.h>
#include "../../graez.h"

inherit STORAGE"heavy_forest.c";

void create() {
    ::create();

set_exits(([

"north" : FOREST"15",
"west" : FOREST"17",

]));

}

