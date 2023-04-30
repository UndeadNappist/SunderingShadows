#include <std.h>
inherit MONSTER;

create(){
    ::create();
    set_name("wyvern");
    set_property("no rush", 1);
    set_id(({ "red wyvern", "wyvern" }));
    set_short("%^C124%^d%^C160%^e%^C196%^ep r%^C160%^e%^C124%^d %^C100%^wyvern%^CRST%^");
    set_long("%^C100%^The wyvern is a large dragon-like creature that has been specially bred by the Kinnesaruda as guardians.  Lacking the intelligence of most dragons and bred with an animalistic desire to hunt and kill, only the undead are safe from these menaces.%^CRST%^");
    set_gender("male");
    set_race("wyvern");
    set_body_type("dragon");
    set_property("swarm", 1);
    set_property("full attacks", 1);
    set_hd(40, 0);
    set_overall_ac(-5);
    set_size(4);
    set_moving(1);
    set_speed(40);
    set_stats("strength", 19);
    set_stats("intelligence", 6);
    set_stats("dexterity", 19);
    set_stats("charisma", 6);
    set_stats("wisdom", 5);
    set_class("fighter");
    set("aggressive", 22);
    set_alignment(4);
    set_max_hp(300);
    set_hp(query_max_hp());
    set_exp(7500);
    set_funcs(({ "fire" }));
    set_func_chance(50);
    set_wielding_limbs(({ "left hand", "right hand" }));
    set_base_damage_type("slashing");
    add_money("gold", 20 + random(340));
}

void init(){
    ::init();
// added ::init() to fix/prevent bugs & changed wizardp to check true invis 2/23/03 *Styx*
    if(TP->query_invis() && !TP->query_true_invis() && !TP->is_monster()){
        tell_room(ETO, "%^C196%^The wyvern senses your movement and attacks!%^CRST%^");
        TP->set_invis();
        kill_ob(TP, 1);
    }
}

void fire(object targ){
    if(!targ) return 0;
    if(random(25) > targ->query_stats("intelligence")){
        tell_room(environment(targ), "%^C100%^The %^C124%^r%^C160%^e%^C124%^d w%^C160%^y%^C196%^ve%^C160%^r%^C124%^n%^C100%^ draws back its head and lets loose a tremendous %^C208%^b%^C214%^r%^C208%^e%^C202%^a%^C208%^t%^C214%^h %^C208%^o%^C202%^f %^C208%^f%^C214%^i%^C208%^r%^C202%^e%^C100%^ that burns "+targ->query_cap_name()+"%^C100%^!%^CRST%^", targ);
        tell_object(targ, "%^C100%^The %^C124%^r%^C160%^e%^C124%^d w%^C160%^y%^C196%^ve%^C160%^r%^C124%^n%^C100%^ draws back its head and lets loose a tremendous %^C208%^b%^C214%^r%^C208%^e%^C202%^a%^C208%^t%^C214%^h %^C208%^o%^C202%^f %^C208%^f%^C214%^i%^C208%^r%^C202%^e%^C100%^ that burns you!%^CRST%^");
        set_property("magic", 1);
        targ->cause_typed_damage(targ, "torso", random(15) + 15, "fire");
        set_property("magic", -1);
        return 1;
    }
    else{
        tell_object(targ, "%^C100%^The %^C124%^r%^C160%^e%^C124%^d w%^C160%^y%^C196%^ve%^C160%^r%^C124%^n%^C100%^ draws back its head and lets loose a tremendous breath of fire, but you are able to dodge out of the way!");
        tell_room(environment(targ), "%^C100%^The %^C124%^r%^C160%^e%^C124%^d w%^C160%^y%^C196%^ve%^C160%^r%^C124%^n%^C100%^ draws back its head and lets loose a tremendous breath of fire at "+targ->query_cap_name()+"%^C100%^ but they dodge out of the way!%^CRST%^", targ);
    }
}

