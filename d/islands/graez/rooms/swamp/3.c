
#include <std.h>
#include "../../graez.h"

inherit STORAGE"swamp.c";



void create(){
   ::create();

set_exits(([

"west" : SWAM"1",
"east" : SWAM"6",



]));

}

