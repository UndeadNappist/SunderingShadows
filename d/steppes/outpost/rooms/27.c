

#include <std.h>
#include "../outpost.h"

inherit STORAGE"lot.c";


void create() {
    ::create();

set_exits(([
"north" : ROOMS"28",
"south" : ROOMS"26",

]));

}

