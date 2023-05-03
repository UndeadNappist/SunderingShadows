#include <std.h>
inherit "/d/magic/symbols/holy_symbol.c";

void create(){
   ::create();
   set_id(({"holy symbol","symbol","the_faceless_one_holy_symbol","ring","black ring","dark ring"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_limbs(({"left hand","right hand"}));
   set_name("ring");
   set_short("%^C248%^A %^C123%^p%^C159%^l%^C195%^a%^C159%^t%^C123%^i%^C159%^n%^C195%^u%^C159%^m %^C123%^r%^C159%^i%^C195%^n%^C159%^g %^C248%^set with a %^C240%^black stone%^CRST%^");
   set_long((:TO, "long_desc":)); 
}


string long_desc() {
   if(!objectp(ETO)) return("Borked!");
   if(TP == ETO) {
     return("%^C248%^This is a %^C123%^p%^C159%^l%^C195%^a%^C159%^t%^C123%^i%^C159%^n%^C195%^u%^C159%^m %^C123%^r%^C159%^i%^C195%^n%^C159%^g %^C248%^with a perfect %^C240%^black stone %^C248%^set in its top. The stone has %^C147%^g%^C105%^l%^C111%^i%^C104%^m%^C153%^m%^C189%^e%^C105%^r%^C147%^s %^C248%^of faint %^C060%^l%^C061%^i%^C062%^g%^C061%^h%^C060%^t %^C248%^dancing through it. It gives off a %^C087%^c%^C123%^o%^C159%^l%^C087%^d a%^C123%^u%^C159%^r%^C087%^a %^C248%^that chills you to the %^C230%^bone%^C248%^. Upon its inner surface, hidden from all but the one that holds it, three %^C124%^b%^C160%^l%^C196%^o%^C160%^o%^C124%^d-r%^C160%^e%^C124%^d t%^C160%^e%^C196%^a%^C160%^r%^C124%^d%^C160%^r%^C196%^o%^C160%^p%^C124%^s %^C248%^have been marked in the bright metal.%^CRST%^");
   }
   return("%^C248%^This is a %^C123%^p%^C159%^l%^C195%^a%^C159%^t%^C123%^i%^C159%^n%^C195%^u%^C159%^m %^C123%^r%^C159%^i%^C195%^n%^C159%^g %^C248%^with a perfect %^C240%^black stone %^C248%^set in its top. The stone has %^C147%^g%^C105%^l%^C111%^i%^C104%^m%^C153%^m%^C189%^e%^C105%^r%^C147%^s %^C248%^of faint %^C060%^l%^C061%^i%^C062%^g%^C061%^h%^C060%^t %^C248%^dancing through it. It gives off a %^C087%^c%^C123%^o%^C159%^l%^C087%^d a%^C123%^u%^C159%^r%^C087%^a %^C248%^that chills you to the %^C230%^bone%^C248%^.");
}