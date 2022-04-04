// Chernobog & Titania (3/3/22)
// Wailing Isle - Unicorn Bait

#include <std.h>

inherit OBJECT;

void create(){
	::create();
    set_name("unicorn bait");
	set_id(({"vial", "blood", "runed vial", "runed vial of blood", "unicorn_bait"}));
	set_short("%^RESET%^%^CRST%^%^C118%^r%^C112%^un%^C106%^e%^C118%^d %^RESET%^%^C059%^vial of %^C196%^bl%^C124%^o%^C196%^o%^C124%^d%^CRST%^");
	set_long("%^RESET%^%^CRST%^%^C059%^This small vial is filled with a vibrant crimson fluid that moves with the viscous consistency of %^C196%^bl%^C124%^o%^C196%^o%^C124%^d%^RESET%^%^C059%^. Strange symbols have been painted along the glass in a %^C118%^f%^C112%^ou%^C106%^l %^C118%^i%^C112%^ch%^C106%^o%^C118%^r%^RESET%^%^C059%^, glowing faintly but seeming to preserve the contents.%^CRST%^");
	set_weight(1);
	set_value(0);
    set_lore("%^RESET%^%^CYAN%^One of the more common legends regarding unicorns are their affinity for virginal innocence, often drawn to maidens and only allowing such to ever ride them. This vial seems to emanate and enhance such an aura, but the price for its creation is the sacrifice of a woman still possessing her maidenhead and filling a prepared vial with her heart's blood.%^RESET%^");
    set_property("lore difficulty", 30);
}

