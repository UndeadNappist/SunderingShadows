
#include <std.h>
#include "../../graez.h"

inherit STORAGE"mountain.c";



void create(){
   ::create();

set_exits(([
"west" : MOUNT"9",
"northeast" : MOUNT"11",

]));

}

