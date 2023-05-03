#include <std.h>
inherit "/d/magic/symbols/holy_symbol.c";

void create(){
    ::create();
    set_id(({"holy symbol", "ebolek_holy_symbol", "symbol", "skull"}));
    set_name("holy symbol");
    set_short("holy symbol");
    set_long("This is a holy symbol.");
}
    
void init(){
    ::init();
    set_name("symbol comprised of writhing maggots");
    set_short("%^C065%^A %^C230%^symbol %^C065%^depicting %^C142%^w%^C143%^r%^C144%^i%^C100%^t%^C101%^h%^C148%^i%^C107%^n%^C108%^g %^C230%^m%^C100%^a%^C230%^gg%^C136%^o%^C230%^ts%^CRST%^");
    set_long("%^C065%^The symbol is carved from a %^C230%^bone %^C065%^and depicts a %^C142%^w%^C143%^r%^C144%^i%^C100%^g%^C101%^g%^C148%^l%^C107%^i%^C108%^n%^C109%^g %^C065%^pile of %^C230%^m%^C100%^a%^C230%^gg%^C136%^o%^C230%^ts%^C065%^. They are meticulously carved, with each one appearing to be actively moving and writhing around in the pile. Together, they form the rough outline of a %^C230%^humanoid skull%^C065%^, with the various %^C240%^cavities %^C065%^and %^C144%^features %^C065%^of the skull being hinted at by the twisted mass. It is a stark reminder of the %^C250%^fragility %^C065%^of life and the inevitability of %^C240%^death %^C065%^and %^C148%^d%^C149%^e%^C150%^c%^C143%^a%^C142%^y%^C065%^. There is a %^C242%^r%^C245%^a%^C248%^t%^C245%^t%^C242%^y %^C244%^leather cord %^C065%^allows the symbol to be worn about the neck.%^CRST%^");
    
}
