#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

void create(){
    ::create();
    set_id(({"holy symbol", "symbol", "cacia_holy_symbol", "medallion"}));
    set_name("holy symbol");
    set_short("holy symbol");
    set_long("This is a holy symbol.");
}

void init(){
    ::init();
    set_name("a medallion covered in jade and sapphire");
    set_short("%^RESET%^%^CRST%^%^C059%^A %^C096%^m%^C090%^e%^C243%^d%^C096%^a%^C243%^l%^C096%^l%^C090%^i%^C243%^o%^C096%^n %^C059%^covered in %^RESET%^%^C072%^j%^C084%^a%^C065%^d%^C072%^e %^RESET%^%^C059%^and %^RESET%^%^C020%^s%^C026%^ap%^C020%^p%^C026%^h%^C032%^i%^C026%^r%^C020%^e%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C059%^This circular %^C096%^d%^C243%^a%^C096%^r%^C090%^k%^C243%^ste%^C096%^e%^C243%^l %^C096%^m%^C090%^e%^C243%^d%^C096%^a%^C243%^l%^C096%^l%^C090%^i%^C243%^o%^C096%^n %^RESET%^%^C059%^has been etched with the shape of a serpent curled about the rim, wreathing about a half-lidded feminine eye. The scales have been picked out in further detail by %^C072%^m%^C084%^o%^C065%^t%^C072%^t%^C084%^l%^C065%^e%^C072%^d %^C084%^s%^C065%^h%^C072%^a%^C084%^r%^C065%^d%^C072%^s %^RESET%^%^C059%^of %^C072%^j%^C084%^a%^C065%^d%^C072%^e %^RESET%^%^C059%^as it bites upon its own tail. %^C096%^Lavender enamel %^RESET%^%^C059%^dusts the lid of the alluring eye, complementing the %^C020%^s%^C026%^ta%^C020%^r %^C020%^s%^C026%^ap%^C020%^p%^C026%^h%^C032%^i%^C026%^r%^C020%^e %^RESET%^%^C059%^seated there in place of her iris. A simple delicate %^C243%^s%^C247%^i%^C250%^lv%^C247%^e%^C243%^r %^C247%^c%^C250%^h%^C243%^a%^C247%^i%^C250%^n %^RESET%^%^C059%^allows it to be worn easily about the neck.%^CRST%^");
}