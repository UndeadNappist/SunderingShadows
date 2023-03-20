/*
  _druid_circle.c

  Allows the druid to select or change their Circle.

  -- Tlaloc -- 
*/

#include <std.h>
#include <daemons.h>
#include <dirs.h>

#define DELAY 259200

inherit FEAT;

string *valid_choices = ({ "claw", "winter", "wildfire", "pestilence", "wild growth" });

void create()
{
    ::create();
    set_author("tlaloc");
    feat_type("instant");
    feat_category("WildernessLore");
    feat_name("druid circle");
    feat_prereq("Druid L1");
    feat_syntax("druid_circle [CIRCLE]");
    feat_desc("This feat allows the druid to select a druid circle, which grants extra spells based on the circle chosen. You can change your druid circle once every three weeks.

%^BOLD%^You can select from the following druid circles:

Claw
Wild Growth
Pestilence
Wildfire
Winter%^RESET%^

To start selection process type <druid_circle [CIRCLE]>.

%^RED%^%^BOLD%^See also :%^RESET%^ circle of the claw, circle of pestilence, circle of winter, circle of wildfire, circle of wild growth");
    allow_tripped(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) return 0;
    if(ob->query_class_level("druid") < 1)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_druid_circle(string str)
{
    object feat;

    if(!objectp(this_player()))
        return 0;

    feat = new(base_name(this_object()));
    feat->setup_feat(this_player(), str);

    return 1;
}

int execute_feat()
{
    ::execute_feat();

    if(!arg)
    {
        if(!strlen(this_player()->query("druid circle")))
            write("You have no druid circle chosen");
        else
            write("%^BOLD%^You current druid circle is: %^RESET%^RED%^" + this_player()->query("druid circle"));
        return 1;
    }

    if(this_player()->cooldown("druid circle change"))
    {
        write("%^BOLD%^You may only change your druid circle once every three weeks.");
        return 1;
    }

    if(member_array(arg, valid_choices) < 0)
    {
        write("%^BOLD%^Valid choices are : %^RESET%^RED%^" + implode(valid_choices, ", "));
        return 1;
    }

    write("You have selected the %^CYAN%^ " + arg + "%^RESET%^ druid circle. Type <yes> to confirm. Anything else will abort.");
    input_to("confirm_selection", 0);

    return 1;
}

void confirm_selection(string str)
{
    if (str != "yes") {
        tell_object(this_player(), "Aborting...");
        return;
    }

    write("%^BOLD%^You declare your druid circle as : %^CYAN%^" + arg + ".");
    this_player()->set("druid circle",arg);
    this_player()->add_cooldown("druid circle change", DELAY);
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
