
#include <std.h>
#include "../../graez.h"

inherit STORAGE"swamp.c";



void create(){
   ::create();

set_exits(([

"southwest" : SWAM"29",
"north" : SWAM"35",

]));

}

