
#include <std.h>
#include "../../graez.h"

inherit STORAGE"scrubland.c";

void create() {
    ::create();

set_exits(([

"northwest" : ROOMS"47",
"northeast" : ROOMS"58",
"southwest" : ROOMS"56",
"southeast" : ROOMS"67",


]));


}

