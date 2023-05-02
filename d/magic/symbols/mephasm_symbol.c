#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

void create(){
    ::create();
    set_id(({"holy symbol", "symbol", "mephasm_holy_symbol", "medallion"}));
    set_name("holy symbol");
    set_short("holy symbol");
    set_long("This is a holy symbol.");
}

void init(){
    ::init();
    set_name("a bronze medallion embossed with a fist and rose");
    set_short("%^C136%^A %^C094%^bronze medallion %^C136%^embossed with a %^C088%^f%^C124%^i%^C160%^s%^C088%^t %^C136%^and %^C240%^r%^C241%^o%^C242%^s%^C240%^e%^CRST%^");
    set_long("%^C136%^This %^C094%^bronze medallion %^C136%^is embossed with a %^C088%^c%^C124%^l%^C160%^a%^C196%^w%^C124%^e%^C088%^d h%^C124%^a%^C160%^n%^C088%^d %^C136%^curled into a tight fist, a %^C240%^r%^C241%^o%^C242%^s%^C240%^e %^C136%^crushed within its grasp. The hand appears to be reaching out of the circle as if in %^C088%^defiance %^C136%^or %^C244%^strength%^C136%^. The details of the carving are well-wrought, the claws on each individual finger visibly sharp, and the texture of the flower’s %^C240%^p%^C241%^e%^C242%^t%^C243%^a%^C241%^l%^C240%^s %^C136%^plain to see. The medallion is strung with %^C250%^s%^C248%^t%^C246%^e%^C248%^e%^C250%^l c%^C248%^h%^C244%^a%^C246%^i%^C248%^n%^C136%^, allowing it to be worn easily about the neck.%^CRST%^");
}