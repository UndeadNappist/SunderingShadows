
#include <std.h>
#include "../../graez.h"

inherit STORAGE"scrubland.c";

void create() {
    ::create();

set_exits(([

"northwest" : ROOMS"37",
"northeast" : ROOMS"48",
"southwest" : ROOMS"46",
"southeast" : ROOMS"57",


]));


}

