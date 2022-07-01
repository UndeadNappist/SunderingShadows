
#include <std.h>
#include "../../graez.h"

inherit STORAGE"scarred_battlefield.c";

void create() {
    ::create();

set_exits(([

"northwest" : ROOMS"44",
"northeast" : ROOMS"55",
"southwest" : ROOMS"53",
"southeast" : ROOMS"64",


]));


}

