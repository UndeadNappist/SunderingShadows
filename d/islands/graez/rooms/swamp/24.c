
#include <std.h>
#include "../../graez.h"

inherit STORAGE"swamp.c";



void create(){
   ::create();

set_exits(([

"northwest" : SWAM"22",
"east" : SWAM"25",
"west" : SWAM"23",


]));

}

