#include <std.h>
inherit "/d/magic/symbols/holy_symbol.c";

void create(){
   ::create();
   set_id(({"holy symbol","symbol","kismet_holy_symbol","pendant","silver pendant"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_name("A pendant emblazoned with a scroll and quill");
   set_short("%^RESET%^%^C123%^A %^RESET%^%^C253%^p%^RESET%^%^C252%^e%^C251%^n%^C250%^d%^C251%^a%^C252%^n%^RESET%^%^C253%^t %^RESET%^%^C123%^emblazoned with a %^RESET%^%^C230%^scroll %^RESET%^%^C123%^and %^RESET%^%^C241%^q%^C242%^u%^C243%^i%^C242%^l%^C241%^l%^CRST%^");
   set_long("%^RESET%^%^CRST%^%^C123%^This %^RESET%^%^C253%^s%^C252%^i%^C251%^l%^C249%^v%^C252%^e%^RESET%^%^C253%^r p%^RESET%^%^C252%^e%^C251%^n%^C250%^d%^C251%^a%^C252%^n%^RESET%^%^C253%^t %^RESET%^%^C123%^is strung upon a %^RESET%^%^C144%^leather cord%^RESET%^%^C123%^, %^RESET%^%^C082%^p%^C070%^e%^C076%^r%^C070%^i%^C082%^d%^C070%^o%^C076%^t%^RESET%^%^C070%^s %^RESET%^%^C123%^bordering its rectangular perimeter. Proudly displayed upon the center of this %^RESET%^%^C250%^silver plane %^RESET%^%^C123%^is an %^RESET%^%^C230%^ivory inlay %^RESET%^%^C123%^depicting a %^RESET%^%^C230%^r%^C015%^o%^C230%^ll%^C015%^e%^RESET%^%^C230%^d scr%^RESET%^%^C015%^o%^C230%^ll%^RESET%^%^C123%^. Crossing the scroll is a %^RESET%^%^C241%^jetstone quill %^RESET%^%^C123%^plumed with an %^RESET%^%^C241%^ostentatious f%^RESET%^%^C242%^e%^C243%^a%^C244%^t%^C243%^h%^C242%^e%^RESET%^%^C241%^r%^RESET%^%^C123%^, its nib as sharp as the tip of any sword.%^CRST%^");
}