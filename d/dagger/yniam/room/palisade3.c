// Chernobog (3/15/22)
// Palisade Wall

#include <std.h>
#include "../defs.h"
inherit INH"palisade";

void create(){
    ::create();
    set_exits(([
        "northwest" : ROOMS"outpost_hub",
        "southeast" : ROOMS"road5",
        ]));
}
