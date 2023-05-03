#include <std.h>
inherit "/d/magic/symbols/holy_symbol.c";

void create(){
    ::create();
    set_id(({"holy symbol", "eucalia_holy_symbol", "symbol", "hoop"}));
    set_name("holy symbol");
    set_short("holy symbol");
    set_long("This is a holy symbol.");
}
    
void init(){
    ::init();
    set_name("hoop of braided wood");
    set_short("%^C155%^A hoop of %^C094%^b%^C130%^r%^C136%^a%^C130%^i%^C094%^d%^C130%^e%^C136%^d %^C130%^w%^C094%^o%^C130%^o%^C136%^d%^CRST%^");
    set_long("%^C155%^The symbol is a beautiful and intricate piece, made from a hoop of %^C094%^b%^C130%^r%^C136%^a%^C130%^i%^C094%^d%^C130%^e%^C136%^d %^C130%^w%^C094%^o%^C130%^o%^C136%^d %^C155%^that is encircled by %^C034%^v%^C040%^i%^C046%^n%^C040%^e%^C034%^s%^C155%^. The vines are intricately %^C094%^e%^C100%^n%^C106%^t%^C112%^w%^C154%^i%^C148%^n%^C142%^e%^C136%^d %^C155%^around the hoop, creating a protective barrier around a suspended %^C035%^s%^C036%^e%^C037%^e%^C043%^d%^C042%^l%^C041%^i%^C035%^n%^C036%^g %^C155%^that hangs in the center of the hoop. A thin leather cord has been tied to the hoop, allowing it to be easily worn about the neck.%^CRST%^");
    
}
