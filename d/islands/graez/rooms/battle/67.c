
#include <std.h>
#include "../../graez.h"

inherit STORAGE"scrubland.c";

void create() {
    ::create();

set_exits(([

"northwest" : ROOMS"57",
"northeast" : ROOMS"68",
"southwest" : ROOMS"66",
"southeast" : ROOMS"77",


]));


}

