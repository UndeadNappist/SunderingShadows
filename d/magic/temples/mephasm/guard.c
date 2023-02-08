// Chernobog (2/7/23)
// Mephasm Temple Guard

#include <std.h>
#include <daemons.h>

inherit MONSTER;

void create(){
    ::create();
    set_name("guard");
    set_id(({ "guard", "abishai", "shadow abishai", "devil" }));
    set_race("human");
    set_gender(random(2) ? "male" : "female");
    set_short("%^RESET%^%^CRST%^%^C243%^A vicious%^RESET%^ %^C093%^s%^C129%^h%^C165%^ad%^C129%^o%^C093%^w%^RESET%^ %^C088%^a%^C124%^b%^C160%^i%^C196%^s%^C160%^h%^C124%^a%^C088%^i%^RESET%^ %^C243%^guard%^RESET%^%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C243%^Shadowy draconic wings drape this%^RESET%^ %^C088%^v%^C124%^i%^C160%^c%^C196%^i%^C160%^o%^C124%^u%^C088%^s%^RESET%^ %^C243%^creature in a membranous embrace, deep%^RESET%^ %^C009%^red%^RESET%^ %^C243%^eyes and%^RESET%^ %^C241%^ashen%^RESET%^ %^C243%^flesh marking it not as a black%^RESET%^ %^C088%^a%^C124%^b%^C160%^i%^C196%^s%^C160%^h%^C124%^a%^C088%^i%^RESET%^ %^C243%^but as a resident of the Plane of Shadow, a servitor of the%^RESET%^ %^C057%^s%^C093%^h%^C129%^a%^C165%^d%^C129%^o%^C093%^w%^RESET%^ %^C057%^d%^C093%^r%^C129%^a%^C165%^g%^C129%^o%^C093%^n%^C057%^s%^C243%^. As viciously aligned to Law as Lord Shadow Himself, their presence in this temple is, perhaps, a strange one - but as they seem inordinately%^RESET%^ %^C088%^f%^C124%^o%^C160%^c%^C196%^u%^C160%^s%^C124%^e%^C088%^d%^RESET%^ %^C243%^on the teller windows, they seem to have been selected as much for their avarice as for their adherence to%^RESET%^ %^C057%^D%^C093%^a%^C129%^r%^C165%^kn%^C129%^e%^C093%^s%^C057%^s%^RESET%^ %^C243%^and%^RESET%^ %^C124%^O%^C160%^r%^C196%^d%^C160%^e%^C124%^r%^C243%^. Serrated claws gleam from their extremities, their ankles shrouded in a cold, dark%^RESET%^ %^C088%^m%^C124%^i%^C160%^s%^C196%^t%^RESET%^ %^C243%^that spreads out in icy plumes from their body before dissipating into the air.%^RESET%^%^CRST%^\n");
    set_alignment(3);
    set_hd(50, 0);
    set_class("fighter");
    set_mlevel("fighter", 50);
    set_class("thief");
    set_mlevel("thief", 50);
    set_max_hp(2000);
    set_hp(query_max_hp());
    set_overall_ac(-60);
    set_skill("athletics", 60);
    set_property("no_random_treasure", 1);
    set_property("swarm", 1);
    set_property("full attacks",1);
    set_monster_feats(({
        "parry"
        "weapon training",
        "weapon focus",
        "greater weapon focus",
        "epic weapon focus",
        "dodge",
        "danger sense",
        "mobility",
        "evasion",
        "scramble",}));
    set_gear();
}

void set_gear(){
    object ob;
    
    ob = new("/d/islands/dreams/obj/glaive");
    ob->set_property("monsterweapon",1);
    ob->move(this_object());
    this_object()->force_me("wield glaive");
}

