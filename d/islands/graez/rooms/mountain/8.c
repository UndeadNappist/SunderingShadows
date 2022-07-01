
#include <std.h>
#include "../../graez.h"

inherit STORAGE"mountain.c";



void create(){
   ::create();

set_exits(([
"north" : MOUNT"14",
"southeast" : MOUNT"6",

]));

}

