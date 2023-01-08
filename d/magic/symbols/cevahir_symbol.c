#include <std.h>
inherit "/d/magic/symbols/holy_symbol.c";

void create(){
   ::create();
   set_id(({"holy symbol","symbol","cevahir_holy_symbol","pendant","gold_pendant"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_name("a gold pendant embossed with a battered helm");
   set_short("%^RESET%^%^CRST%^%^C136%^A %^RESET%^%^C226%^gold pendant %^RESET%^%^C136%^embossed with a %^RESET%^%^C094%^b%^C136%^a%^C178%^t%^C220%^t%^C226%^e%^C178%^r%^C136%^e%^RESET%^%^C094%^d helm%^CRST%^");
   set_long("%^RESET%^%^CRST%^%^C136%^Strung upon a %^RESET%^%^C144%^leather cord%^RESET%^%^C136%^, this pendant is made from %^RESET%^%^C226%^pure gold%^RESET%^%^C136%^, pounded and shaped into a disc. Embossed upon its surface is a %^RESET%^%^C094%^b%^C136%^a%^C178%^t%^C220%^t%^C226%^e%^C178%^r%^C136%^e%^RESET%^%^C094%^d%^C136%^, %^RESET%^%^C094%^crested helm%^RESET%^%^C136%^. A smaller circular field of crushed %^RESET%^%^C054%^a%^C055%^m%^C056%^e%^C057%^t%^C056%^h%^C055%^y%^RESET%^%^C054%^st %^RESET%^%^C136%^serves as a backdrop to the helm, giving the otherwise austere symbol a bit of flare.%^CRST%^");
}