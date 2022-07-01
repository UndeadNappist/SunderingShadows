
#include <std.h>
#include "../../graez.h"

inherit STORAGE"swamp.c";



void create(){
   ::create();

set_exits(([

"northeast" : SWAM"38",
"south" : SWAM"40",

]));

}

