
#include <std.h>
#include "../../graez.h"

inherit STORAGE"scrubland.c";

void create() {
    ::create();

set_exits(([

"northwest" : ROOMS"74",
"northeast" : ROOMS"85",
"southwest" : ROOMS"83",


]));


}

