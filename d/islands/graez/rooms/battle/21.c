
#include <std.h>
#include "../../graez.h"

inherit STORAGE"citywall.c";

void create() {
    ::create();

set_exits(([

"west" : TOWN"20",
"north" : BATTLE"12",
"northwest" : ROOMS"11",
"northeast" : ROOMS"22",
"southeast" : ROOMS"31",


]));


}

