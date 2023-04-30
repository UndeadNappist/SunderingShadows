// Chernobog (4/6/23)
// Lesser Undead Minion

#include <std.h>

inherit "/d/magic/mon/create_undead/_inherit";

void create(){
    ::create();
    set_name("lesser undead");
    set_id(({"minion", "undead minion", "undead"}));
    set_short("typical lesser undead minion");
    set_long("This is a typical example of a lesser undead that a necromancer would use for menial tasks.");
    set_race("undead");
    set_gender("neuter");
    set_body_type("human");
    set_hd(2, 0);
    set_alignment(9);
    set_size(2);
    set_stats("strength", 22);
    set_stats("dexterity", 16);
    set_stats("constitution", 12);
    set_stats("intelligence", 4);
    set_stats("wisdom", 4);
    set_stats("charisma", 8);
    set_max_hp(20);
    set_hp(query_max_hp());
    set_property("undead", 1);
    set_property("full attacks", 1);
    set_property("no corpse", 1);
}

