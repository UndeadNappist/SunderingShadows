#include <std.h>
inherit "/d/magic/symbols/holy_symbol.c";

void create(){
    ::create();
    set_id(({"holy symbol", "nim_holy_symbol", "symbol", "medallion", "nimnavanon_holy_symbol"}));
    set_name("holy symbol");
    set_short("holy symbol");
    set_long("This is a holy symbol.");
}
    
void init(){
    ::init();
    set_name("oak medallion");
    set_short("%^RESET%^%^C058%^A rustic %^RESET%^%^C240%^wolf paw %^RESET%^%^C058%^carving etched upon an %^RESET%^%^C094%^o%^C130%^a%^C136%^k %^RESET%^%^C130%^m%^C094%^e%^C130%^d%^C136%^a%^C130%^l%^C094%^l%^C130%^i%^C136%^o%^RESET%^%^C130%^n%^CRST%^");
    set_long("");
    
}
