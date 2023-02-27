

#include <std.h>
#include "../outpost.h"

inherit STORAGE"lot.c";


void create() {
    ::create();

set_exits(([
"south" : ROOMS"5",


]));

}

