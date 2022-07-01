
#include <std.h>
#include "../../graez.h"

inherit STORAGE"heavy_forest.c";

void create() {
   ::create();

set_exits(([

"northwest" : FOREST"2",
"south" : FOREST"4",


]));

}

