
#include <std.h>
#include "../../graez.h"

inherit STORAGE"swamp.c";



void create(){
   ::create();

set_exits(([

"southwest" : SWAM"2",
"north" : SWAM"8",
"east" : SWAM"12",


]));

}

