
#include <std.h>
#include "../../graez.h"

inherit STORAGE"beforewall.c";

void create() {
    ::create();

set_exits(([

"northwest" : ROOMS"12",
"northeast" : ROOMS"23",
"southwest" : ROOMS"21",
"southeast" : ROOMS"32",


]));


}

