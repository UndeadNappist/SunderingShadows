// Repose domain, spectral steed. Nienne, 04/07.
#include <std.h>
inherit "/std/riding_animal";

void create(){
    ::create();
    set_name("a phantom steed");
    set_short("%^C059%^An %^C051%^e%^C045%^th%^C039%^er%^C033%^eal %^C244%^g%^C246%^ra%^C244%^y %^C059%^horse%^CRST%^");
    set_id(({"steed", "horse", "spectral steed", "ethereal horse", "gray horse", "ethereal gray horse"}));
    set_long("%^C024%^Before you stands a creature that is difficult to perceive. It seems %^C051%^g%^C045%^ho%^C039%^st%^C033%^ly %^C024%^and insubstancial, forming the vague outline of a tall horse with a dull %^C244%^g%^C246%^ra%^C244%^y %^C024%^coat. Whispy hooves brush the ground without a sound, as if the creature were only %^C125%^i%^C126%^ma%^C125%^gi%^C126%^ne%^C125%^d%^C024%^, not truly present. The only clear part about the creature is its %^C059%^dark%^C024%^ eyes, which glow with an intelligence unlike that of a mere beast. This indeed must be some kind of supernatural creature, and probably not one to take lightly.%^CRST%^");
    set_level(10);
    set_value(0);
    set_race("horse");
    if(random(2)) set_gender("female");
    else set_gender("male");
    set_body_type("equine");
    set_attack_limbs( ({"right forehoof", "left forehoof"}) );
    set_size(3);
    set_max_hp(100);
    set_hd(10,1);
    set_hp(100);
    set_overall_ac(3);
    set_exp(1);
    set_max_distance(10);
    set_enter_room("rides in on a spectral horse.");
    set_exit_room("leaves riding a spectral horse.");
    set_vehicle_short("%^C059%^An %^C051%^e%^C045%^th%^C039%^er%^C033%^eal %^C244%^g%^C246%^ra%^C244%^y %^C059%^horse%^CRST%^");
    set_attacks_num(2);
    set_damage(2,6);
    set_property("no_random_treasure", 1);
}

int enter(string str){
    int lev, temp;

    lev = TP->query_guild_level("cleric");
    temp = TP->query_max_hp();
    if(query_owner() != this_player()) {
        tell_room(ETP, ""+TPQCN+" seems unable to mount the spectral horse!", TP);
        return notify_fail("The horse is too insubstancial to mount!\n");
    }

    set_level(lev*1/3);
    set_mlevel("fighter", lev*1/3);
    set_max_hp(temp*1/3);
    set_damage(2,6);
    set_hp(query_max_hp());
    return ::enter(str);
    return 1;
}

int handle_critter(string str) {
    tell_room(ETP,"The spectral horse seems uninterested in "+TPQCN+"'s attempts to handle it.", TP);
    return notify_fail("You cannot handle this enchanted beast!\n");
}

int give_me_away(string str){
    return notify_fail("Your mount refuses to leave you!\n");
    return 0;
}
int save_me(string file) {return 0;}
int restore_me(string file) { TO->remove(); return 0;}
