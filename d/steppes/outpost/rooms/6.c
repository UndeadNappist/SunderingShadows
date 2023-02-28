

#include <std.h>
#include "../outpost.h"

inherit STORAGE"walls.c";


void create() {
    ::create();

set_exits(([
"north" : ROOMS"3",
"southeast" : ROOMS"23",



]));

}

