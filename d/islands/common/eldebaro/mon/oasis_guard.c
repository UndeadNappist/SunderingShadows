#include <std.h>
#include "../area_stuff.h"
inherit GUARDSMAN;

void create()
{
    ::create();
    NPCCRE->build_me(TO);
    add_id(({"oasis guard"}));
    set_nogo(({ELROOMSE+"14"}));
    set_speed(20);
}

int is_eldebaro_monster(object ob)
{
    if(!objectp(ob)) return 0;
    if(ob->id("eldebarocreature")) return 1;
    return 0;
}

void check_my_environment()
{
    object *vics, environment;
    int x;

    if(!objectp(environment = environment(this_object())))
        return;

    vics = filter_array(all_living(environment), "is_eldebaro_monster", this_object());
    vics -= query_attackers();

    if(!sizeof(vics))
        return;

    for(x = 0; x < sizeof(vics); ++x)
        force_me("kill "+vics[x]->query_name());

    return;    
}

void init()
{
    ::init();
    check_my_environment();
    return;
}

void heart_beat()
{
    if(!objectp(this_object()))
        return;

    ::heart_beat();
    check_my_environment();

    return;
}
