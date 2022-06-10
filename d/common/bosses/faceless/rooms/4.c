
#include <std.h>
#include "../puppet.h"

inherit STORAGE"passageway.c";



void create(){
   ::create();


set_exits(([

"south" : ROOMS"3",
"west" : ROOMS"5",

]));

}

