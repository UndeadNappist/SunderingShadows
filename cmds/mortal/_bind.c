#include <std.h>

int cmd_bind(string str)
{
    object binder, bindee, environment, rope;
    string race, action;

    binder = this_player();
    environment = environment(binder);

    if (binder->query_bound())
    {
        binder->send_paralyzed_message("info", binder);
        return 1;
    }

    if (!str)
        tell_object(binder, "Bind who?\n");

    bindee = present(str, environment);

    if (!objectp(bindee))
        tell_object(binder, "That is not here.\n");

    if (!binder->ok_to_kill(bindee))
        tell_object(binder, "Supernatural forces prevent you from doing that.\n");

    if (!userp(bindee) && !bindee->is_townsman())
        tell_object(binder, "Binding can only be done in RP situations.\n");

    if (sizeof(binder->query_attackers()))
        tell_object(binder, "You're too busy right now.\n");

    if (!rope = present("rope", binder))
    {
        if (!binder = present("rope", environment))
        {
            tell_object(binder, "You need rope to bind someone.\n");
        }
    }

    if (!bindee->query_unconscious() && !bindee->query_property("submit_bind", binder) && !bindee->query_bound())
        return notify_fail(capitalize(str) + " is gonna fight that ya know.\n");

    if (bindee->query_bound()) {
/* allowing them to rebind, but still require fresh rope else the person might escape while the others were loosened (which I didn't want to take time to code)  *Styx*  11/22/02
   return notify_fail(str+" is already bound.\n");
*/
        action = "more rope to tighten the bindings on";
    }  else {
        action = "some rope to bind";
    }
    rope->remove();
    tell_room(environment, "%^BOLD%^" + binder->query_cap_name() + " uses " + action + " " + binder->query_cap_name() + "'s hands and feet.", ({ binder, bindee }));
    tell_object(binder, "%^BOLD%^You use " + action + " " + bindee->query_cap_name() + "'s hands and feet.");
/*This should change it so that poses are automatically removed when someone is bound so we no longer have strange poses of people standing while bound.  ~Circe~ 10/3/03  Last change was Sept. 17, 2003
 */
    if (bindee->query_property("posed"))
    {
        bindee->remove_property("posed");

        if (!bindee->query_unconscious())
            tell_object(bindee, "Your pose has been cleared.");
    }

    if (!bindee->query_unconscious())
        tell_object(bindee, "%^BOLD%^" + binder->query_cap_name() + " uses " + action + " your hands and feet. You might want to <struggle>.");

    if (bindee->query_property("submit_bind", binder))
        bindee->remove_property("submit_bind", binder);

//   who->set_bound( (int)TP->query_stats("wisdom") * (int)TP->query_stats("strength") * (random(5) +1));     
    if (bindee->query_bound())
    {
       bindee->set_bound(bindee->query_bound() + ((int)binder->query_skill("rope use") * 50));
       binder->set_paralyzed(2, "You are busy binding " + bindee->query_cap_name());
       return 1;
    }
    else
    {
        bindee->set_bound(1000 + ((int)binder->query_skill("rope use") * 50));
        binder->set_paralyzed(5, "You are busy binding " + bindee->query_cap_name());
        return 1;
    }
}

// updated help file to mention being able to tighten just by having rope and binding again.
// last change was 5/03 *Styx* 9/17/03

int help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

bind - use ropes on someone

%^CYAN%^SYNOPSIS%^RESET%^

bind %^ORANGE%^%^ULINE%^TARGET%^RESET%^

%^CYAN%^SYNOPSIS%^RESET%^

This command will bind %^ORANGE%^%^ULINE%^TARGET%^RESET%^ with rope in your inventory. You can then %^ORANGE%^<drag>%^RESET%^ them.

The %^ORANGE%^%^ULINE%^TARGET%^RESET%^ must be either unconcious or use %^ORANGE%^<submit>%^RESET%^ to submit to your binding.

Binding will prevent them from running, but a bound person can %^ORANGE%^<struggle>%^RESET%^ to get free.

%^CYAN%^SEE ALSO%^RESET%^

unbind, submit, gag, ungag, struggle, drag, drop, strip, blindfold, unblindfold, pkilling, rules, rope use
"
        );
    return 1;
}
