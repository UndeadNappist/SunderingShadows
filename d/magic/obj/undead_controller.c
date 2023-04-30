#include <std.h>

inherit OBJECT;

#define BLACKLIST ({ "buy", "prepare", "cast", "shoot", "heal" })

object caster, *mons = ({ });
//string *undead_list = ({ "skeleton", "graveknight", "skelemage", "skelehorse", "vampire_spawn", "vampire_knight", "animus", });

void save_me(string file){
    return 1;
}

void create(){
    ::create();
    set_name("device");
    set("id", ({ "undead_controller" }));
    set("short", "");
    set("long", "");
    set_weight(0);
}

int move(mixed dest){
    if(ETO && objectp(ETO)){
        if(interactive(ETO)) return 0;
    }
    ::move(dest);
    set_heart_beat(10);
}

set_caster(object ob){
    if(objectp(ob)) caster = ob;
    else remove();
}

object* query_mons(){
    return mons;
}

object query_caster(){
    return caster;
}

void add_monster(object obj){
    if(!objectp(obj)) return;
    mons += ({ obj });
}

int clean_mons(){
    object* temp = ({});
    int i;
    int poolsize;

    for(i = 0; i < sizeof(mons); i++){
        if(!objectp(mons[i])) continue;
        temp += ({ mons[i] });
        if((poolsize + (int)mons[i]->query_property("raised")) > MAX_RAISE){
            mons[i]->remove();
            continue;
        }
        poolsize += (int)mons[i]->query_property("raised");
    }
    if(!sizeof(temp)){
        if(objectp(TO)) TO->remove();
        return 1;
    }

    caster->remove_property("raised");
    caster->set_property("raised", poolsize);

    mons = temp;
    return 0;
}

void heart_beat(){
    if(!objectp(caster)) remove();
    clean_mons();
}

void remove(){
    int i;
    for(i = 0; i < sizeof(mons); i++){
        if(objectp(mons[i])) mons[i]->die();
    }
    if(objectp(caster)) caster->remove_property("raised");
    return ::remove();
}

void init(){
    ::init();
    add_action("cmd", "command");
    add_action("dismiss", "dismiss");
    add_action("poolsize", "poolsize");
}

int poolsize(string str){
    int pool;

    clean_mons();
    pool = (int)caster->query_property("raised");
    if(pool) tell_object(caster, "%^C059%^Your undead pool is filled with %^C255%^"+sizeof(mons)+"%^C059%^ undead minions using %^C255%^"+pool+"%^C059%^ slots. You have %^C255%^"+(MAX_RAISE - pool)+"%^C059%^ slots remaining.%^CRST%^");
    else tell_object(caster, "%^C059%^YOU LACK ANY MINIONS TO SERVE YOUR WILL.%^CRST%^");

    return 1;
}

int cmd(string str){
    object ob;
    string what, who, what2, holder, *command;
    int i;

    if(clean_mons()) return 0;
    if(!str) return 0;
    
    if(sscanf(str, "%s to %s", who, what) != 2) return notify_fail("YOUR SERVANTS WILL NOT ACT WITHOUT A PROPER COMMAND!");
    if(who != "undead") return 0;

    command = explode(what, " ");
    if(member_array(command[0], BLACKLIST) != -1) return notify_fail("YOU CANNOT MAKE SUCH A DEMAND OF THE UNDEAD!");

    if(what[0..3] == "kill"){
        if(sscanf(what, "kill %s", who) == 1){
            if(ob = present(who, environment(caster))){
                if(!caster->ok_to_kill(ob)) return notify_fail("KILLING THAT IS BENEATH YOUR NOTICE.");
            }
        }
    }

    if(what == "follow"){
        for(i = 0; i < sizeof(mons); i++){
            if(!objectp(mons[i])) continue;
            if(!present(mons[i], environment(caster))) continue;
            caster->add_follower(mons[i]);
            caster->add_protector(mons[i]);
            mons[i]->set_follow(1);
            tell_object(caster, "%^C059%^Your "+mons[i]->query_short()+"%^C059%^ falls in line with you.%^CRST%^");
        }
        return 1;
    }
    
    if(what == "halt"){
        for(i = 0; i < sizeof(mons); i++){
            if(!objectp(mons[i])) continue;
            if(!present(mons[i], environment(caster))) continue;
            caster->remove_follower(mons[i]);
            mons[i]->set_follow(0);
            tell_object(caster, "%^C059%^Your "+mons[i]->query_short()+"%^C059%^ stops where it stands.%^CRST%^");
        }
        return 1;
    }

    for(i = 0; i < sizeof(mons); i++){
        if (!mons[i]->force_me(what)) continue;
    }
    return 1;
}

int dismiss(string str){
    int i;

    if(!str || str != "undead") return 0;
    
    tell_object(caster, "%^C059%^THE SOULS REJOICE IN FREEDOM FROM THEIR MORTAL PRISONS!%^CRST%^");
    if(sizeof(mons) > 1) tell_room(environment(caster), "%^C064%^The undead creatures crumble to dust!%^CRST%^", caster );
    else tell_room(environment(caster), "%^C064%^The undead creature crumbles to dust!%^CRST%^", caster );
    remove();
    return 1;
}

