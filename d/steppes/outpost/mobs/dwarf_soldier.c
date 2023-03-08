

#include <std.h>
#include <daemons.h>
#include "/d/common/common.h"


inherit "/std/guardsman.c";

object ob;

void create(){
    ::create();
    will_open_doors(1);
    set_nogo(({ "/d/stepps/outpost/rooms/1" }));
    set_name("dwarven soldier");
    set_id(({ "soldier", "dwarven soldier", "dwarf"}));
    set_short("A buff dwarf");
    set_gender(random(2) ? "male" : "female");
    set_race("dwarf");
    set_hd(20 + random(20), 1);
    set_class("fighter");
    set_mlevel("fighter", query_hd());

    set_guild_level("fighter", query_hd());
    add_search_path("/cmds/fighter");
    set_fighter_style("soldier");
    set_property("full attacks", 1);
    set_mob_magic_resistance("average");
    set_property("add kits", 20);
    set_skill("rope use", 45);
    set_monster_feats(({
        "parry",
        "powerattack",
        "shatter",
        "sunder",
        "rush",
        "damage resistance",
        "improved damage resistance",
        "improved toughness",
        "regeneration",
        "toughness",
        "expertise",
        "knockdown"
    }));

    set_funcs(({
        "rushit",
        "flashit",
        "shatterit",
        "sunderit",
        "rushit",
        "kdit",
        "kdit"
    }));
    set_func_chance(80);
    set_ac(5 - random(30));
    set_detecting_invis(random(2));
    set_exp(1);


//equipment
            ob = new("/d/common/obj/weapon/battle_axe");
            ob->set_property("enchantment",3);
            // ob->set_short(" ");
			// ob->set_long(" ");
            ob->set_property("monsterweapon",1);
            ob->move(TO);
            command("wield axe");
    
            ob = new("/d/common/obj/armour/banded");
            ob->set_property("enchantment",3);
            // ob->set_short(" ");
            // ob->set_long(" ");
            ob->set_property("monsterweapon",1);
            ob->move(TO);
            command("wear banded");

            ob = new("/d/common/obj/clothing/robe");
            // ob->set_short(" ");
            // ob->set_long(" ");
            ob->set_property("monsterweapon",1);
            ob->move(TO);
            command("wear robe");

            ob = new("/d/common/obj/armour/shield");
            ob->set_property("enchantment",3);
            ob->set_property("monsterweapon",1);
            ob->move(TO);
            command("wear shield");
            command("wield sword");
            ob = new("/d/common/obj/armour/coif");
            // ob->set_short(" ");
            // ob->set_long(" ");
            ob->set_property("enchantment",3);
            ob->set_property("monsterweapon",1);
            ob->move(TO);
            command("wear coif");
    
    make_me();
}




void make_me(){
    object ob;
    int i,j,k;
    string theclass,dwarf_adj,dwarf_type;
    i = random(5);
    switch(i){
        case 0: dwarf_adj = "%^C060%^gruff%^CRST%^"; break;
        case 1: dwarf_adj = "%^C094%^hardy%^CRST%^"; break;
        case 2: dwarf_adj = "%^C161%^fierce%^CRST%^"; break;
        case 3: dwarf_adj = "%^C145%^gaunt%^CRST%^"; break;
        case 4: dwarf_adj = "%^C245%^shifty%^CRST%^"; break;
    }

    i = random(3);
    switch(i){
        case 0: dwarf_type = "%^C241%^gray%^CRST%^"; break;
        case 1: dwarf_type = "%^C143%^shield%^CRST%^"; break;
        case 2: dwarf_type = "%^C184%^gold%^CRST%^"; break;
    }

    i = random(3);
    switch(i){
        case 0:        set_short("%^C108%^A %^CRST%^" +dwarf_adj+ "%^C108%^ %^C100%^dwarven%^C108%^ soldier%^CRST%^"); break;
        case 1:        set_short("%^C108%^A %^CRST%^" +dwarf_type+ "%^C108%^ %^C100%^dwarf%^C108%^ soldier%^CRST%^"); break;
        case 2:        set_short("%^C108%^A %^CRST%^" +dwarf_adj+ " " +dwarf_type+ "%^C100%^ dwarf%^C108%^ soldier%^CRST%^"); break;
    }

    set_long("%^C059%^Dressed in %^C249%^simple armour%^C059%^ and wielding a %^C100%^worn weapon%^C059%^, this %^CRST%^" +dwarf_type+ "%^C059%^ stands resolutely in protection of the steppes outpost. They grip their weapon tightly and are constantly scanning the %^C074%^horizon%^C059%^ for some threat. The equipment itself is %^C251%^threadbare%^C059%^, as if they are equipped in hand me downs.%^CRST%^\n"); 
}

void kdit(object targ)
{
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    TO->force_me("knockdown " + targ->query_name());
}

void flashit(object targ)
{
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    TO->force_me("flash " + targ->query_name());
}

void rushit(object targ)
{
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    TO->force_me("rush " + targ->query_name());
}

void sunderit(object targ)
{
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    TO->force_me("sunder " + targ->query_name());
}

void shatterit(object targ)
{
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    TO->force_me("shatter " + targ->query_name());
}


