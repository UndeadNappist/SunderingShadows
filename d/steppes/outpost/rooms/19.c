

#include <std.h>
#include "../outpost.h"

inherit STORAGE"walls.c";


void create() {
    ::create();

set_exits(([
"northeast" : ROOMS"18",
"west" : ROOMS"20",



]));

}

