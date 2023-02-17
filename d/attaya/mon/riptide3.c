#include <std.h>
inherit MONSTER;

create(){
    ::create();
    set_name("riptide");
    set_id(({ "riptide", "boatman" }));
    set_gender("male");
    set_short("%^RESET%^%^CRST%^%^C051%^R%^C045%^ip%^C039%^ti%^C033%^de %^C027%^the %^C051%^B%^C045%^oa%^C039%^tm%^C033%^an%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C021%^Ancient spirits slip aside to reveal Riptide, the mythical boatman of the River of Flame. It is his sole purpose to ferry travelers towards the distant shore, bound in service for reasons lost to the ages. Does he serve the %^C045%^Kinnesaruda%^C021%^, or is it %^C059%^revenge %^RESET%^%^C021%^that fuels him, allowing adventurers the chance to strike at the evil lurking there? It has been said that those that traverse the molten river seldom return.%^CRST%^");
    set_level( 30 );
    set_race("undead");
    set_body_type("humanoid");
    set_alignment( 7 );
    set_size( 2 );
    set_stats("intelligence", 25);
    set_stats("wisdom", 25);
    set_stats("strength", 24);
    set_stats("charisma", 25);
    set_stats("dexterity", 18);
    set_stats("constitution", 25);
    set_max_mp(500);
    set_spell_chance(99);
    set_spells(({
        "chill touch",
        "dispel magic",
        "magic missile",
        "freeze"
        }));
    set_mp(query_max_mp());
    set_hd(5, 1);
    set_max_hp(query_hp());
    set_exp(500);
    set_max_sp(query_hp());
    set_sp(query_max_sp());
    add_money("silver",random(1300));
    add_money("copper",random(20));
}

