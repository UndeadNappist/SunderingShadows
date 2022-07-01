
#include <std.h>
#include "../../graez.h"

inherit STORAGE"swamp.c";



void create(){
   ::create();

set_exits(([

"southwest" : SWAM"19",
"north" : SWAM"21",



]));

}

