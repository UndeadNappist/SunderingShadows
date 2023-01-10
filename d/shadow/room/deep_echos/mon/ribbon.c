//dancing dress summoned by weapon

#include <std.h>

inherit "/std/monster";

string *dances;

create() {
    ::create();
    set_name("dress");
    set("id", ({ "dress" }));
	if(random(2)){
        set("short", "%^RESET%^%^CRST%^%^C255%^a glowing white dress%^CRST%^");
        set("long", "This glowing white dress dances about. It looks to be formed from a collection of ribbons.");
        dances = ({
            "%^RESET%^%^CRST%^%^C255%^The empty dress dances about.%^CRST%^",
            "%^RESET%^%^CRST%^%^C255%^The dress spins about elegantly.%^CRST%^",
            "%^RESET%^%^CRST%^%^C255%^The dress bows in an graceful dip.%^CRST%^",});
	}
	else{
        set("short", "%^RESET%^%^CRST%^%^C059%^a glowing black dress%^CRST%^");
        set("long", "This glowing black dress dances about. It looks to be formed from a collection of ribbons.");
        dances = ({
            "%^RESET%^%^CRST%^%^C059%^The empty dress dances about.%^CRST%^",
            "%^RESET%^%^CRST%^%^C059%^The dress spins about elegantly.%^CRST%^",
            "%^RESET%^%^CRST%^%^C059%^The dress bows in an graceful dip.%^CRST%^",});
	}

	add_search_path("/cmds/mortal");
	set_stats("wisdom", 3);
    set_stats("strength", 3);
    set_stats("charisma", 25);
    set_stats("dexterity", 3);
    set_stats("constitution", 3);
	set_hd(2,1);
    set_level(1);
    set_class("thief");
    set_body_type("humanoid");
    set_alignment(5);
    set("race", "dress");
    set_exp(0);
    set_gender("female");
    set_ac(1);
    set_max_hp(60);
    set_hp(60);
    if(clonep(TO)) call_out("remove", 40);

}
void dance(){
    if(!objectp(ETO)) return;  //dancing spams debug.log, trying to fix
    tell_room(ETO, dances[random(3)]);
}

void heart_beat(){
    ::heart_beat();
    dance();
}

int remove(){
    if(!objectp(TO) || !objectp(ETO)) return ::remove();
    tell_room(ETO, "%^RESET%^%^CRST%^%^C090%^The dress falls apart into a pile of %^C243%^r%^C247%^i%^C255%^b%^C243%^b%^C247%^o%^C255%^n%^C243%^s %^RESET%^%^C090%^and %^C059%^disappears%^C090%^.%^CRST%^");
    return ::remove();
}

void die(object ob){
    remove();
}

