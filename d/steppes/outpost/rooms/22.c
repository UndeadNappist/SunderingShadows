

#include <std.h>
#include "../outpost.h"

inherit STORAGE"walls.c";


void create() {
    ::create();

set_exits(([
"northwest" : ROOMS"23",
"east" : ROOMS"20",



]));

}

