
#include <std.h>
#include "../../graez.h"

inherit STORAGE"haven.c";



void create(){
   ::create();

set_exits(([
"west" : HAVEN"12",
"south" : HAVEN"28",
"east" : HAVEN"14",



]));

}

