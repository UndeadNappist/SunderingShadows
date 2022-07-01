
#include <std.h>
#include "../../graez.h"

inherit STORAGE"swamp.c";



void create(){
   ::create();

set_exits(([

"north" : SWAM"4",
"northeast" : SWAM"5",
"southwest" : SWAM"1",
"east" : SWAM"7",


]));

}

