#include "../tomb.h"

inherit TOMBSTR;

void create(){
    ::create();
    set_exits(([
                   "west":ROOMS+"/fountain2",
                   ]));
    set_heart_beat(0);
}
