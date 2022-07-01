
#include <std.h>
#include "../../graez.h"

inherit STORAGE"desert.c";

void create() {
    ::create();

set_exits(([

"northwest" : ROOMS"40",
"southeast" : ROOMS"60",
"southwest" : ROOMS"49",


]));


}

