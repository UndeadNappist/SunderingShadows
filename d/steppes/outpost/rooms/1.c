#include <std.h>
#include "../outpost.h"

inherit STORAGE"steppes.c";


void create() {
    ::create();

set_exits(([
"northeast" : ROOMS"2",

]));

}

void reset() {
    ::reset();
    if(!present("archway"))
	new(OBJ"archway2")->move(this_object());
}


