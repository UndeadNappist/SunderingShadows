// eqglance, glued together by Spade on 17 Jan. 2023
// Mashed "eq" and "glance" together

#include "move.h"
#include <std.h>
#include <daemons.h>

inherit DAEMON;

int worn_wielded(object ob)
{
    if (!objectp(ob)) return 0;
    if (undefinedp(ob->query_short())) return 0;
    if (!ob->query_worn() && !ob->query_wielded()) return 0;
    return 1;
}

int cmd_eqglance(string args)
{
   string target, target_discriminator;
   object player = this_player();
   object wiz, ob, *items, *exclude = ({});
   string stuff, sub_case, full_message = "";

   set_property("information",1);

    if(player->query_blind())
    {
        return notify_fail("You are blind and cannot see anything.");
    }

    if(!args)
        return 0;

    if (!stringp(args))   // Seems uneccessary
        return 0;

    if((sscanf(args, "%s %d", target, target_discriminator) == 2 && target == "player") || args == "player")
        return notify_fail("You do not notice that here.\n");

    ob = environment(player);

    if (!wizardp(player) && (wiz=present(args, ob)) && wizardp(wiz) && wiz->query_invis())
       return notify_fail("You do not notice that here.\n");

    if(player->light_blind(0))
        return notify_fail(player->light_blind_fail_message(player->light_blind(1)));

    ob = present(args, ob);

    if (!ob)
        return notify_fail("You do not notice that here.\n");

    if ((ob->query_hidden() || (ob->query_magic_hidden() && !player->detecting_invis()) && ob != player))
        return notify_fail("You do not notice that here.\n");

    if (!living(ob))
        return notify_fail("That is not a living thing.\n");

    if(TP->query_ansi())
        full_message += ansi_str((string)ob->query_desc(args));
    else
        full_message += (string)ob->query_desc(args);

    items = all_inventory(ob);
    exclude = filter_array(items, "worn_wielded");
    items -= exclude;
    stuff = ob->describe_item_contents(items);

    if(stuff != "")
    {
        stuff = "   " + stuff;
        stuff = replace_string(stuff, ",", "\n  ");
        stuff = replace_string(stuff, " are here.", "");
        stuff = replace_string(stuff, " is here.", "");
    }

    sub_case = capitalize(ob->query_subjective());

    if (sub_case == "They")
        sub_case = "They are";
    else
        sub_case += " is";

    if(stuff == "")
        full_message += "%^RED%^" + sub_case + " wholly unequipped.\n";
    else
    {
        full_message += "%^BOLD%^%^GREEN%^" + sub_case + " equipped with:%^RESET%^\n";
        full_message += stuff;
    }

    player->more(explode(full_message, "\n"));

    write("");

    return 1;
}

void help() {
    write("
%^CYAN%^NAME%^RESET%^

eqglance - look at someone's gear

%^CYAN%^DESCRIPTION%^RESET%^

This command displays a list of the items that your target is currently using.

%^CYAN%^SEE ALSO%^RESET%^

eq, glance, spy, inventory, limbs, score, money
"
        );
}
