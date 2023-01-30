inherit "/std/armour";

void create() {
    ::create();
    set_name("hide shield");
    set("id", ({ "shield", "hide shield", "hshield" }) );
    set("short", "A hide shield");
    set_long("This shield has been fashioned with a hide-covered wooden frame in a circular shape.  The frame has straps for the wearer to loop around the arm in the back.");
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