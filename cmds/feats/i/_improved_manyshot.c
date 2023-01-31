// Chernobog (1/31/23)
// Improved Manyshot

#include <std.h>
#include <daemons.h>

inherit FEAT;


void create(){
    ::create();
    feat_type("permanent");
    feat_category("RangedCombat");
    feat_name("improved manyshot");
    feat_prereq("Manyshot");
    feat_desc("With this feat you are able avoid being tripped on a missed manyshot attack.");
    permanent(1);
}

int allow_shifted(){
    return 1;
}

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if(!FEATS_D->has_feat(ob, "manyshot")){
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

void execute_feat(){
    ::execute_feat();
    dest_effect();
}

void permanent_effects(object ob){
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void reverse_permanent_effects(object ob){
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void dest_effect(){
    ::dest_effect();
    remove_feat(this_object());
    return;
}

