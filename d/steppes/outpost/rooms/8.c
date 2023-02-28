

#include <std.h>
#include "../outpost.h"

inherit STORAGE"walls.c";


void create() {
    ::create();

set_exits(([
"east" : ROOMS"9",
"southwest" : ROOMS"7",


]));

}

