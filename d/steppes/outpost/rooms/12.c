

#include <std.h>
#include "../outpost.h"

inherit STORAGE"walls.c";


void create() {
    ::create();

set_exits(([
"northwest" : ROOMS"11",
"southeast" : ROOMS"13",


]));

}

