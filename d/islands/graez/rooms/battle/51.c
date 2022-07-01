
#include <std.h>
#include "../../graez.h"

inherit STORAGE"scarred_battlefield.c";

void create() {
    ::create();

set_exits(([

"northwest" : ROOMS"41",
"northeast" : ROOMS"52",
"southeast" : ROOMS"61",


]));


}

