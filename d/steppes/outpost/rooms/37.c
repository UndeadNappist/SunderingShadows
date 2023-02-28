

#include <std.h>
#include "../outpost.h"

inherit STORAGE"lot.c";


void create() {
    ::create();

set_exits(([
"north" : ROOMS"34",
"south" : ROOMS"38",

]));

}

