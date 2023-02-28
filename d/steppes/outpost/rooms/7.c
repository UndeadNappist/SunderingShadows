

#include <std.h>
#include "../outpost.h"

inherit STORAGE"walls.c";


void create() {
    ::create();

set_exits(([
"northeast" : ROOMS"8",
"southwest" : ROOMS"4",


]));

}

