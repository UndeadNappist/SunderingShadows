
#include <std.h>
#include "../../graez.h"

inherit STORAGE"scrubland.c";

void create() {
    ::create();

set_exits(([

"northwest" : ROOMS"28",
"northeast" : ROOMS"39",
"southwest" : ROOMS"37",
"southeast" : ROOMS"48",


]));


}

