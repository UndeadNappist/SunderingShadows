#include <std.h>
#include <priest.h>

inherit OBJECT;

void create()
{
    ::create();
    set_name("godsfavor");
    set("id", ({ "remotexoli"}) );
    set_short("");
    set_long("");
    set_property("no animate", 1);
    set_weight(0);
}

void init()
{
    ::init();
    add_action("now", "now");
}

int now(string str)
{
   object player = this_player();
   string where, temple,diety;

   if (!objectp(player))
      return 0;

   diety = player->query_diety();
   if (player->query_diety())
   {
      where = "/d/magic/temples/"+diety;
      temple = "Temple of "+capitalize(player->query_diety());
   }
   else
   {
      tell_object(player, "You need to follow a god to be saved by one.");
      dest_effect();
      return 0;
   }

   if (environment(player)->query_property("no teleport") || environment(player)->query_property("teleport proof")) {
      tell_object(player, "Even "+player->query_diety()+" is unable to save you from here.");
      dest_effect();
      return 0;
   }

   tell_object(player, "You feel the presence of your deity fill the room as you are swept away from danger and brought back to the "+temple+"!");
   tell_room(environment(ETO), "A holy presence fills the room and " + player->query_cap_name() + " disappears from view!", ({player}));
   player->move_player(where);
   dest_effect();
   return 1;
}

int dest_effect()
{
   if (objectp(this_object()))
      return 0;

   this_object()->remove();

   return 1;
}
