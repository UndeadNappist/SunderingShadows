
#include <std.h>
#include "../puppet.h"

inherit STORAGE"passageway.c";



void create(){
   ::create();


set_exits(([


"southeast" : ROOMS"8",
"north" : ROOMS"10",

]));

}

