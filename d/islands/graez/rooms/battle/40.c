
#include <std.h>
#include "../../graez.h"

inherit STORAGE"desert.c";

void create() {
    ::create();

set_exits(([

"northwest" : ROOMS"30",
"southeast" : ROOMS"50",
"southwest" : ROOMS"39",


]));


}

