
#include <std.h>
#include "../../graez.h"

inherit STORAGE"swamp.c";



void create(){
   ::create();

set_exits(([

"east" : SWAM"36",
"south" : SWAM"30",

]));

}

