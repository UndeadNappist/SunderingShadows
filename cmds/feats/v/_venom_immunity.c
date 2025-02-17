#include <std.h>
#include <daemons.h>
inherit FEAT;

int help();

void create() {
    ::create();
    feat_type("permanent");
    feat_category("WildernessLore");
    feat_name("venom immunity");
    feat_prereq("Druid L9");
    feat_desc("A character with this feat gains an innate immunity to poisons.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob) {
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("druid") < 9) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
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

void execute_feat() {
    ::execute_feat();
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    remove_feat(TO);
    return;
}

