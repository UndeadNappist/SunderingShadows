// Chernobog (3/15/22)
// Interior Yniam Road

#include <std.h>
#include "../defs.h"
inherit INH"road2";

void create(){
    ::create();
    set_long(::query_long()+"%^RESET%^%^CRST%^%^C101%^Workers move about the skeleton of a building here. Piles of wood and stone are scattered about to be used as the structure takes shape.%^CRST%^\n");
    set_exits(([
        "southwest" : "/d/dagger/tonovi/1path1",
        "northeast" : ROOMS"road2",
        ]));
}

void reset(){
    ::reset();
    
    if(!present("ambiance device")) new(OBJ"ambiance")->move(this_object());
}

