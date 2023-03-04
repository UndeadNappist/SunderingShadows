#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("TwoWeapons");
    feat_name("ambidexterity");
    feat_prereq("Base Dexterity 13");
    feat_desc("Ambidexterity allows a character to wield two weapons that are normal size to that character. A human could wield two medium sized weapons or a giant could wield two large sized weapons. Small-sized creatures don't have access to this, as they do not need this feat to properly wield two small weapons.");
    permanent(1);
    set_replaces_feat("weapon finesse");
    set_required_for(({"two weapon fighting","improved two weapon fighting","unassailable parry","whirl"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_base_stats("dexterity") < 13)
    {
        dest_effect();
        return 0;
    }
    
    if(ob->query_size() < 2)
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
