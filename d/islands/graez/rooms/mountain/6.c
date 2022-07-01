
#include <std.h>
#include "../../graez.h"

inherit STORAGE"mountain.c";



void create(){
   ::create();

set_exits(([
"southeast" : MOUNT"5",
"northwest" : MOUNT"8",

]));

}

