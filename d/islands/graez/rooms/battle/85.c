
#include <std.h>
#include "../../graez.h"

inherit STORAGE"scrubland.c";

void create() {
    ::create();

set_exits(([

"northwest" : ROOMS"75",
"northeast" : ROOMS"86",
"southwest" : ROOMS"84",


]));


}

