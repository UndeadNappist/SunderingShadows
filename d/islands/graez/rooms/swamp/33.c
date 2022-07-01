
#include <std.h>
#include "../../graez.h"

inherit STORAGE"swamp.c";



void create(){
   ::create();

set_exits(([

"east" : SWAM"34",
"southeast" : SWAM"32",

]));

}

