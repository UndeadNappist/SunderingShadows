#include <std.h>

inherit "/std/riding_animal";

void create(){
  ::create();
  set_id(({"bicorn","animal"}));
  set_name("bicorn");
  set_short("%^RESET%^%^C242%^S%^C241%^l%^C240%^e%^C242%^e%^C241%^k %^CRST%^%^C240%^bic%^C124%^o%^C240%^rn%^RESET%^");
  set_long("%^RESET%^%^CRST%^%^C242%^This beast is the %^RESET%^%^C059%^umbral %^RESET%^%^C242%^offspring resulting from the unholy coupling of a %^RESET%^%^C153%^fey %^RESET%^%^C231%^u%^C183%^n%^C230%^i%^C231%^c%^C195%^o%^C189%^r%^C231%^n %^RESET%^%^C242%^and a %^RESET%^%^C088%^d%^C124%^e%^C160%^m%^C196%^o%^n%^C124%^i%^C088%^c %^RESET%^%^C240%^nightmare%^RESET%^%^C242%^. This specimen stands 16 hands tall, its sleek, %^RESET%^%^C240%^dark coat %^RESET%^%^C242%^contrasting beautifully against its %^RESET%^%^C250%^s%^C248%^i%^C246%^l%^C248%^v%^C250%^e%^C248%^r%^C246%^y %^RESET%^%^C248%^m%^C250%^a%^C248%^n%^C246%^e%^RESET%^%^C242%^. Though majestic of body, its powerful, %^RESET%^%^C240%^s%^C242%^i%^C243%^n%^C244%^u%^C243%^o%^C242%^u%^C240%^s %^RESET%^%^C242%^form conveys all that it means to be %^RESET%^%^C240%^fell%^RESET%^%^C242%^; %^RESET%^%^C088%^bl%^C124%^a%^C160%^z%^C196%^i%^C124%^n%^C088%^g e%^RESET%^%^C124%^y%^C160%^e%^C088%^s %^RESET%^%^C242%^and dual %^CRST%^%^C244%^h%^C242%^e%^C240%^l%^C242%^i%^C244%^c%^C242%^a%^C240%^l %^RESET%^%^C242%^h%^C244%^o%^C242%^r%^C240%^n%^C244%^s %^RESET%^%^C242%^conveying an aesthetic of %^RESET%^%^C060%^m%^C061%^a%^C062%^l%^C063%^i%^C062%^g%^C061%^n%^C060%^ed br%^RESET%^%^C061%^u%^C062%^t%^C063%^a%^C062%^l%^C061%^i%^C060%^ty%^RESET%^%^C242%^.%^RESET%^");
  set_value(500);
  set_race("bicorn");
  set_body_type("equine");
  set_max_hp(80);
  set_hd(1,6);
  set_max_distance(500);
  set_enter_room(" rides in.");
  set_exit_room("leaves riding a spirited bicorn.");
  set_vehicle_short("bicorn");
  set_riding_level(15);
}
