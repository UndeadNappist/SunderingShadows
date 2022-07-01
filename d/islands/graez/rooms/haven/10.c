
#include <std.h>
#include "../../graez.h"

inherit STORAGE"haven.c";



void create(){
   ::create();

set_exits(([
"southwest" : HAVEN"9",
"east" : HAVEN"11",



]));

}

