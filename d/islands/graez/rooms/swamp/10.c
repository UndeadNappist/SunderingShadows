
#include <std.h>
#include "../../graez.h"

inherit STORAGE"swamp.c";



void create(){
   ::create();

set_exits(([

"north" : SWAM"42",
"southwest" : SWAM"4",
"east" : SWAM"17",


]));

}

