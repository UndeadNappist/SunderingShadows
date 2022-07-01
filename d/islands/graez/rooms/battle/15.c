
#include <std.h>
#include "../../graez.h"

inherit STORAGE"scarred_battlefield.c";

void create() {
    ::create();

set_exits(([

"northwest" : ROOMS"5",
"southeast" : ROOMS"25",
"southwest" : ROOMS"14",
"northeast" : ROOMS"16", 

]));


}

