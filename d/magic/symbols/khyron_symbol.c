#include <std.h>
inherit "/d/magic/symbols/holy_symbol.c";

void create(){
   ::create();
   set_id(({"holy symbol","symbol","khyron_holy_symbol","amulet","driftwood_amulet"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_name("a driftwood amulet");
   set_short("%^RESET%^%^CRST%^%^C102%^A %^RESET%^%^C248%^d%^C250%^r%^C253%^i%^C250%^f%^C248%^tw%^C250%^o%^C255%^o%^RESET%^%^C248%^d a%^RESET%^%^C255%^m%^C250%^ul%^C255%^e%^RESET%^%^C248%^t%^CRST%^");
   set_long("%^RESET%^%^CRST%^%^C102%^This circular amulet is cut from a cross section of a branch of %^RESET%^%^C248%^d%^C250%^r%^C253%^i%^C250%^f%^C248%^tw%^C250%^o%^C255%^o%^RESET%^%^C248%^d%^RESET%^%^C102%^, a %^RESET%^%^C136%^leather cord %^RESET%^%^C102%^strung through a natural hole in the wood. The wood is a %^RESET%^%^C252%^pale gray %^RESET%^%^C102%^in color, its surface %^RESET%^%^C244%^m%^C248%^a%^C250%^r%^C244%^r%^C248%^e%^RESET%^%^C250%^d %^RESET%^%^C102%^with faint %^RESET%^%^C241%^cracks %^RESET%^%^C102%^and %^C242%^nicks%^RESET%^%^C102%^. The amulet bears a symbol that appears to have been %^RESET%^%^C240%^b%^RESET%^%^C088%^u%^C124%^rn%^C088%^e%^RESET%^%^C240%^d %^RESET%^%^C102%^into its surface; a %^RESET%^%^C252%^shattered scimitar %^RESET%^%^C102%^with shards shaped like %^RESET%^%^C226%^l%^C227%^i%^C228%^g%^C229%^h%^C230%^t%^C229%^n%^C228%^i%^C227%^n%^RESET%^%^C226%^g b%^RESET%^%^C228%^o%^C229%^l%^C228%^t%^RESET%^%^C226%^s%^RESET%^%^C102%^.%^CRST%^");
}