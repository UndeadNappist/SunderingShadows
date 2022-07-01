
#include <std.h>
#include "../../graez.h"

inherit STORAGE"swamp.c";



void create(){
   ::create();

set_exits(([

"south" : SWAM"28",
"southwest" : SWAM"26",


]));

}

