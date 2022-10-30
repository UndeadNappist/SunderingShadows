#include <std.h>
inherit BARKEEP;

void create() {
    ::create();
    set_property("no bump", 1);
    set_name("grubb");
    set_id( ({ "grubb", "Grubb","barkeep" }) );
    set_short("%^RESET%^%^C167%^Grubb%^RESET%^%^C130%^, spitmaster of the %^RESET%^%^C088%^T%^C124%^u%^C160%^r%^C196%^n%^C202%^i%^C124%^n%^RESET%^%^C088%^g S%^RESET%^%^C124%^p%^C160%^i%^RESET%^%^C088%^t%^CRST%^");
    set("aggressive", 0);
    set_level(12);
    set_long("%^RESET%^%^C130%^This %^RESET%^%^C107%^dumpy %^RESET%^%^C130%^looking little %^RESET%^%^C167%^reptile %^RESET%^%^C130%^is an enigma for his kind; where most are %^RESET%^%^C167%^s%^C174%^l%^C181%^i%^RESET%^%^C188%^g%^RESET%^%^C174%^h%^C167%^t%^RESET%^%^C130%^, %^RESET%^%^C076%^c%^C077%^u%^C078%^n%^C079%^n%^C078%^i%^C077%^n%^C076%^g%^RESET%^%^C130%^, and %^RESET%^%^C088%^m%^C124%^a%^C160%^l%^C124%^i%^C088%^c%^C124%^i%^C160%^o%^C124%^u%^C088%^s%^RESET%^%^C130%^, this little fellow is round and %^RESET%^%^C220%^j%^C226%^o%^v%^RESET%^%^C227%^i%^C226%^a%^RESET%^%^C220%^l%^RESET%^%^C130%^, garbed in what once may have been %^RESET%^%^C231%^chef's finery%^RESET%^%^C130%^. While on a normal man his %^RESET%^%^C015%^white coat %^RESET%^%^C130%^would appear %^RESET%^%^C241%^d%^C255%^a%^C250%^p%^C241%^p%^RESET%^%^C255%^e%^RESET%^%^C250%^r%^RESET%^%^C130%^, the diminutive stature of this kobold leaves it looking unquestionably tragic, as though a particularly ugly child were playing dress-up. The %^RESET%^%^C015%^hat%^RESET%^%^C130%^, likely once refined, is now %^RESET%^%^C108%^stained %^RESET%^%^C130%^and too large for the kobold, often falling over one of his beady, %^RESET%^%^C131%^incarnadine eyes%^RESET%^%^C130%^. His %^RESET%^%^C124%^bl%^C160%^oo%^RESET%^%^C124%^d%^RESET%^%^C130%^-%^RESET%^%^C088%^s%^RESET%^%^C124%^p%^C160%^a%^RESET%^%^C196%^t%^RESET%^%^C160%^t%^C124%^e%^RESET%^%^C088%^r%^RESET%^%^C124%^e%^C160%^d %^RESET%^%^C058%^apron %^RESET%^%^C130%^drags along the ground, creating a clownish aesthetic for what is normally a dangerous little beast. Happily %^RESET%^%^C230%^c%^C231%^h%^C015%^i%^RESET%^%^C231%^t%^C230%^t%^C231%^e%^RESET%^%^C015%^r%^C231%^i%^RESET%^%^C230%^n%^RESET%^%^C231%^g %^RESET%^%^C130%^away, he wields a %^RESET%^%^C249%^meat cleaver %^RESET%^%^C130%^in each hand, and his %^RESET%^%^C167%^knobby tail %^RESET%^%^C130%^undulates behind him as he moves from spit to spit, turning the %^RESET%^%^C124%^m%^C160%^e%^C196%^a%^RESET%^%^C124%^t %^RESET%^%^C130%^and carving great %^RESET%^%^C094%^chunks %^RESET%^%^C130%^from the carcasses with relish!%^CRST%^");
    set_gender("male");
    set_alignment (1);
    set_race("kobold");
    set_hp(300);
    add_money("gold", random(200));
    set_body_type("kobold");
    set_currency("silver");
    set_menu(
        ({
	     "fire roasted nuts","tharisian dark lager","verbonese ale","traveler's meal","spit turned meat","cravnarian wine",
        }),
        ({ "food", "alcoholic", "alcoholic","food","food","alcoholic",}),
        ({ 30, 30, 15, 15, 20, 25, 65})
    );
    set_my_mess(
        ({
       "You crunch the roasted nuts as your chew.",
       "You drink the extremely dark, thick lager and feel it as it rolls down your throat.",
       "You drink the golden ale and wince at the slight bite it offers back.",
       "You eat the sparse but painfully healthy meal.",
       "You eat the tender well cooks piece of spicey meat with lust and vigor.",
       "You drink down the red tinted ale quickly in a single gulp.",
        })
    );
    set_your_mess(
        ({
          "crunches on some nuts.",
	      "pours the thick dark brew down "+TP->query_possessive()+" gullet.",
	      "drinks the golden ale slowly.",
	      "eats the sparse yet healthy looking meal.",
          "tears into the fragrant meat fresh from the spit.",
	      "gulps down the red tinted wine.",
        })
    );
    set_menu_short(
        ({
          "Fire Roasted Nuts",
	      "Tharisian Dark Lager",
	      "Verbonese Ale",
	      "Traveler's Meal",
   	      "Spit Turned Meat",
	      "Cravnarian Wine",
        })
    );
    set_menu_long(
        ({
       "This is a small package of various nuts that are roast along with the meat on the spit.",
       "This is a dark dark dark brew, famous to Tharis. this brew doesn't even slosh it sorta oozes.",
       "This is the golden ale imported from the city of Verbone across the ocean.",
       "This is a well packaged little meal made of more nutrious stuffs for the active traveler.",
       "This is a grand hunk of sizzling, well spiced meat from the spit at the Turning Spit Tavern.",
       "This is a small glass of imported wine from the legendary ciy of Cravnari, the sister city to Tharis to the south of the mountains.",
        })
    );
    set_emotes(2,({
    "%^RESET%^%^C143%^A %^RESET%^%^C241%^fly b%^RESET%^%^C242%^u%^C243%^z%^C244%^z%^C242%^e%^RESET%^%^C241%^s %^RESET%^%^C143%^near one of the %^RESET%^%^C094%^carcasses%^RESET%^%^C143%^. With a %^RESET%^%^C088%^v%^C124%^i%^C160%^c%^RESET%^%^C196%^i%^C160%^o%^C124%^u%^RESET%^%^C088%^s s%^RESET%^%^C124%^n%^RESET%^%^C160%^a%^C124%^r%^RESET%^%^C088%^l%^RESET%^%^C143%^, Grubb smacks it with the flat of one of his %^RESET%^%^C249%^cleavers%^RESET%^%^C143%^. He looks around slyly before %^RESET%^%^C174%^licking %^RESET%^%^C143%^the %^RESET%^%^C150%^g%^C149%^u%^RESET%^%^C148%^t%^RESET%^%^C150%^s %^RESET%^%^C143%^off the knife.%^CRST%^",
    "%^RESET%^%^C167%^Grubb shaves a few pieces of %^RESET%^%^C130%^rothe haunch %^RESET%^%^C167%^onto a plate, tossing it unceremoniously onto the counter. A waitress collects the order and brings it to a table of %^RESET%^%^C178%^d%^C220%^r%^C226%^u%^C227%^n%^C226%^k%^RESET%^%^C220%^e%^C178%^n s%^RESET%^%^C220%^a%^C226%^i%^C227%^l%^C226%^o%^C220%^r%^RESET%^%^C178%^s%^RESET%^%^C167%^.%^CRST%^",
    "%^RESET%^%^C136%^A %^RESET%^%^C124%^r%^C160%^o%^C196%^a%^RESET%^%^C124%^r %^RESET%^%^C136%^of %^RESET%^%^C124%^laughter %^RESET%^%^C136%^erupts from a nearby %^RESET%^%^C094%^table %^RESET%^%^C136%^after a patron %^RESET%^%^C168%^p%^C169%^i%^C170%^n%^C171%^c%^RESET%^%^C170%^h%^C169%^e%^RESET%^%^C168%^s %^RESET%^%^C136%^the rear of a nearby waitress and she returns the favor by upending his %^RESET%^%^C220%^ale %^RESET%^%^C136%^over his head, leaving him %^RESET%^%^C220%^s%^C221%^p%^C222%^u%^C223%^t%^C222%^t%^C221%^e%^C220%^r%^C221%^i%^RESET%^%^C222%^n%^C223%^g%^RESET%^%^C136%^.%^CRST%^",}), 0);
} 

