
#include <std.h>
#include "../../graez.h"

inherit STORAGE"desert.c";

void create() {
    ::create();

set_exits(([

"northwest" : ROOMS"50",
"southeast" : ROOMS"70",
"southwest" : ROOMS"59",


]));


}

