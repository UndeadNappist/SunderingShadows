#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("AdvancedTraining");
    feat_name("aura of confidence");
    feat_prereq("Fighter L21, Advanced Training Feat");
    feat_desc("Through sheer grit the warrior can inspire her allies to push through their deepest fears. Party members of the fighter will gain a 50% chance to resist fear effects.");
    permanent(1);
    set_required_for(({}));
}

int prerequisites(object ob) 
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("fighter") < 21) {
       dest_effect();
       return 0;
    }
   
    if(!FEATS_D->has_feat(ob,"advanced training")) {
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

void permanent_effects(object ob) {
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void reverse_permanent_effects(object ob) {
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void dest_effect() {
    ::dest_effect();
    remove_feat(TO);
    return;
}

