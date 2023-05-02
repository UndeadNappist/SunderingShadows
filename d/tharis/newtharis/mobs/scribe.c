#include <std.h>
#include <langs.h>

inherit "/std/scribe";

int end_game(string str, object ob, string lang);

void create() {
    ::create();
    set_name("Jerren the scribe");
    set_id(({"scribe","vendor", "Jerren", "jerren"}));
    set_race("human");
    set_gender("male");
    set_short("%^C246%^J%^C245%^e%^C244%^r%^C243%^r%^C245%^e%^C246%^n%^C058%^, Scribe of %^C241%^Tharis%^CRST%^");
    set_long("%^C144%^You see a shortly, %^C243%^g%^C244%^r%^C245%^a%^C246%^n%^C245%^d%^C244%^f%^C243%^a%^C244%^t%^C245%^h%^C246%^e%^C245%^r%^C243%^l%^C244%^y %^C144%^man standing before you. He is a bit thick around the waist, with a sturdy and robust appearance. A pair of %^C136%^wire-rimmed %^C123%^g%^C159%^l%^C195%^a%^C159%^s%^C123%^s%^C159%^e%^C195%^s %^C144%^rest on the bridge of his bulbous, %^C167%^r%^C168%^u%^C169%^d%^C168%^d%^C167%^y %^C144%^nose and his %^C159%^pale blue eyes %^C144%^have a keen intelligence to them. He is dressed in a %^C058%^tweed jacket %^C144%^with elbow patches, paired with a %^C230%^cream%^C144%^-colored tunic and well-tailored, %^C059%^woolen pants%^C144%^. His %^C181%^pate %^C144%^is largely exposed, %^C136%^%^freckles %^C144%^and %^C094%^age spots %^C144%^present on his balding head, and unlike the rest of him his remaining %^C246%^g%^C248%^r%^C250%^a%^C246%^y h%^C248%^a%^C250%^i%^C246%^r %^C144%^is a bit unruly; it sticks out from his head in %^C250%^c%^C255%^l%^C015%^o%^C255%^u%^C250%^d%^C144%^-like tufts. Despite his age, there is a certain %^C094%^v%^C136%^i%^C220%^t%^C226%^a%^C227%^l%^C220%^i%^C136%^t%^C094%^y %^C144%^about him.%^CRST%^ \n%^C136%^He will write anything for you, for a price. Type %^C220%^<write>%^C136%^.  He will %^C220%^<translate [item] to [language] %^C136%^for you. He can also give you an estimate of how much it will cost to translate an item, by using %^C220%^<estimate [item]>%^C136%^.");
    set_level(20);
	set_scribe_name("jerren");
	set_region("newtharis");
	set_body_type("human");
    set_class("mage");
    set("aggressive", 0);
    set_alignment(5);
    set_size(2);
    set_stats("intelligence",18);
    set_stats("wisdom",14);
    set_stats("strength",16);
    set_stats("charisma",18);
    set_stats("dexterity",12);
    set_stats("constitution",16);
    set_max_mp(0);
    set_mp(query_max_mp());
    set_hd(19, 3);
    set_exp(10);
	set_max_hp(1000);
    set_max_hp(query_hp());
    set_max_sp(query_hp());
    set_sp(query_max_sp());
    add_money("silver",random(10));
    add_money("gold",random(5));
    add_money("copper",random(20));
}
