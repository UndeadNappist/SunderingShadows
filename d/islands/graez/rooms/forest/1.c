
#include <std.h>
#include "../../graez.h"

inherit STORAGE"heavy_forest.c";

void create() {
    ::create();

set_exits(([

"southeast" : FOREST"2",


]));

}

