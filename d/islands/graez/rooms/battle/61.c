
#include <std.h>
#include "../../graez.h"

inherit STORAGE"scarred_battlefield.c";

void create() {
    ::create();

set_exits(([

"northwest" : ROOMS"51",
"northeast" : ROOMS"62",
"southeast" : ROOMS"71",


]));


}

