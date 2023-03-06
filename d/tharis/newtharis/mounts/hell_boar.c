
#include <std.h>
inherit "/std/flying_mount.c";

void create(){
   ::create();
   set_name("boar");
   set_id(({"mount","hell boar","boar"}));
   set_short("%^RESET%^%^CRST%^%^C202%^In%^CRST%^%^C208%^fe%^CRST%^%^C166%^rn%^CRST%^%^C202%^al %^CRST%^%^C208%^he%^CRST%^%^C166%^ll %^RESET%^%^C241%^boar%^CRST%^");
   set_long("%^RESET%^%^CRST%^%^C202%^Wr%^CRST%^%^C208%^ea%^CRST%^%^C166%^th%^CRST%^%^C208%^ed %^CRST%^%^C166%^wi%^CRST%^%^C202%^th %^CRST%^%^C208%^he%^CRST%^%^C166%^ll%^CRST%^%^C202%^fi%^CRST%^%^C208%^re%^RESET%^%^C241%^, this infernal boar resembles its more mundane kin, though its flesh is %^RESET%^%^C240%^supernally dark%^CRST%^%^C241%^, its eyes %^CRST%^%^C208%^bl%^CRST%^%^C166%^az%^CRST%^%^C202%^in%^CRST%^%^C208%^g w%^CRST%^%^C166%^it%^CRST%^%^C208%^h a f%^CRST%^%^C166%^ie%^CRST%^%^C202%^ry %^CRST%^%^C208%^he%^CRST%^%^C166%^at %^CRST%^%^C241%^and its %^CRST%^%^C230%^tusks %^RESET%^%^C241%^sharp and sword-like. Low and squat, its powerful form is intimidating, its footfalls striking the ground with %^CRST%^%^C166%^bu%^CRST%^%^C208%^rs%^CRST%^%^C202%^ts %^CRST%^%^C202%^of %^CRST%^%^C166%^fl%^CRST%^%^C208%^am%^CRST%^%^C202%^e%^RESET%^%^C241%^.%^CRST%^");
   set_level(10);
   set_riding_level(10);
   set_value(2000);
   set_race("hell boar");
   set_gender("male");
   set_body_type("equine");
   set_size(3);
   set_max_hp(500);
   set_hd(10,4);
   set_hp(500);
   set_overall_ac(-10);
   set_exp(10);
   set_max_distance(200);
   set_enter_room("rides in.");
   set_exit_room("leaves riding an ill-tempered hell boar.");
   set_vehicle_short("%^RESET%^%^C202%^In%^CRST%^%^C208%^fe%^CRST%^%^C166%^rn%^CRST%^%^C202%^al %^CRST%^%^C208%^he%^CRST%^%^C166%^ll %^RESET%^%^C241%^boar%^CRST%^");
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
