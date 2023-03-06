#include <std.h>
inherit "/std/flying_mount.c";

void create(){
   ::create();
   set_name("shadow drake");
   set_vehicle_short("%^RESET%^%^C059%^shadow %^RESET%^%^C060%^d%^C061%^r%^C062%^a%^C061%^k%^C060%^e%^CRST%^");
   set_short("%^RESET%^%^C059%^shadow %^RESET%^%^C060%^d%^C061%^r%^C062%^a%^C061%^k%^C060%^e%^CRST%^");
   set_id(({"mount","shadow drake","drake"}));
   set_race("drake");
   set_long("%^RESET%^%^CRST%^%^C059%^This large dragon-like creature is covered in gleaming, %^RESET%^%^C060%^d%^C061%^u%^C062%^s%^C061%^k%^C060%^y p%^C061%^u%^C062%^r%^C063%^p%^C061%^l%^C060%^e s%^C061%^c%^C062%^a%^C063%^l%^C061%^e%^C060%^s%^RESET%^%^C059%^. Its head is elongated and pointed with row after row of %^RESET%^%^C230%^sharp teeth %^RESET%^%^C059%^lining its powerful jaws. Its eyes %^RESET%^%^C063%^g%^C069%^l%^C075%^o%^C063%^w %^RESET%^%^C059%^with a fierce intelligence that. Wisps of %^RESET%^%^C240%^s%^C242%^h%^C243%^a%^C242%^d%^C241%^o%^C240%^w %^RESET%^%^C059%^cling to its lean, muscular body, and its powerful legs that end in wicked %^RESET%^%^C240%^claws %^RESET%^%^C059%^capable of tearing through %^RESET%^%^C088%^f%^C124%^l%^C160%^e%^C124%^s%^C088%^h %^RESET%^%^C059%^and %^RESET%^%^C230%^bone%^RESET%^%^C059%^. Its %^RESET%^%^C060%^w%^C063%^i%^C060%^ng%^C060%^s %^C059%^are bat-like and span a considerable distance, enabling it to fly with great speed and agility.%^CRST%^");
   if(random(2)) set_gender("male");
   else set_gender("female");  
   set_exit_room("leaves riding a shadow drake.");
   set_funcs(({"special"}));
   set_func_chance(15);
   TO->force_me("message in enters, breathing whisps of shadow from its nostrils.");
   TO->force_me("message out leaves $D.");
   set_race("drake");
   set_level(10);
   set_value(2000);
   set_riding_level(10);
   add_limb("right foreleg","torso",0,0,0);
   add_limb("left foreleg","torso",0,0,0);
   add_limb("right rear leg","torso",0,0,0);
   add_limb("left rear leg","torso",0,0,0);	
   add_limb("torso","torso",0,0,0);
   add_limb("head","torso",0,0,0);
   set_attack_limbs( ({"right leg","left leg"}) );
   set_damage(1,6);
   set_body_type("dragon");
   set_max_hp(500);
   set_hp(500);
   set_hd(10,4);
   set_overall_ac(-10);
   set_exp(10);
   set_max_distance(200);
   set_flight_delay(900);
   set_flying_prof(30);
   set_ward_pass(25);   
}

void special(object target) {
   tell_room(ETO,"%^RED%^%^BOLD%^The drake unleashes a breath of chilling darkness through the air at "
+target->QCN+"!%^RESET%^",target);
   tell_object(target,"%^RED%^%^BOLD%^The drake unleashes a breath of chilling darkness at "
"you!%^RESET%^");
   TO->set_property("magic",1);
   target->do_damage(target->return_target_limb(),(roll_dice(3,6))+6);
   TO->remove_property("magic");
}
