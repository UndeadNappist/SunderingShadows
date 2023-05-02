#include <std.h>
inherit "/d/magic/symbols/holy_symbol.c";

void create(){
    ::create();
    set_id(({"holy symbol", "velik_holy_symbol", "symbol", "pendant"}));
    set_name("holy symbol");
    set_short("holy symbol");
    set_long("This is a holy symbol.");
}
    
void init(){
    ::init();
    set_name("iron pendant embossed with a raised fist");
    set_short("%^C250%^An %^C059%^iron pendant %^C250%^embossed with a raised %^C240%^f%^C241%^i%^C242%^s%^C240%^t%^CRST%^");
    set_long("%^C250%^The %^C059%^iron pendant %^C250%^is a symbol of %^C088%^s%^C124%^t%^C160%^r%^C196%^en%^C160%^g%^C124%^t%^C088%^h %^C250%^and %^C027%^l%^C033%^i%^C039%^b%^C045%^e%^C039%^r%^C033%^a%^C027%^t%^C033%^i%^C039%^o%^C045%^n%^C250%^, bearing the image of a raised %^C240%^f%^C241%^i%^C242%^s%^C240%^t %^C250%^breaking free from a %^C059%^shackle%^C250%^. The pendant appears to be expertly crafted, the fist and shackle both raised in high relief. With its rough and textured surface, one could imagine this symbol was forged from remnants of %^C240%^b%^C241%^r%^C242%^o%^C243%^k%^C241%^e%^C240%^n chains%^C250%^. The pendant is replete with a sturdy %^C094%^leather cord %^C250%^that allows it to be worn easily about the neck.%^CRST%^");
    
}
