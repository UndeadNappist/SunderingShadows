
#include <std.h>
#include "../../graez.h"

inherit STORAGE"mountain.c";



void create(){
   ::create();



set_exits(([
"south" : MOUNT"3",
"northeast" : MOUNT"5",

]));

}

