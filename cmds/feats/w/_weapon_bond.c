#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

void create()
{
    ::create();
    set_author("wedex");
    feat_type("permanent");
    feat_category("DivineBond");
    feat_name("weapon bond");
    feat_classes("paladin");
    feat_desc("The paladin can expend a point from the grace pool to grant enhancement bonuses or properties to a wielded weapon. The paladin has the following properties available: flaming, flaming burst, frost, icy burst, holy, unholy, axiomatic, anarchic. The enhancement bonus is 1 at 5th and one additional point for every 6 additional levels. The enhancement will last for 3 minutes, plus a further 3 minutes for every 5 paladin levels.\n\n%^BOLD%^N.B.%^RESET%^ This is a divine feat, use <feats divinebond weapon bond> to gain the feat.\nSee also : enhance, enhancements");
    permanent(1);
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (ob->query_class_level("paladin") < 5) {
        dest_effect();
        return 0;
    }
    //Tlaloc is testing if this causes any problems to remove
    /*
    if (FEATS_D->has_feat(ob, "armor bond")) {
        dest_effect();
        return 0;
    }
    */
    return ::prerequisites(ob);
}

void execute_feat()
{
    ::execute_feat();
    dest_effect();
    return;
}

void permanent_effects(object ob)
{
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void reverse_permanent_effects(object ob)
{
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}