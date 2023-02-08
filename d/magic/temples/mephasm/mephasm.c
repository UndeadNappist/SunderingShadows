// Chernobog (2/7/23)
// Temple to Mephasm
// Written by Vuzan

#include <std.h>
#include <player_housing.h>
inherit "/std/temple";

void create(){
    ::create();
    set_terrain(BEACH);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_temple("mephasm");
    set_name("The Temple of Mephasm");
    set_short("%^RESET%^%^CRST%^%^C243%^The%^RESET%^ %^C088%^T%^C124%^e%^C160%^m%^C196%^p%^C160%^l%^C124%^e%^RESET%^ %^C088%^of%^RESET%^ %^C088%^M%^C124%^e%^C160%^p%^C196%^h%^C160%^a%^C124%^s%^C088%^m%^RESET%^%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C243%^The sight that greets the eye once the threshold is crossed to this place of worship seems carefully arranged to be impressive. Polished floor of black marble reflects what passes above it, giving the%^RESET%^ %^C095%^e%^C131%^e%^C167%^r%^C203%^i%^C217%^e%^RESET%^ %^C243%^sensation of walking upon a dark, distorted%^RESET%^ %^C088%^m%^C124%^i%^C160%^r%^C196%^r%^C160%^o%^C124%^r%^C243%^. High, gothic arches frame the ceiling and the stained glass windows that cast%^RESET%^ %^C088%^d%^C124%^a%^C160%^r%^C196%^k%^RESET%^ %^C160%^r%^C124%^e%^C088%^d%^RESET%^ %^C243%^and%^RESET%^ %^C241%^black%^RESET%^ %^C243%^lights upon all within this chamber. The roof seems to be a mesh of supporting crosses for a plethora of skylights, similarly stained in aesthetic%^RESET%^ %^C088%^r%^C124%^e%^C160%^d%^C196%^s%^RESET%^ %^C243%^and%^RESET%^ %^C241%^blacks%^C243%^, that let in all of the light from outdoors - largely to assist in feeding the myriad%^RESET%^ %^C065%^p%^C107%^l%^C150%^a%^C192%^nt%^C150%^e%^C107%^r%^C065%^s%^RESET%^ %^C243%^of carefully maintained%^RESET%^ %^C095%^f%^C131%^l%^C167%^o%^C210%^r%^C217%^a%^C225%^l%^RESET%^ %^C243%^arrangements that decorate the hall. A massive%^RESET%^ %^C088%^s%^C124%^u%^C160%^m%^C196%^mon%^C160%^i%^C124%^n%^C088%^g%^RESET%^ %^C088%^c%^C124%^i%^C160%^r%^C196%^c%^C160%^l%^C124%^e%^RESET%^ %^C243%^of finest%^RESET%^ %^C249%^silver%^RESET%^ %^C243%^seems to be inlaid directly into the mirror-like floor in the center of the room, before the altar. Flanking it on each side are many bank-style%^RESET%^ %^C095%^t%^C131%^e%^C167%^l%^C210%^l%^C217%^e%^C225%^r%^RESET%^ %^C225%^w%^C224%^i%^C217%^n%^C210%^d%^C167%^o%^C131%^w%^C095%^s%^C243%^, staffed by lay-clergy that offer services for both the mundane coinpurse and the spiritual realm, for in this temple even those with nothing to give may offer up their soul to a conjured%^RESET%^ %^C088%^d%^C124%^e%^C160%^v%^C196%^il%^RESET%^ %^C243%^should they find the terms amenable.%^RESET%^\n%^CRST%^");
    set_smell("default","%^RESET%^%^CRST%^%^C242%^A%^RESET%^ %^C095%^r%^C131%^o%^C167%^s%^C203%^a%^C210%^c%^C203%^e%^C167%^o%^C131%^u%^C095%^s%^C242%^,%^RESET%^ %^C245%^m%^C246%^e%^C247%^t%^C248%^a%^C249%^l%^C248%^l%^C247%^i%^C246%^c%^RESET%^ %^C242%^scent permeates the air.%^RESET%^%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C242%^Somber%^RESET%^ %^C246%^s%^C247%^i%^C248%^l%^C249%^e%^C248%^n%^C247%^c%^C246%^e%^CRST%^ %^C242%^is broken only by the scratch of quills on%^RESET%^ %^C088%^c%^C124%^o%^C160%^n%^C196%^tra%^C160%^c%^C124%^t%^C088%^s%^C242%^.%^RESET%^%^CRST%^");
    set_items(([
        ({"planters", "plants"}) : "%^RESET%^%^CRST%^%^C243%^These are clearly black%^RESET%^ %^C095%^r%^C131%^o%^C167%^s%^C210%^e%^C217%^bu%^C210%^s%^C167%^h%^C131%^e%^C095%^s%^C243%^, carefully positioned so that they bathe in the %^C088%^c%^C124%^r%^C160%^i%^C196%^m%^C160%^s%^C124%^o%^C088%^n%^RESET%^ %^C243%^light cast from above, jarringly absent from any of the areas where the more%^RESET%^ %^C241%^ebon%^RESET%^ %^C243%^rays fall. Clearly, the gardeners and architects have conspired to ensure these%^RESET%^ %^C065%^p%^C107%^l%^C150%^an%^C107%^t%^C065%^s%^RESET%^ %^C243%^are capable of%^RESET%^ %^C065%^l%^C107%^i%^C150%^f%^C192%^e%^RESET%^ %^C243%^despite the hauntingly beautiful choice of skylight decor.%^RESET%^%^CRST%^",
        "altar" : "%^RESET%^%^CRST%^%^C243%^The altar to%^RESET%^ %^C088%^M%^C124%^e%^C160%^p%^C196%^h%^C160%^a%^C124%^s%^C088%^m%^RESET%^ %^C243%^is an ornate affair - fine ebony wood in a large, rectangular block.%^RESET%^ %^C065%^B%^C107%^o%^C150%^ns%^C107%^a%^C065%^i%^RESET%^ %^C243%^trees, carefully and meticulously cut into miniature shape, adorn the four corners, and the%^RESET%^ %^C124%^s%^C160%^i%^C196%^g%^C160%^i%^C124%^l%^RESET%^ %^C243%^of the fist on the%^RESET%^ %^C095%^b%^C131%^l%^C167%^a%^C210%^c%^C217%^k%^RESET%^ %^C210%^r%^C167%^o%^C131%^s%^C095%^e%^RESET%^ %^C243%^is engraved into the center of it, the%^RESET%^ %^C088%^A%^C124%^r%^C160%^c%^C196%^hfi%^C160%^e%^C124%^n%^C088%^d's%^RESET%^ %^C088%^u%^C124%^n%^C160%^h%^C196%^oly sym%^C160%^b%^C124%^o%^C088%^l%^RESET%^ %^C243%^on full display.%^RESET%^%^CRST%^",
        ]));
    set_exits(([
        "out" : "/d/magic/temples/mephasm/outside",
        ]));
    
    set_property("scry proof", SCRYWARD_LEGENDARY);
}

void reset(){
    ::reset();
    if(!present("guard")) new("/d/magic/temples/mephasm/guard")->move(this_object());
}

