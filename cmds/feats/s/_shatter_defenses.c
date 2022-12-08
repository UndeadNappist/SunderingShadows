// Chernobog (12/6/22)
// Feat - Shatter Defenses

#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("WeaponMastery");
    feat_name("shatter defenses");
    feat_prereq("Cornugon Smash");
    feat_desc("Your skill with your chosen weapon leaves opponents unable to defend themselves if you strike them while their defenses are already compromised. Any enemy that is shaken, frightened, or panicked will be vulnerable to your attacks.");
    permanent(1);
    set_required_for(({ }));
}

int allow_shifted() { return 1; }

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if(!FEATS_D->has_feat(ob, "cornugon smash")) return 0;
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