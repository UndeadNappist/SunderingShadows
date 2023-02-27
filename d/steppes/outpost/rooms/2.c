

#include <std.h>
#include "../outpost.h"

inherit STORAGE"steppes.c";


void create() {
    ::create();

set_exits(([
"east" : ROOMS"3",
"southwest" : ROOMS"1",

]));

}

