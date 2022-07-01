
#include <std.h>
#include "../../graez.h"

inherit STORAGE"desert.c";

void create() {
    ::create();

set_exits(([

"northwest" : ROOMS"70",
"southeast" : ROOMS"90",
"southwest" : ROOMS"79",


]));


}

