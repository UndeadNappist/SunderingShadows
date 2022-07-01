
#include <std.h>
#include "../../graez.h"

inherit STORAGE"desert.c";

void create() {
    ::create();

set_exits(([

"northwest" : ROOMS"10",
"southeast" : ROOMS"30",
"southwest" : ROOMS"19",


]));


}

