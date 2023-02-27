

#include <std.h>
#include "../outpost.h"

inherit STORAGE"walls.c";


void create() {
    ::create();

set_exits(([
"northwest" : ROOMS"6",
"southeast" : ROOMS"22",



]));

}

