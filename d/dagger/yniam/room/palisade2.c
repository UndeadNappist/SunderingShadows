// Chernobog (3/15/22)
// Palisade Wall

#include <std.h>
#include "../defs.h"
inherit INH"palisade";

void create(){
    ::create();
    set_exits(([
        "southwest" : ROOMS"outpost_hub",
        "northeast" : ROOMS"road3",
        ]));
}
