#include <std.h>
inherit "/d/magic/symbols/holy_symbol.c";

void create(){
   ::create();
   set_id(({"holy symbol","symbol","krey_holy_symbol","kreysneothosies_holy_symbol","amulet","malachite_amulet"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_name("a carved malachite amulet");
   set_short("%^RESET%^%^CRST%^%^C034%^A carved %^RESET%^%^C022%^m%^C028%^a%^C040%^l%^C046%^a%^C040%^c%^C034%^h%^C028%^i%^C022%^t%^RESET%^%^C028%^e %^RESET%^%^C034%^amulet%^CRST%^");
   set_long("%^RESET%^%^CRST%^%^C034%^This triangular amulet is shaped from pure %^RESET%^%^C022%^m%^C028%^a%^C040%^l%^C046%^a%^C040%^c%^C034%^h%^C028%^i%^C022%^t%^RESET%^%^C028%^e%^RESET%^%^C034%^, %^RESET%^%^C040%^s%^C046%^w%^C122%^i%^C121%^r%^C041%^l%^RESET%^%^C047%^s %^RESET%^%^C034%^of %^RESET%^%^C121%^lighter %^RESET%^%^C034%^and %^RESET%^%^C028%^darker green %^RESET%^%^C034%^decorating its surface. Carved into the %^RESET%^%^C047%^polished %^RESET%^%^C034%^stone is a %^RESET%^%^C250%^sword %^RESET%^%^C034%^crossing a sheaf of %^RESET%^%^C136%^wheat%^RESET%^%^C034%^. A hole has been drilled into the top corner of the amulet, a delicate %^RESET%^%^C136%^g%^C178%^o%^C220%^l%^RESET%^%^C226%^d %^RESET%^%^C227%^c%^C226%^h%^C220%^a%^C178%^i%^RESET%^%^C136%^n %^RESET%^%^C034%^strung through it.%^CRST%^");
}