#include <std.h>

inherit "/std/riding_animal";

void create(){
  ::create();
  set_id(({"lizard","animal"}));
  set_name("sleek riding lizard");
  set_short("%^RESET%^%^C058%^Large riding %^RESET%^%^C064%^l%^C070%^i%^C072%^z%^C077%^a%^C070%^r%^C064%^d%^CRST%^");
  set_long("%^RESET%^%^CRST%^%^C058%^This %^RESET%^%^C064%^riding lizard %^RESET%^%^C058%^is a large reptile about 20 feet long, its tail alone responsible for at least half that length. It has a slightly elongated neck and a flat head, its %^RESET%^%^C076%^moss%^RESET%^%^C058%^-%^RESET%^%^C064%^g%^C065%^r%^C071%^e%^C065%^e%^C064%^n %^RESET%^%^C058%^body pebbled with %^RESET%^%^C023%^warty growths %^RESET%^%^C058%^and %^RESET%^%^C029%^spiky protrusions%^RESET%^%^C058%^. While shorter, its snout is not unlike that of an alligator, numerous %^RESET%^%^C230%^yellow teeth %^RESET%^%^C058%^protruding visibly from its powerful jaws even when its mouth is closed. It observes its surroundings with emotionless, round %^RESET%^%^C088%^umber%^RESET%^%^C058%^-colored eyes, occasionally tasting the air with its long, %^RESET%^%^C174%^forked tongue%^RESET%^%^C058%^. The lizard has four-toed feet ending in %^RESET%^%^C124%^r%^C160%^a%^C196%^z%^C160%^o%^C124%^r%^RESET%^%^C058%^-sharp %^RESET%^%^C059%^claws %^RESET%^%^C058%^that click audibly against the ground as it walks. %^CRST%^");
  set_value(500);
  set_race("lizard");
  set_body_type("equine");
  set_max_hp(80);
  set_hd(1,6);
  set_max_distance(500);
  set_enter_room(" rides in.");
  set_exit_room("leaves riding a large lizard.");
  set_vehicle_short("%^RESET%^%^C058%^Large riding %^RESET%^%^C064%^l%^C070%^i%^C072%^z%^C077%^a%^C070%^r%^C064%^d%^CRST%^");
  set_riding_level(8);
}
