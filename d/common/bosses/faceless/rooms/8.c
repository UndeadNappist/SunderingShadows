
#include <std.h>
#include "../puppet.h"

inherit STORAGE"passageway.c";



void create(){
   ::create();


set_exits(([


"southeast" : ROOMS"6",
"northwest" : ROOMS"9",

]));

}

