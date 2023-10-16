#include <std.h>
#include <daemons.h>

inherit DAEMON;

int list_allowed_give(string* str);

int cmd_allowed_give(string str)
{
    string* allowed_give, rstr;

    allowed_give = TP->query_allowed_give();

    if (!str) {
        return list_allowed_give(allowed_give);
    }
    if (str == "clear") {
        TP->reset_allowed_give();
        tell_object(TP, "You are no longer allowing anyone to give you anything.");
        return 1;
    }
    str = lower_case(str);
    rstr = TP->realNameVsProfile(str);
    if (member_array(rstr, allowed_give) != -1) {
	    TP->remove_allowed_give(rstr);
        tell_object(TP, str + " is no longer on your allowed give list.");
        return 1;
    }

    TP->add_allowed_give(rstr);
    tell_object(TP, "You are allowing all items given to you from " + str + ".");
    return 1;
}

int list_allowed_give(string* str)
{
    int i;

    tell_object(TP, "%^BOLD%^You are currently allowing the following people to give you things:");
    for (i = 0; i < sizeof(str); i++) {
        tell_object(TP, TP->knownAs(str[i]));
    }
    return 1;
}

void help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

allowed_give - allow someone to give you items

%^CYAN%^SYNOPSIS%^RESET%^

allowed_give [%^ORANGE%^%^ULINE%^TARGET%^RESET%^|clear]

%^CYAN%^DESCRIPTION%^RESET%^

Allows you to accept items from specific players. Without an argument it will display list of people currently allowed to give you things.

%^CYAN%^SEE ALSO%^RESET%^

get, put, palm, steal, drop, show
");
