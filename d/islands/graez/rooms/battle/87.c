#include <std.h>
#include "../../graez.h"

inherit STORAGE"desert.c";

void create() {
    ::create();

set_exits(([

"northwest" : ROOMS"77",
"northeast" : ROOMS"88",
"southwest" : ROOMS"86",


]));


}
