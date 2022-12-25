#include <std.h>
inherit "/d/magic/symbols/holy_symbol.c";

void create(){
   ::create();
   set_id(({"holy symbol","symbol","callamir_holy_symbol","pendant","quartz pendant","quartziferous pendant","rabbit pendant","quartziferous rabbit pendant"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   // A quartziferous rabbit pendant
   set_name("%^C255%^A q%^C253%^u%^C255%^ar%^C253%^t%^C251%^z%^C255%^ife%^C159%^r%^C255%^ous ra%^C253%^b%^C255%^b%^C159%^i%^C255%^t pe%^C253%^n%^C255%^da%^C251%^n%^C255%^t%^CRST%^");
   set_short("%^C255%^A q%^C253%^u%^C255%^ar%^C253%^t%^C251%^z%^C255%^ife%^C159%^r%^C255%^ous ra%^C253%^b%^C255%^b%^C159%^i%^C255%^t pe%^C253%^n%^C255%^da%^C251%^n%^C255%^t%^CRST%^");
   // A thin silver thread loops around the hare-shaped stone, whose legs are outstretched in defiance of its bondage.
   // When observed from afar, its wearers movements lend it a lifelike bounce, while the cloudy-white coloration of the quartz appears to paint a fluffy texture over its lapine form.
   // Up close, the dusting of arandur flakes embedded within the misty crystal becomes more visible; congregated chiefly in its eye, the shavings conspire to create a mischievous twinkle.
   set_long("%^C037%^A %^C255%^th%^C253%^i%^C251%^n%^C255%^ si%^C253%^l%^C251%^v%^C255%^er th%^C253%^r%^C251%^e%^C255%^ad%^RESET%^%^C037%^ loops around the %^C255%^ha%^C253%^r%^C255%^e-sh%^C251%^a%^C255%^p%^C253%^e%^C255%^d sto%^C251%^n%^C255%^e%^RESET%^%^C037%^, whose legs are outs%^C044%^tret%^C051%^ched%^RESET%^%^C037%^ in defiance of its bondage. When observed from afar, its wearers movements lend it a %^C035%^l%^C041%^if%^C047%^el%^C041%^ik%^C035%^e%^RESET%^%^C037%^ bounce, while the %^C255%^clo%^C253%^u%^C255%^d%^C251%^y%^C255%^-w%^C253%^h%^C255%^i%^C251%^t%^C255%^e co%^C253%^l%^C255%^o%^C250%^r%^C255%^at%^C253%^i%^C255%^on%^RESET%^%^C037%^ of the %^C255%^q%^C253%^u%^C255%^ar%^C251%^t%^C255%^z%^RESET%^%^C037%^ appears to paint a fluffy texture over its lapine form. Up close, the dusting of %^C195%^ara%^C051%^n%^C195%^d%^C050%^u%^C195%^r fl%^C049%^a%^C195%^k%^C048%^e%^C195%^s%^RESET%^%^C037%^ embedded within the %^C255%^mis%^C253%^t%^C255%^y cr%^C253%^y%^C255%^st%^C251%^a%^C255%^l%^RESET%^%^C037%^ becomes more visible; congregated chiefly in its eye, the shavings conspire to create a mi%^C044%^s%^RESET%^%^C037%^c%^C051%^h%^RESET%^%^C037%^i%^C044%^e%^RESET%^%^C037%^vo%^C087%^u%^RESET%^%^C037%^s tw%^C044%^i%^RESET%^%^C037%^n%^C051%^k%^RESET%^%^C037%^le.%^RESET%^");
}
