
#include <std.h>
#include "../../graez.h"

inherit STORAGE"haven.c";



void create(){
   ::create();

set_exits(([
"south" : HAVEN"1",
"northeast" : HAVEN"16",
"west" : HAVEN"18",

]));

}

