
#include <std.h>
#include "../../graez.h"

inherit STORAGE"swamp.c";



void create(){
   ::create();

set_exits(([

"west" : SWAM"12",
"northwest" : SWAM"21",
"northeast" : SWAM"20",



]));

}

