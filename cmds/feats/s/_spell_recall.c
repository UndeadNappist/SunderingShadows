#include <std.h>
#include <daemons.h>

inherit FEAT;

void create(){
    ::create();
    set_author("wedex");
    feat_type("instant");
    feat_category("Steel&Magic");
    feat_name("spell recall");
    feat_prereq("Magus L4");
    feat_syntax("spell_recall");
    feat_desc("The next spell you cast will use your arcana pool instead of a spell slot.");
    set_required_for(({ "improved spell recall" }));
}

int allow_shifted() { return 1; }

int prerequisites(object ob){
    if(!objectp(ob)){ return 0; }

    if(ob->query_class_level("magus") < 4){
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_spell_recall(string str){
    object feat;
    if(!objectp(this_player())){ return 0; }
    
    feat = new(base_name(this_object()));
    feat->setup_feat(this_player(), str);
    return 1;
}


void execute_feat(){
    object obj;
    string * elements;
    int i;

    if(!objectp(caster)){
        dest_effect();
        return;
    }

    ::execute_feat();

    if(caster->query_property("spell recall")){
        dest_effect();
        return;
    }
    tell_object(caster, "%^RESET%^%^CRST%^%^C036%^You ready your %^C026%^i%^C027%^n%^C032%^n%^C027%^e%^C026%^r a%^C027%^r%^C032%^c%^C027%^a%^C032%^n%^C026%^a %^RESET%^%^C036%^to fuel your %^C048%^magic%^C036%^.%^CRST%^");
    caster->set_property("spell recall", 1);
    if(userp(caster)){
        caster->gmcp_update_character("resources", ([ "spell_recall": 1 ]));
    }
    return;
}

void dest_effect(){
    if(objectp(caster)){
        tell_object(caster, "%^RESET%^%^CRST%^%^C036%^You release your hold on your %^C026%^i%^C027%^n%^C032%^n%^C027%^e%^C026%^r a%^C027%^r%^C032%^c%^C027%^a%^C032%^n%^C026%^a%^RESET%^%^C036%^.%^CRST%^");
        caster->remove_property("spell recall");
        if(userp(caster)){
            caster->gmcp_update_character("resources", ([ "spell_recall": 0 ]));
        }
    }
    ::dest_effect();
    remove_feat(this_object());
    return;
}

