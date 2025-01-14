#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("CryptStalker");
    feat_name("scour the depths");
    feat_prereq("Crypt Stalker L4");
    feat_desc(""
"Stalking like a shadow through the domain of their hated enemies, the Crypt Stalker becomes a master of the earthen depths of the world where the undead call home. The Crypt Stalker gains bonuses in caves as if they had the Caves favored terrain. They also gain Rope Trick, Detect Undead, Greater Invisibility, Disrupting Weapon, Undeath Ward and False Future as innate spells.");
    permanent(1);
    set_required_for(({}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if (!objectp(ob))
    {
        return 0;
    }

    if ((int)ob->query_class_level("crypt_stalker") < 4)
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
