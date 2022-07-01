
#include <std.h>
#include "../../graez.h"

inherit STORAGE"haven.c";



void create(){
   ::create();

set_exits(([
"north" : HAVEN"7",
"east" : HAVEN"20",
"south" : HAVEN"5",

]));

}

