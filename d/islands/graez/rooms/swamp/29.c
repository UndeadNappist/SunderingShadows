
#include <std.h>
#include "../../graez.h"

inherit STORAGE"swamp.c";



void create(){
   ::create();

set_exits(([

"northwest" : SWAM"31",
"northeast" : SWAM"30",

]));

}

