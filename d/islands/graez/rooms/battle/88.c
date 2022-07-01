
#include <std.h>
#include "../../graez.h"

inherit STORAGE"desert.c";

void create() {
    ::create();

set_exits(([

"northwest" : ROOMS"78",
"northeast" : ROOMS"89",
"southwest" : ROOMS"87",


]));


}

