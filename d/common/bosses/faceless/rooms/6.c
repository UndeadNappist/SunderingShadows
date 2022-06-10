#include <std.h>
#include "../puppet.h"

inherit STORAGE"banquet.c";



void create(){
   ::create();


set_exits(([


"south" : ROOMS"5",
"northwest" : ROOMS"8",

]));

}

