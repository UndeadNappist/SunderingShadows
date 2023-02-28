

#include <std.h>
#include "../outpost.h"

inherit STORAGE"roads.c";


void create() {
    ::create();

set_exits(([
"west" : ROOMS"3",
"east" : ROOMS"26",
"south" : ROOMS"25",
"north" : ROOMS"24",

]));

}

