
#include <std.h>
#include "../../graez.h"

inherit STORAGE"desert.c";

void create() {
    ::create();

set_exits(([

"northwest" : ROOMS"69",
"northeast" : ROOMS"80",
"southwest" : ROOMS"78",
"southeast" : ROOMS"89",


]));


}

