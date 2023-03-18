//this is a room where stuff ends up after something errors out
//it also cleans itself so some things go here to be removed.
#include <config.h>
#include <std.h>
#include <security.h>

#define PRISON_D ("/adm/daemon/prison_d")
#define JAIL ("/d/shadowgate/jail")
void check_my_inventory();
void clean_inventory();
inherit "/std/room";

void create()
{
    ::create();
    set("short", "The void");
    set("long",
        "You're in the void, stuck here for reasons unknown.\n"
        "To get out, simply %^WHITE%^<break free>%^WHITE%^.");
    set_property("light", 1);
    call_out("check_my_inventory", 10);
    set_property("no teleport", 1);
    set_property("indoors", 1);
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    seteuid(UID_ROOT);
    set_no_clean(1);
    return;
}

init()
{
    ::init();
    
    if(!userp(this_player()))
        return;
    
    add_action("break_free", "break");
}

int break_free(string str)
{
    if (!str)
        return 0;

    if (str != "free")
        return 0;

    this_player()->move_player("/d/shadow/room/forest/road30");

    return 1;
}

int handle_player_object(object ob)
{
    object me = this_object();
    string start;

    if (!objectp(me))
        return 0;

    if (!objectp(ob) || !userp(ob))
        return 0;

    if (PRISON_D->is_imprisoned(ob->query_true_name()))
    {
        ob->move_player(JAIL);
        return 1;
    }

    ob->set_property("voided", 1);

    if (stringp(start == ob->getenv("start")))
    {
        ob->move_player(start);
        return 1;
    }

    ob->move_player("/d/shadow/room/forest/road30");
    return 1;
}

int clean_inventory()
{
    object *players, *targets;
    object me = this_object(), ob;
    object trash;

    if (!objectp(me))
        return 0;
    
    players = filter_array(all_inventory(me), (:userp($1):));

    if (sizeof(players))
    {
        foreach(ob in players)
            handle_player_object(ob);
    }
    
    trash = load_object("/d/shadowgate/trash");
    targets = deep_inventory(me);
    
    if(sizeof(targets) > 100)
        targets = targets[0..99];
    
    foreach(ob in targets)
    {
        if(eval_cost() < 25000)
            continue;
                
        if (!objectp(ob))
            continue;
        
        if (userp(ob))
        {
            handle_player_object(ob);
            continue;
        }
        
        if (objectp(trash))
        {
            ob->move(trash);
        }
        else
        {
            if (catch(ob->remove()))
                destruct(ob);
        }   
    }
    
    sizeof(targets) && objectp(trash) && destruct(trash);
    
    return 1;
}

int check_my_inventory()
{
    object me = this_object();
    mixed error;
    
    if (!objectp(me))
        return 0;

    if (clonep(me))
    {
        clean_inventory();
        reclaim_objects();
        me->remove();
        return 1;
    }

    error = catch(clean_inventory());
    reclaim_objects();
    call_out("check_my_inventory", 10);
    return 1;
}
