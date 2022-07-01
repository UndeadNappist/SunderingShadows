
#include <std.h>
#include "../../graez.h"

inherit STORAGE"swamp.c";



void create(){
   ::create();

set_exits(([

"northeast" : SWAM"26",
"west" : SWAM"24",


]));

}

