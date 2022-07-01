
#include <std.h>
#include "../../graez.h"

inherit STORAGE"haven.c";



void create(){
   ::create();

set_exits(([
"northeast" : HAVEN"10",
"south" : HAVEN"8",



]));

}

