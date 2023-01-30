inherit "/std/armour";

void create() {
    ::create();
    set_name("wooden shield");
    set("id", ({ "shield","wood shield", "wooden", "wshield", "wooden shield" }) );
    set("short", "A wooden shield");
    set_long("This shield has been fashioned with a wooden frame in a circular shape.  The frame has straps for the wearer to loop around the arm in the back.");
    set_weight(8);
    set("value", 7);
    set_type("shield");
    set_limbs(({"right hand"}));
    set_ac(1);
    set_armor_prof("shield");
    set_block_chance(25);
    set_item_bonus("shieldMiss",25); // setting these equal to the old block chance since it's a replacement
}

int is_metal() { return 0; }