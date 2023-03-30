// Chernobog & Titania (2/25/22)
// Wailing Isle - Market Street

#include <std.h>
#include "../defs.h"
inherit INH+"market";

void create(){
    ::create();
    set_exits(([
        "north" : ROOMS"marketsquare",
        "south" : ROOMS"market1",
        ]));
}

