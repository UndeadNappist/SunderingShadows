
#include <std.h>
#include "../../graez.h"

inherit STORAGE"swamp.c";



void create(){
   ::create();

set_exits(([

"northeast" : SWAM"10",
"south" : SWAM"4",


]));

}

