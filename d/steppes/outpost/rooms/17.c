

#include <std.h>
#include "../outpost.h"

inherit STORAGE"roads.c";


void create() {
    ::create();

set_exits(([
"west" : ROOMS"34",
"east" : ROOMS"14",
"south" : ROOMS"40",
"north" : ROOMS"39",

]));

}

