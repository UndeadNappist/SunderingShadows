#include <std.h>
inherit WEAPONLESS;

create(){
    ::create ();
    set_name("wyvern");
    set_property("no rush",1);
    set_id( ({"black wyvern", "wyvern"}) );
    set_short("%^C243%^s%^C245%^h%^C247%^a%^C243%^d%^C245%^o%^C247%^w%^C243%^y %^C059%^black %^C100%^wyvern%^CRST%^");
    set_long("%^C100%^The wyvern is a large dragon-like creature that has been specially bred by the Kinnesaruda as guardians.  Lacking the intelligence of most dragons, and bred with an animalistic desire to hunt and kill, only the undead are safe from these menaces.\n\n%^C059%^The black wyvern is perhaps the most deadly of wyverns.%^CRST%^");
    set_gender("male");
    set_race("wyvern");
    set_body_type("dragon");
    set_property("swarm",1);
    set_hd(46,0);
    set_overall_ac(-5);
    set_size(4);
    set_moving( 1 );
    set_speed( 30 );
    set_stats("strength", 19);
    set_stats("intelligence", 6);
    set_stats("dexterity", 19);
    set_stats("charisma", 6);
    set_stats("wisdom", 5);
    set_class("fighter");
    set("aggressive", 26);
    set_alignment(4);
    set_max_hp(300);
    set_hp(query_max_hp());
    set_exp(8500);
    set_funcs( ({"fire"}) );
    set_func_chance(50);
    set_attacks_num(2);
    set_damage(1,12);
    set_attack_limbs(({"left foreclaw","right foreclaw"}));
    add_money("gold", 20 + random(340));
}

void init(){
    ::init();  
// added ::init() to fix/prevent bugs & changed wizardp to check true invis 2/23/03 *Styx*
    if(TP->query_invis() && !TP->query_true_invis() && !TP->is_monster()){
        tell_room(ETO,"%^C196%^The wyvern senses your movement and attacks!%^CRST%^");
        TP->set_invis();
        kill_ob(TP,1);
    }
}

void fire(object targ){
    if(!targ) return 0;
    if(random(25) > targ->query_stats("charisma")){
        tell_room(environment(targ), "%^C100%^%^The %^C243%^b%^C245%^l%^C247%^a%^C243%^c%^C245%^k %^C247%^w%^C243%^y%^C245%^v%^C247%^e%^C243%^r%^C245%^n%^C100%^ shrieks and %^C243%^s%^C245%^h%^C247%^a%^C243%^d%^C245%^o%^C247%^w%^C243%^y %^C245%^w%^C247%^i%^C243%^s%^C245%^p%^C247%^s%^C100%^ stab into "+targ->query_cap_name()+"%^C100%^ like daggers!%^CRST%^", targ);
        tell_object(targ, "%^BOLD%^%^BLACK%^The %^C243%^b%^C245%^l%^C247%^a%^C243%^c%^C245%^k %^C247%^w%^C243%^y%^C245%^v%^C247%^e%^C243%^r%^C245%^n%^C100%^ shrieks and %^C243%^s%^C245%^h%^C247%^a%^C243%^d%^C245%^o%^C247%^w%^C243%^y %^C245%^w%^C247%^i%^C243%^s%^C245%^p%^C247%^s%^C100%^ stab into you like daggers!");
        targ->cause_typed_damage(targ, "torso", random(30) + 15, "void");
        return 1;
    }
    else{
        tell_object(targ, "%^C100%^%^The %^C243%^b%^C245%^l%^C247%^a%^C243%^c%^C245%^k %^C247%^w%^C243%^y%^C245%^v%^C247%^e%^C243%^r%^C245%^n%^C100%^ shrieks violently at you, but nothing happens!%^CRST%^");
        tell_room(environment(targ), "%^C100%^The %^C243%^b%^C245%^l%^C247%^a%^C243%^c%^C245%^k %^C247%^w%^C243%^y%^C245%^v%^C247%^e%^C243%^r%^C245%^n%^C100%^ shrieks violently at "+targ->query_cap_name()+"%^C100%^ but nothing happens!%^CRST%^", targ);
    }
}

