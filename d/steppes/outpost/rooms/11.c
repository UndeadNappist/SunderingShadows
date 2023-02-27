

#include <std.h>
#include "../outpost.h"


inherit STORAGE"walls.c";



void create() {
    ::create();

set_exits(([
"west" : ROOMS"9",
"southeast" : ROOMS"12",


]));

}

