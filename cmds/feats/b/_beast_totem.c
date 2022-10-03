#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("RagePower");
    feat_name("beast totem");
    feat_prereq("Barbarian");
    feat_desc("While raging, the barbarian gains two claw attacks that automatically happen, periodically. These claw attacks each do 1d6 + STR modifier in damage. This feat is mutually exclusive with other totem rage powers.");
    permanent(1);
}

int allow_shifted()
{
    return 1;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (!ob->is_class("barbarian")) {
        dest_effect();
        return 0;
    }
    
    if(FEATS_D->has_feat(ob, "moon totem") || 
    FEATS_D->has_feat(ob, "air totem") ||
    FEATS_D->has_feat(ob, "celestial totem") ||
    FEATS_D->has_feat(ob, "spire totem") ||
    FEATS_D->has_feat(ob, "daemon totem") ||
    FEATS_D->has_feat(ob, "ancestor totem") ||
    FEATS_D->has_feat(ob, "spirit totem"))
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
