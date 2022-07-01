
#include <std.h>
#include "../../graez.h"

inherit STORAGE"haven.c";



void create(){
   ::create();

set_exits(([
"north" : HAVEN"15",
"southwest" : HAVEN"17",


]));

}

