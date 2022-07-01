
#include <std.h>
#include "../../graez.h"

inherit STORAGE"scrubland.c";

inherit CORE;

void create() {
    ::create();

set_exits(([

"northwest" : ROOMS"76",
"northeast" : ROOMS"87",
"southwest" : ROOMS"85",


]));


}

