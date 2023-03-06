//Faebala 03/05/23 - Tharis flying mount

#include <std.h>
inherit "/std/flying_mount.c";

void create(){
   ::create();
   set_name("dire bat");
   set_id(({"mount","dire bat","bat"}));
   set_short("%^RESET%^%^CRST%^%^C015%^Alb%^C225%^i%^C015%^n%^C231%^o %^RESET%^%^C015%^d%^C225%^i%^C015%^r%^C189%^e %^RESET%^%^C015%^b%^C225%^a%^RESET%^%^C015%^t%^CRST%^");
   set_long("%^RESET%^%^C252%^A truly gigantic specimen, this %^RESET%^%^CRST%^%^C015%^alb%^C225%^i%^C015%^n%^C231%^o %^RESET%^%^C015%^d%^C225%^i%^C015%^r%^C189%^e %^RESET%^%^C015%^b%^C225%^a%^RESET%^%^C015%^t %^RESET%^%^C252%^stands seven feet tall. It has large semi-%^RESET%^%^C225%^transparent ears %^RESET%^%^C252%^and beady %^RESET%^%^C124%^e%^C196%^y%^C124%^es %^CRST%^%^C252%^glowing with %^RESET%^%^C088%^m%^C124%^a%^C160%^l%^C196%^i%^C124%^c%^C088%^e%^RESET%^%^C252%^. Its body is covered in short %^RESET%^%^C015%^white fur %^RESET%^%^C252%^and it crawls along with surprising agility. When fully extended, the %^RESET%^%^C225%^wings %^RESET%^%^C252%^of this creature would dwarf any man and its sharp %^RESET%^%^C230%^talons %^RESET%^%^C252%^could rend with ease.%^RESET%^");
   set_level(10);
   set_riding_level(10);
   set_value(2000);
   set_race("dire bat");
   set_gender("female");
   set_body_type("equine");
   set_size(3);
   set_max_hp(500);
   set_hd(10,4);
   set_hp(500);
   set_overall_ac(-10);
   set_exp(10);
   set_max_distance(200);
   set_enter_room("rides in.");
   set_exit_room("leaves riding a massive dire bat.");
   set_vehicle_short("%^RESET%^%^CRST%^%^C015%^An %^RESET%^%^C225%^alb%^C225%^i%^C015%^n%^C231%^o %^RESET%^%^C015%^d%^C225%^i%^C015%^r%^C189%^e %^RESET%^%^C015%^b%^C225%^a%^RESET%^%^C015%^t%^CRST%^");
   add_limb("snout","head",0,0,0);
   add_limb("right leg","torso",0,0,0);
   add_limb("left leg","torso",0,0,0);
   add_limb("torso","torso",0,0,0);
   add_limb("head","torso",0,0,0);
   set_attack_limbs( ({"snout","right leg","left leg"}) );
   set_attacks_num(3);
   set_damage(2,6);
   set_flight_delay(300);
   set_flying_prof(25);
   set_ward_pass(25);
}