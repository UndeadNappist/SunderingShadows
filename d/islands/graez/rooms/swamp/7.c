
#include <std.h>
#include "../../graez.h"

inherit STORAGE"swamp.c";



void create(){
   ::create();

set_exits(([

"south" : SWAM"6",
"west" : SWAM"2",
"east" : SWAM"13",


]));

}

