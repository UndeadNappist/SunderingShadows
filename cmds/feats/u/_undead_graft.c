#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("PaleLord");
    feat_name("undead graft");
    feat_prereq("Pale Lord L1");
    feat_desc("This is the first step of the transformation into a pale lord. A mortal wishing to become one starts so with cutting out and removing most of their own internal organs, mummifying them, infusing them with powerful spells, and placing them back into their own body. Such organs, despite being virtually dead, still serve their functions through entwined spells. This step of the transformation gives the pale lord unprecedented resilience to damage. Negative energy no longer harms them, they gain damage reduction to physical attacks, and gain poison and disease immunity. They also become fully immune to assassin crits and only receive half of the damage from thief stabs and sneak attack damage.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("pale_lord") < 1)
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
