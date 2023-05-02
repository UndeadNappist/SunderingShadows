// Foo! - LoKi

#include <std.h>

inherit WEAPONLESS;

void create(){
    object ob;
    
    ::create();
    set_name("foo creature");
    set_body_type("quadruped");
    set_gender("neuter");
    set_property("full attacks",1);
    set("aggressive", "aggro_check");
    set_alignment(1);
    set_race("foo creature");
    set_attack_limbs(({"mouth", "right claw", "left claw"}));
    
    switch(random(5)){
        case 0..3:
            set_short("%^C136%^go%^C185%^l%^C136%^den fur%^C185%^r%^C136%^ed Foo Dog%^CRST%^");
            set_id(({"foo dog", "foodog", "foo", "dog"}));
            set_long("%^C185%^This massive beast looks walks on four legs and is %^C088%^bristling with muscles%^C185%^ under its %^C136%^golden fur%^C185%^. While it resembles a %^C094%^monstrous dog%^C185%^, its face has an oddly %^C101%^human%^C185%^ quality to it. Each of its paws end in %^C244%^wicked claws%^C185%^ and %^C015%^two massive fangs%^C185%^ hang out from its mouth.%^CRST%^\n");
            set_hd(36 + random(6), 10);
            add_money("gold", random(500));
            add_money("platinum", random(50));
            set_attacks_num(4);
            set_damage(10, 10);
            set_overall_ac(-55);
            set_monster_feats(({
                "weapon training",
                "weapon focus",
                "greater weapon focus",
                "epic weapon focus",
                }));
            set_resistance_percent("radiant", 15);
            set_resistance_percent("void", -10);
            break;
        case 4:
            set_short("%^C254%^whi%^C246%^t%^C254%^e fu%^C246%^r%^C254%^red Foo L%^C246%^i%^C254%^on%^CRST%^");
            set_id(({"foo lion", "lion", "foo", "foolion"}));
            set_long("%^C254%^This massive beast looks walks on four legs and is %^C088%^bristling with muscles%^C254%^ under its %^C246%^snow white fur%^C254%^. While it resembles a %^C094%^monstrous lion%^C254%^, its face has an oddly %^C101%^human%^C254%^ quality to it. Each of its paws end in %^C244%^wicked claws%^C254%^ and %^C241%^two massive fangs%^C254%^ hang out from its mouth.%^CRST%^\n");
            set_hd(40 + random(4), 10);
            add_money("gold", random(600));
            add_money("platinum", random(100));
            set_attacks_num(6);
            set_damage(15, 15);
            set_overall_ac(-60);
            set_monster_feats(({
                "unarmed parry",
                "rapid strikes",
                "precise strikes",
                "dodge",
                "mobility",
                "scramble",
                "spring attack",
                "defensive roll",
                "resistance",
                "increased resistance",
                "damage resistance",
                "improved damage resistance",
                "weapon training",
                "weapon focus",
                "greater weapon focus",
                "epic weapon focus",
                }));
            set_resistance_percent("radiant", 25);
            set_resistance_percent("void", -15);
            break;
    }
    
    set_max_hp(100 * query_hd());
    set_hp(query_max_hp());
    set_class("fighter", query_hd());
    set_mlevel("fighter", query_hd());
    set_skill("athletics", query_hd() + 5);
    
    set_new_exp(query_hd(), "high");
    set_property("swarm", 1);
    set_property("no_random_treasure", 1);
    set_property("add kits", roll_dice(1, 4) * 5);
    set_mob_magic_resistance("average");
    set_property("spell damage resistance", 20);
}

void aggro_check(){
    object player = this_player();
    if(avatarp(player)) return;
    if(!player->query_alignment()%3) force_me("kill "+player->query_name());
    return;
}

