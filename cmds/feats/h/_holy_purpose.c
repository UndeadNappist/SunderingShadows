#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("RadiantServant");
    feat_name("holy purpose");
    feat_prereq("Radiant Servant L7");
    feat_desc("The Radiant Servant is here, above all, to serve a holy purpose: to bring light and life to a world filled with darkness and sorrow. To that end, they are granted powerful spells to aid in their fight. The Radiant Servant gains: heal, mass heal, repel the profane, cleansing flames, spray of shooting stars, gale of life, celestial brilliance, and eye of the sun as innate spells.");
    permanent(1);
    set_required_for(({}));
}

int prerequisites(object ob)
{
    if (!objectp(ob))
    {
        return 0;
    }

    if ((int)ob->query_class_level("radiant_servant") < 7)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

void execute_feat()
{
    ::execute_feat();
    dest_effect();
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