
#include <std.h>
#include "../../graez.h"

inherit STORAGE"scrubland.c";

void create() {
    ::create();

set_exits(([

"northwest" : ROOMS"38",
"northeast" : ROOMS"49",
"southwest" : ROOMS"47",
"southeast" : ROOMS"58",


]));


}

