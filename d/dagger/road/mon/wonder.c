#include "/d/dagger/road/short.h"
#include <std.h>
#include <security.h>

#define ROADEND "/d/dagger/road/road2b"
#define TONOVI1 "/d/dagger/tonovi/1path1"
#define TONOVI2 "/d/dagger/tonovi/2path1"
#define TORM "/d/dagger/Torm/road/path1"
#define DALE1 "/d/dagger/Daggerdale/gates/Wgate"
#define DALE2 "/d/dagger/Daggerdale/gates/Ngate"
#define DALE3 "/d/dagger/Daggerdale/gates/Egate"
#define D_MARSH "/d/dagger/marsh/marsh1"
#define KINARO "/d/dagger/kinaro/path1"
#define ELEMENTS "/d/dagger/elements/path/path1"
#define AKETON "/d/dagger/aketon/path/path1"
#define KEEP "/d/dagger/keep/road/road5"
#define SOLAREN "/d/player_houses/solaren/solaren1"
#define STELLA "/d/dagger/road/stella/sroad5"
#define NOGO ({ROADEND, TONOVI1, TONOVI2, TORM, DALE1, DALE2, DALE3, D_MARSH, KINARO, ELEMENTS, AKETON, KEEP, STELLA, SOLAREN})

int okExit(string exit);
inherit MONSTER;

void move_around()
{
    object my_environment, next_environment;
    string *exits, exit, next_room_path;

    if(!this_object())
        return;

    if(!objectp(my_environment = environment(this_object())))
        return;

    my_environment->setupExits();

    if(query_current_attacker())
        return;

    exits = (string *)my_environment->query_exits();

    seteuid(UID_SYSTEM);

    if(sizeof(exits))
    {
        exit = exits[random(sizeof(exits))];

        if (!stringp(next_room_path = my_environment->query_exit(exit)))
            return;

        if (!objectp(next_environment = find_object_or_load(next_room_path)))

        next_environment->init();

        if(okExit(exit))
            command(exit);
    }

    moving = 0;
}

int okExit(string exit){
    string filename;

    if(exit == "temple") return 0;

    filename = environment(this_object())->query_exit(exit);
    if(member_array(filename, NOGO) != -1) return 0;
    return 1;
}
