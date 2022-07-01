
#include <std.h>
#include "../../graez.h"

inherit STORAGE"scarred_battlefield.c";

void create() {
    ::create();

set_exits(([

"northwest" : ROOMS"52",
"northeast" : ROOMS"63",
"southwest" : ROOMS"61",
"southeast" : ROOMS"72",


]));


}

