
#include <std.h>
#include "../../graez.h"

inherit STORAGE"mountain.c";



void create(){
   ::create();

set_exits(([
"southwest" : MOUNT"10",
"east" : MOUNT"12",

]));

}

