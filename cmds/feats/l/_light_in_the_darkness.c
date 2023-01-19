#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("RadiantServant");
    feat_name("light in the darkness");
    feat_prereq("Radiant servant L1");
    feat_desc("The Radiant Servant is the paragon of all that is the light against the darkness. With this feat, the Radiant Servant gains +2 clevel to healing spells and spells that inflict radiant damage. In addition, the Radiant Servant gains 10% radiant resistance. Finally, the radiant servant can no longer be blinded by rooms being too bright.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }
    if(ob->query_class_level("radiant_servant") < 1)
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
