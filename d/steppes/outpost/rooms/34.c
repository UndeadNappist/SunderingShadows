

#include <std.h>
#include "../outpost.h"

inherit STORAGE"roads.c";


void create() {
    ::create();

set_exits(([
"west" : ROOMS"31",
"east" : ROOMS"17",
"south" : ROOMS"37",
"north" : ROOMS"35",

]));

}

