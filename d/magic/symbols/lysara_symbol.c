#include <std.h>
inherit "/d/magic/symbols/holy_symbol.c";

void create(){
   ::create();
   set_id(({"holy symbol","symbol","lysara_holy_symbol","amulet","silver amulet","three ringed amulet","amulet of interlocking rings"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_name("amulet of interlocking rings");
   set_short("%^RESET%^%^CRST%^%^C080%^An amulet of %^RESET%^%^C255%^i%^C254%^n%^C253%^t%^C252%^e%^C251%^r%^C252%^l%^C253%^o%^C254%^c%^C255%^k%^C244%^i%^RESET%^%^C253%^n%^RESET%^%^C252%^g %^RESET%^%^C253%^r%^C241%^i%^C255%^n%^C254%^g%^RESET%^%^C252%^s%^CRST%^");
   set_long("%^RESET%^%^CRST%^%^C080%^This simple amulet hangs upon a chain of %^RESET%^%^C252%^s%^C251%^i%^C250%^l%^C249%^v%^C250%^e%^C251%^r%^RESET%^%^C080%^, its links %^RESET%^%^C255%^polished %^RESET%^%^C080%^to a %^RESET%^%^C015%^lustrous shine%^RESET%^%^C080%^. They lead down to an amulet formed of three metallic rings, each about an inch in diameter. The hoops have been %^RESET%^%^C255%^i%^C254%^n%^C253%^t%^C252%^e%^C251%^r%^C252%^l%^C253%^o%^C254%^c%^C255%^k%^C254%^e%^RESET%^%^C253%^d %^RESET%^%^C080%^in such a careful manner that they cannot be moved out of place. The upper ring is made of the same %^RESET%^%^C252%^s%^C251%^i%^C250%^l%^C249%^v%^C250%^e%^RESET%^%^C251%^r %^RESET%^%^C080%^as the chain, while of the lower two circles, the one on the right is made of %^RESET%^%^C241%^ebony%^RESET%^%^C080%^, and one on the left is carved from %^RESET%^%^C230%^ivory%^RESET%^%^C080%^.%^CRST%^");
}