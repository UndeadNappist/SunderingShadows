#include <std.h>
#include "../../serakii.h"

inherit STORAGE"corrupted_forest.c";

void create(){
   ::create();

set_exits(([
"southwest" : FOR"b6",
"east" : FOR"b24",

]));

}
