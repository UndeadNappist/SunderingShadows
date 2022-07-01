
#include <std.h>
#include "../../graez.h"

inherit STORAGE"desert.c";

void create() {
    ::create();

set_exits(([

"northwest" : ROOMS"19",
"northeast" : ROOMS"30",
"southwest" : ROOMS"28",
"southeast" : ROOMS"39",


]));


}

