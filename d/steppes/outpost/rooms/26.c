

#include <std.h>
#include "../outpost.h"

inherit STORAGE"roads.c";


void create() {
    ::create();

set_exits(([
"west" : ROOMS"5",
"east" : ROOMS"31",
"south" : ROOMS"29",
"north" : ROOMS"27",

]));

}

