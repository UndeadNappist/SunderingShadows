#include <std.h>
#include "../puppet.h"

inherit STORAGE"passageway.c";



void create(){
   ::create();


set_exits(([

"north" : ROOMS"2",

]));

}

