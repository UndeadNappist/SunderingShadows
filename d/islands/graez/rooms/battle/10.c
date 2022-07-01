
#include <std.h>
#include "../../graez.h"

inherit STORAGE"light_forest.c";

void create() {
    ::create();



set_exits(([


"southeast" : ROOMS"20",
"southwest" : ROOMS"9",

]));


}

