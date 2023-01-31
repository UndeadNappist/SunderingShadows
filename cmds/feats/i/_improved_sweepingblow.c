// Chernobog (1/31/23)
// Improved Sweepingblow

#include <std.h>
#include <daemons.h>

inherit FEAT;


void create(){
    ::create();
    feat_type("permanent");
    feat_category("TwoHandedWeapons");
    feat_name("improved sweepingblow");
    feat_prereq("Sweepingblow");
    feat_desc("With this feat you are able avoid being tripped on a missed sweepingblow attack.");
    permanent(1);
}

int allow_shifted(){
    return 1;
}

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if(!FEATS_D->has_feat(ob, "sweepingblow")){
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

