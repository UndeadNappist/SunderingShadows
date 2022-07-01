
#include <std.h>
#include "../../graez.h"

inherit STORAGE"desert.c";

void create() {
    ::create();

set_exits(([

"northwest" : ROOMS"67",
"northeast" : ROOMS"78",
"southwest" : ROOMS"76",
"southeast" : ROOMS"87",


]));


}

