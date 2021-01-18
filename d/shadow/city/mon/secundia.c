#include <std.h>
inherit "/std/vendor";

create() {
   ::create();
   set_name("secundia");
   set_id( ({ "secundia", "clerk", "shop keeper", "shopkeeper"}) );
   set_short("%^YELLOW%^Secundia, The Scriber of Scrolls%^RESET%^");
   set("aggressive", 0);
   set_level(19);
   set_long("%^BOLD%^%^BLACK%^Three mysterious sisters tend to the needs of the guild. The triplets are identical in nearly every way. Dark of skin, Secundia moves effortlessly within the shadows of this dim place, unseen and unheard. Her cropped hair enhances the sharp angles of her statuesque face, and she has a dark, penetrating gaze that could intimidate even the proudest of warriors. When together, the triplets mirror each other's movements and words, lending credit to the rumor that they are three bodies sharing one mind.%^RESET%^");
   set_gender("female");
   set_alignment(6);
   set_race("human");
   add_money("gold", random(500));
   set_body_type("human");
   set_storage_room("/d/shadow/city/storage/ass_scroll_storage");
   set_property("no attack", 1);
   set_hd(19,3);
   set_exp(10);
   set_items_allowed("misc");
   set_max_hp(query_hp());
}
