#include <std.h>
inherit "/std/flying_mount.c";

void create(){
   ::create();
   set_name("nightmare");
   set_vehicle_short("%^RESET%^%^C240%^n%^C241%^i%^C242%^g%^C243%^h%^C244%^t%^C088%^m%^C124%^a%^C160%^r%^C196%^e%^CRST%^");
   set_short("%^RESET%^%^CRST%^%^C244%^Tharisian %^RESET%^%^C240%^n%^C241%^i%^C242%^g%^C244%^t%^C088%^m%^C124%^a%^C160%^r%^C196%^e%^CRST%^");
   set_id(({"mount","nightmare","tharisian nightmare"}));
   set_race("nightmare");
   set_long("%^RESET%^%^CRST%^%^C244%^The %^RESET%^%^C240%^n%^C241%^i%^C242%^g%^C243%^h%^C244%^t%^C088%^m%^CRST%^%^C124%^a%^C160%^r%^C196%^e%^RESET%^%^C244%^, sometimes referred to as a %^RESET%^%^C202%^h%^C208%^e%^C214%^l%^C202%^l %^RESET%^%^C244%^or %^RESET%^%^C088%^d%^C124%^e%^C160%^m%^C124%^o%^C088%^n %^RESET%^%^C244%^horse, is a tall, %^RESET%^%^C240%^coal-black %^RESET%^%^C244%^form composed of lean muscle. However, that is where its resemblance to a mundane horse ends. Its wide maw is full of razor-sharp %^RESET%^%^C230%^teeth %^RESET%^%^C244%^and its eyes are %^RESET%^%^C226%^g%^C227%^l%^C228%^o%^C229%^w%^C228%^i%^C227%^n%^RESET%^%^C226%^g e%^RESET%^%^C227%^m%^C228%^b%^C229%^e%^C227%^r%^C226%^s %^RESET%^%^C244%^of %^RESET%^%^C240%^malevolence%^RESET%^%^C244%^. %^CRST%^%^C088%^Wr%^CRST%^%^C124%^e%^C160%^at%^C160%^h%^CRST%^%^C088%^ed %^RESET%^%^C244%^in %^RESET%^%^C202%^f%^C208%^i%^C226%^r%^C202%^e%^RESET%^%^C244%^, its %^RESET%^%^C202%^m%^CRST%^%^C208%^a%^C220%^n%^C202%^e %^RESET%^%^C244%^is %^RESET%^%^C208%^w%^C220%^i%^C226%^l%^C208%^d %^RESET%^%^C244%^and its %^CRST%^%^C196%^t%^C202%^a%^C226%^i%^C196%^l u%^C202%^n%^C208%^k%^C226%^e%^C208%^m%^C202%^p%^C196%^t%^C244%^, while every footfall and snort produces gouts of %^RESET%^%^C124%^f%^C160%^l%^C202%^a%^C226%^m%^C124%^e%^RESET%^%^C244%^.%^CRST%^");
   if(random(2)) set_gender("male");
   else set_gender("female");  
   set_exit_room("leaves riding a fiery nightmare.");
   set_funcs(({"special"}));
   set_func_chance(15);
   TO->force_me("message in trots in, breathing whisps of flame from its nostrils.");
   TO->force_me("message out trots $D.");
   set_race("nightmare");
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
   set_body_type("equine");
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
   tell_room(ETO,"%^RED%^%^BOLD%^The nightmare unleashes a breath of burning flames through the air at "
+target->QCN+"!%^RESET%^",target);
   tell_object(target,"%^RED%^%^BOLD%^The nightmare unleashes a breath of burning flames through the air at "
"you!%^RESET%^");
   TO->set_property("magic",1);
   target->do_damage(target->return_target_limb(),(roll_dice(3,6))+6);
   TO->remove_property("magic");
}
