
#include <std.h>
#include "../../graez.h"

inherit STORAGE"light_forest.c";

void create() {
    ::create();

set_exits(([

"northwest" : ROOMS"6",
"southeast" : ROOMS"26",
"southwest" : ROOMS"15",
"northeast" : ROOMS"17", 

]));


}

