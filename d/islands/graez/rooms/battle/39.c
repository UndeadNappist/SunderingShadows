
#include <std.h>
#include "../../graez.h"

inherit STORAGE"desert.c";

void create() {
    ::create();

set_exits(([

"northwest" : ROOMS"29",
"northeast" : ROOMS"40",
"southwest" : ROOMS"38",
"southeast" : ROOMS"49",


]));


}

