
#include <std.h>
#include "../../graez.h"

inherit STORAGE"desert.c";

void create() {
    ::create();

set_exits(([

"northwest" : ROOMS"60",
"southeast" : ROOMS"80",
"southwest" : ROOMS"69",


]));


}

