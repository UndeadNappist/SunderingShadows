
#include <std.h>
#include "../../graez.h"

inherit STORAGE"scrubland.c";

void create() {
    ::create();

set_exits(([

"northwest" : ROOMS"72",
"northeast" : ROOMS"83",
"southwest" : ROOMS"81",


]));


}

