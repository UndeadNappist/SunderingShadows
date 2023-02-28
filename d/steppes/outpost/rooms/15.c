

#include <std.h>
#include "../outpost.h"


inherit STORAGE"steppes.c";



void create() {
    ::create();

set_exits(([
"west" : ROOMS"14",
"northeast" : ROOMS"41",


]));

    set_pre_exit_functions(({"northeast"}),({"exit_fun"}));

}


int exit_fun() {
    int damroll;
   tell_object(TP,"\n%^C066%^You step forward, and are hit with an instant of %^C160%^intense pain%^C066%^ and cannot move further.%^CRST%^\n");
    damroll = roll_dice(10, 10) + 10;
    this_player()->add_hp(-damroll);
    return 0;
}   

