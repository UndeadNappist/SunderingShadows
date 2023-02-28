

#include <std.h>
#include "../outpost.h"

inherit STORAGE"roads.c";


void create() {
    ::create();

set_exits(([
"south" : ROOMS"33",
"north" : ROOMS"9",

]));

}

