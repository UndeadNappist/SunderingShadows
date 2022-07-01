
#include <std.h>
#include "../../graez.h"

inherit CORE;

void create() {
    ::create();

set_exits(([

"northwest" : ROOMS"63",
"northeast" : ROOMS"74",
"southwest" : ROOMS"72",
"southeast" : ROOMS"83",


]));


}

