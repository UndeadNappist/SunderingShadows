
#include <std.h>
#include "../../graez.h"

inherit STORAGE"swamp.c";



void create(){
   ::create();

set_exits(([

"north" : SWAM"22",
"east" : SWAM"24",


]));

}

