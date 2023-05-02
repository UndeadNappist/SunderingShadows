#include <std.h>
#include "../tharis.h"

inherit ROOM;

void init(){
	::init();
	//add_action("search_bookshelf");
	//add_action("buy_map","buy");
	//add_action("buy_map","draw");
}

void create() {
    ::create();
    set_property( "light", 1);
    set_property( "indoors", 1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("%^C022%^A %^C144%^tidy %^C022%^office%^CRST%^");
    set_long("%^C029%^As you enter the scribe's office, you are struck by the orderliness of the space. The room is impeccably organized, with everything in its place. To the left, there are tall %^C241%^cubbies %^C029%^with neatly stacked %^C195%^vellum%^C029%^, %^C144%^parchment%^C029%^, and %^C231%^linen papers%^C029%^, each labeled with its type and size. On the right are built-in %^C240%^bookshelves %^C029%^that house an expansive collection of %^C058%^books%^C029%^. The papers are arranged in perfect order, with no edges sticking out or any sign of disorder. In the center of the room, there is a large, sturdy %^C130%^wooden desk%^C029%^. The surface is %^C015%^clean %^C029%^and tidy, with all the necessary supplies arranged in a systematic manner. Above the desk hangs a stunning %^C220%^g%^C226%^o%^C227%^l%^C228%^d%^C226%^e%^C220%^n c%^C226%^h%^C227%^a%^C228%^n%^C227%^d%^C226%^e%^C220%^l%^C226%^i%^C227%^e%^C228%^r %^C029%^adorned with %^C123%^g%^C159%^l%^C195%^a%^C159%^s%^C123%^s crystals %^C029%^in a variety of %^C124%^c%^C202%^o%^C226%^l%^C034%^o%^C033%^r%^C063%^s%^C029%^. The %^C228%^l%^C229%^i%^C230%^g%^C229%^h%^C228%^t %^C029%^that filters through the crystals creates a dazzling display on the walls and %^C241%^floor%^C029%^. The bottom half of the walls are paneled with %^C240%^dark%^C029%^, rich %^C241%^w%^C242%^o%^C243%^o%^C241%^d %^C029%^and the top half of the walls and ceiling are covered in a stunning depiction of a %^C028%^j%^C034%^u%^C040%^n%^C046%^g%^C034%^l%^C028%^e %^C029%^scene in %^C022%^deep e%^C023%^m%^C024%^e%^C030%^r%^C031%^a%^C024%^l%^C023%^d%^C022%^s%^C029%^.\n%^CRST%^");
    set_smell("default","%^C136%^You smell the odors of pen ink and paper.%^CRST%^");
    set_listen("default","%^C130%^You hear the sounds of papers being shuffled.%^CRST%^");
    set_exits( ([
      //"southeast": ROOMS"serpentnest"
        ]) );
    set_items(([
	({"bookshelves","books", "shelves"}) : "%^C143%^These %^C240%^shelves %^C143%^contain a number of reference %^C058%^books %^C143%^on subjects ranging from languages and geography to math and science. They also appear to hold some of the scribe’s own personal collection.%^CRST%^",
	({"supplies","ink", "quills"}) : "%^C144%^Out and ready for use for use are %^C123%^p%^C195%^o%^C195%^t%^C123%^s %^C144%^containing an assortment of ink in every %^C124%^c%^C202%^o%^C226%^l%^C040%^o%^C027%^r%^C144%^, each labeled and organized by hue, next to a row of %^C241%^q%^C242%^u%^C243%^i%^C244%^l%^C242%^l%^C241%^s %^C144%^that are sorted by size and shape. There are also %^C167%^s%^C168%^t%^C169%^a%^C169%^m%^C168%^p%^C167%^s %^C144%^and %^C231%^waxes %^C144%^neatly arranged in a row.%^CRST%^",
	({"archway", "entry"}) : "%^C241%^This room is accessible via an elegant archway bordered by %^C240%^ebony wood%^C241%^. The wood is smooth and g%^C242%^l%^C243%^o%^C244%^s%^C242%^s%^C241%^y, with a deep %^C240%^black color%^C241%^.%^CRST%^",
	({"paper", "vellum", "parchment", "linen"}) : "%^C094%^The parchment is a creamy %^C231%^off-white %^C094%^color, the vellum nearly %^C195%^translucent %^C094%^and almost ethereal, while the linen is a light %^C144%^beige %^C094%^with a slight texture.%^CRST%^",
    ({"paneling", "wood paneling"}) : "%^C244%^The walls of the room are lined with a %^C240%^dark wooden %^C244%^paneling, polished to a %^C248%^r%^C244%^e%^C246%^f%^C250%^l%^C248%^e%^C246%^c%^C252%^t%^C248%^i%^C244%^v%^C250%^e %^C244%^s%^C246%^h%^C248%^i%^C250%^n%^C252%^e%^C244%^. The paneling runs about halfway up the walls, giving the room a feeling of %^C240%^depth %^C244%^and %^C241%^d%^C242%^i%^C243%^m%^C244%^e%^C245%^n%^C246%^s%^C243%^i%^C242%^o%^C241%^n%^C244%^.%^CRST%^",
	"chandelier" : "%^C136%^As you enter the room, your eyes are immediately drawn to the extravagant %^C220%^g%^C226%^o%^C227%^l%^C228%^d%^C226%^e%^C220%^n c%^C226%^h%^C227%^a%^C228%^n%^C227%^d%^C226%^e%^C220%^l%^C226%^i%^C227%^e%^C228%^r %^C136%^that hangs from the ceiling. It features multiple tiers of arms extending from a central hub, each with its own set of %^C231%^candles %^C136%^alight with flickering %^C160%^f%^C161%^a%^C162%^e%^C163%^r%^C164%^i%^C200%^e %^C199%^f%^C198%^i%^C197%^r%^C196%^e%^C136%^. Hanging from the chandelier are numerous %^C123%^g%^C159%^l%^C195%^a%^C159%^s%^C123%^s c%^C159%^r%^C195%^y%^C159%^s%^C123%^t%^C159%^a%^C195%^l %^C159%^t%^C123%^e%^C159%^a%^C195%^r%^C159%^d%^C123%^r%^C159%^o%^C195%^p%^C159%^s%^C136%^, arranged in a pattern, with larger pieces towards the bottom and smaller pieces towards the top. They are a kaleidoscope of colors, including %^C027%^d%^C033%^e%^C039%^e%^C027%^p b%^C033%^l%^C039%^u%^C033%^e%^C027%^s%^C136%^, %^C034%^v%^C040%^i%^C046%^b%^C082%^r%^C046%^a%^C040%^n%^C034%^t g%^C040%^r%^C046%^e%^C082%^e%^C046%^n%^C034%^s%^C136%^, and %^C124%^v%^C160%^i%^C196%^v%^C160%^i%^C124%^d r%^C160%^e%^C196%^d%^C124%^s%^C136%^. As the light from the chandelier filters through the glass, it creates a stunning display of %^C124%^r%^C202%^a%^C226%^i%^C040%^n%^C027%^b%^C069%^o%^C057%^w %^C136%^reflections across the walls and ceiling of the room. The prisms are not overpowering, but rather a %^C183%^s%^C231%^u%^C195%^b%^C194%^t%^C225%^l%^C189%^e %^C136%^and %^C039%^m%^C045%^a%^C051%^g%^C087%^i%^C081%^c%^C075%^a%^C069%^l %^C136%^touch that adds to the ambiance of the room.%^CRST%^",
	"cubbies" : "%^C244%^As you walk into the room, your attention is immediately drawn to the left wall. Here are several %^C240%^cubbies%^C244%^, each one housing a variety of different %^C144%^p%^C015%^a%^C195%^p%^C231%^e%^C015%^r%^C144%^s%^C244%^. The cubbies are organized neatly by type and size, creating an orderly and efficient system for storing papers. The cubbies are made of a rich, %^C240%^dark wood %^C244%^that matches the paneling along the bottom half of the walls and complements the %^C130%^desk %^C244%^perfectly. Each type of paper has its dedicated place, with %^C094%^b%^C220%^r%^C226%^a%^C220%^s%^C094%^s p%^C220%^l%^C226%^a%^C227%^ca%^C226%^r%^C220%^d%^C094%^s %^C244%^marking their respective types and sizes.%^CRST%^ ",
	"desk" : "%^C136%^The deep, rich color of the %^C130%^oak desk %^C136%^is both elegant and commanding, making it the perfect centerpiece for this %^C029%^room%^C136%^. The body of the desk is adorned with delicate %^C094%^scrollwork %^C136%^and %^C136%^relief carvings%^C136%^, which add an extra layer of depth and texture to the piece. The carvings are precise and detailed, showcasing the skill and craftsmanship of the artist. Each curve and line is purposeful, creating a sense of movement and flow that draws the eye. The four corners of the piece feature large %^C022%^j%^C028%^u%^C034%^n%^C040%^g%^C028%^l%^C022%^e %^C220%^c%^C241%^a%^C094%^t%^C220%^s %^C136%^sitting back on their haunches, their front legs outstretched, and their %^C230%^clawed %^C136%^paws depicted as supporting the heavy desktop. It has ample space for %^C241%^writing %^C136%^or working, with several %^C094%^drawers %^C136%^and %^C130%^compartments %^C136%^for additional storage.%^CRST%^",
	"mural" : "%^C022%^The %^C028%^j%^C034%^u%^C040%^n%^C046%^g%^C034%^l%^C028%^e %^C022%^themed mural is a magnificent sight to behold, with intricate designs that depict a lush, %^C040%^v%^C046%^e%^C082%^r%^C083%^d%^C082%^a%^C046%^n%^C040%^t %^C022%^landscape teeming with life. Its color is predominantly deep e%^C023%^m%^C024%^e%^C030%^r%^C031%^a%^C024%^l%^C023%^d%^C022%^, with %^C040%^l%^C046%^i%^C083%^g%^C048%^h%^C047%^t%^C082%^e%^C046%^r %^C040%^s%^C082%^h%^C047%^a%^C048%^d%^C083%^e%^C040%^s %^C022%^of green intermingling to create a sense of depth and texture. %^C028%^P%^C029%^e%^C030%^a%^C031%^c%^C027%^o%^C026%^c%^C025%^k%^C024%^s %^C022%^are the star of the show, with their %^C021%^bright %^C022%^and %^C029%^beautiful %^C022%^feathers strutting across the walls. The intricate detailing of each feather is breathtaking, with rich hues of %^C021%^b%^C027%^l%^C033%^u%^C026%^e%^C025%^s%^C022%^, %^C028%^g%^C029%^r%^C030%^e%^C036%^e%^C035%^n%^C034%^s%^C022%^, and %^C054%^p%^C055%^u%^C056%^r%^C057%^p%^C056%^l%^C055%^e%^C054%^s %^C022%^that shimmer in the light. Stalking %^C220%^j%^C241%^a%^C226%^g%^C240%^u%^C136%^a%^C241%^r%^C220%^s %^C022%^hide amongst the %^C046%^foliage%^C022%^, keeping a watchful eye on their surroundings. %^C094%^B%^C095%^e%^C096%^e%^C149%^t%^C148%^l%^C142%^e%^C136%^s %^C022%^are scattered throughout the mural, adding an extra layer of intricacy to the design. They are depicted in a variety of sizes and colors, each one unique and distinct. From %^C046%^i%^C047%^r%^C048%^i%^C049%^d%^C050%^e%^C086%^s%^C085%^c%^C084%^e%^C083%^n%^C082%^t %^C046%^g%^C047%^r%^C048%^e%^C049%^e%^C050%^n%^C086%^s %^C022%^to %^C136%^m%^C220%^e%^C226%^t%^C227%^al%^C226%^l%^C220%^i%^C136%^c g%^C220%^o%^C226%^l%^C220%^d%^C136%^s%^C022%^, the beetles bring an extra dimension to the design. The mural is so detailed that you can almost feel the %^C214%^w%^C220%^a%^C226%^r%^C227%^m%^C220%^t%^C214%^h %^C022%^of the %^C226%^s%^C228%^u%^C226%^n %^C022%^on your face and the %^C094%^humidity %^C022%^of the jungle in the air.%^CRST%^",
	"floor" : "%^C241%^The floor is made from p%^C242%^o%^C243%^l%^C244%^i%^C245%^s%^C243%^h%^C242%^e%^C241%^d %^C240%^black marble%^C241%^.%^CRST%^",
    "sign":"%^C136%^There is a sign written in %^C220%^f%^C226%^l%^C227%^o%^C228%^w%^C227%^i%^C226%^n%^C220%^g s%^C226%^c%^C227%^r%^C228%^i%^C226%^p%^C220%^t %^C136%^on the desk, it reads:\n\n%^C220%^""I can %^C226%^write%^C220%^ for you anything you wish in any written language.\n\nTranslating services also available."
	]));
}
// int buy_map(string str){
//	int amount;
//	amount = 5;
//	if(str != "map") return notify_fail("draw what?\n");
//  if(!present("scribe")) return notify_fail("Nobody is here to draw you a map.\n");
//	if(TP->query_money("gold") < amount)
//	return notify_fail("You don't have "+amount+" gold!\n");
//	write("The Scribe hands you a map of Tharis.");
//      tell_room(ETP,"The Scribe hands "+TPQCN+" a piece of paper.",TP);
//	new("/d/tharis/newtharis/obj/citymap")->move(TP);
//	return 1;
//  }
void reset(){
   ::reset();
   if(!present("scribe")){
     new("/d/tharis/newtharis/mobs/scribe.c")->move(TO);
   }
}
