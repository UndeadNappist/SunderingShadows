// Chernobog (4/24/23)
// Temple of Cacia
// Written by Branwen

#include <std.h>

inherit "/std/temple";

#define ROOMS "/d/magic/temples/cacia/"

int clutter;

void create(){
    ::create();
    set_terrain(CITY);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_temple("cacia");
    set_name("cacia's temple");
    set_short("%^C133%^Cacia's Temple%^CRST%^");
    set_long("%^C133%^As you enter the room, a wave of %^C090%^decadence%^C133%^ and %^C090%^sensuality%^C133%^ washes over you. The space is bathed in a %^C214%^w%^C220%^a%^C214%^rm%^C133%^, %^C220%^g%^C214%^o%^C220%^ld%^C214%^e%^C220%^n gl%^C214%^o%^C220%^w%^RESET%^%^C133%^ from the %^C220%^f%^C221%^l%^C227%^i%^C228%^c%^C229%^ke%^C228%^r%^C227%^i%^C221%^n%^C220%^g %^C220%^c%^C221%^h%^C227%^a%^C228%^n%^C229%^del%^C228%^i%^C227%^e%^C221%^r%^C220%^s%^C133%^, casting %^C243%^shadows%^C133%^ across the plush furnishings. At the heart of the chamber stands an exquisite statue of %^C213%^Cacia%^C133%^, crafted from %^C188%^d%^C145%^a%^C219%^r%^C213%^k%^C207%^s%^C201%^t%^C164%^e%^C127%^e%^C090%^l%^C133%^ and adorned with intricate %^C127%^violet detailing %^C133%^that shimmers seductively in the %^C220%^c%^C221%^a%^C227%^n%^C228%^d%^C229%^lel%^C228%^i%^C227%^g%^C221%^h%^C220%^t%^C133%^. Her curves are accentuated by the sensual play of %^C250%^light%^C133%^ and %^C243%^shadow%^C133%^ that dance tantalizingly across her surface. Reverent %^C090%^offerings%^C133%^ are laid out at her feet, and cradled in her upturned palms, a testament to the worship and indulgence that takes place within these walls. The %^C059%^bla%^C243%^c%^C059%^k m%^C243%^a%^C059%^rble flo%^C243%^o%^C059%^r%^C133%^ is polished to a mirror-like finish, reflecting the glow of the chandeliers and adding to the room's sense of %^C090%^grandeur%^C133%^. Soft, %^C089%^pl%^C091%^u%^C090%^s%^C089%^h carp%^C091%^e%^C090%^t%^C089%^s%^C133%^ and %^C089%^l%^C090%^a%^C091%^v%^C089%^ish d%^C090%^i%^C091%^v%^C089%^ans%^C133%^ invite guests to sink into their luxurious embrace and give in to their deepest desires. Along the perimeter of the room, %^C243%^t%^C059%^o%^C243%^wer%^C059%^in%^C243%^g p%^C059%^i%^C243%^ll%^C059%^ar%^C243%^s%^C133%^ frame sheer, %^C140%^g%^C141%^o%^C105%^s%^C104%^s%^C140%^a%^C141%^m%^C105%^e%^C104%^r %^C140%^c%^C141%^u%^C105%^r%^C104%^t%^C140%^a%^C141%^i%^C105%^n%^C104%^s%^C133%^, offering teasing glimpses of the %^C090%^private chambers%^C133%^ beyond.%^CRST%^\n");
    set_smell("default", "%^C219%^The air is thick with the scent of %^C182%^exotic incense%^C219%^ and %^C182%^spices%^C219%^, which drift through the room and fill your senses.%^CRST%^");
    set_listen("default", "%^C147%^Soft, %^C146%^seductive music%^C147%^ rises and falls like the ebb and flow of the tides.%^CRST%^");
    set_items(([
	    "chamber 1" : "%^C110%^Above the arched western doorway to this alcove, the elegant cursive letters spell out the name of the room - %^C255%^The Temptation of Euphoria%^C110%^. As you move closer to the curtains, the %^C122%^hypnotic beat%^C110%^ of the music and the %^C104%^potent aroma%^C110%^ of %^C076%^herbs%^C110%^ and %^C127%^wine%^C110%^ intoxicate your senses. Peering through the veil, you catch glimpses of %^C153%^ethereal figures%^C110%^ swaying in a dreamlike state, completely immersed in the moment.%^CRST%^",
		"chamber 2" : "%^C110%^Above the arched southwestern doorway to this alcove, the flowing cursive letters spell out the name of the room - %^C255%^The Temptation of Gluttony%^C110%^. As you approach the curtains, the mouthwatering aroma of %^C115%^rich%^C110%^ and %^C115%^savory cuisine%^C110%^ envelops you, igniting a %^C243%^hunger%^C110%^ deep within. The silhouettes of indulgent figures around a table become more distinct, savoring every bite and sip.%^CRST%^",
		"chamber 3" : "%^C110%^Above the arched southern doorway to this alcove, the elegant cursive letters spell out the name of the room - %^C255%^The Temptation of Flesh%^C110%^. As you move closer to the curtains, the air becomes saturated with a heady blend of %^C098%^perfumes%^C110%^ and %^C098%^incense%^C110%^, accompanied by a %^C117%^soft symphony%^C110%^ of whispers and sighs. Beyond the veil, you can discern the graceful shapes of bodies intertwined in %^C089%^pleasure%^C110%^, tempting you to join in this captivating dalliance.%^CRST%^",
		"chamber 4" : "%^C110%^Above the arched southeastern doorway to this alcove, the elegant cursive letters spell out the name of the room - %^C255%^The Temptation of Avarice%^C110%^. As you move closer to the curtains, the captivating scent of %^C146%^exotic perfumes%^C110%^ and %^C128%^luxurious wines%^C110%^ fills your senses, enchanting you. You begin to see the outlines of elegant figures gracefully gliding about, their footsteps accompanied by the gentle chime of %^C220%^golden coins%^C110%^.%^CRST%^",
		"chamber 5" : "%^C110%^Above the arched eastern doorway to this alcove, the flowing cursive letters spell out the name of the room - %^C255%^The Temptation of Fury%^C110%^. As you draw nearer to the curtains, a mesmerizing play of light and shadow from the %^C124%^flames%^C110%^ dancing beyond captures your attention. The acrid scent of %^C243%^smoke%^C110%^ invades your senses, while a sudden scream of %^C059%^rage%^C110%^ pierces the air, followed by the sound of shattering glass.%^CRST%^",
		"floor" : "%^C059%^The floor is made of black marble and is polished to a mirror-like finish, reflecting the warm glow of the %^C192%^chandeliers%^C059%^ and adding to the room's sense of grandeur.%^CRST%^",
        "offerings" : "%^C109%^Placed with intention are traces of %^C245%^worldly vices%^C109%^: Bottles of spirits, cigarettes, pouches of pungent herbs. Splashes of blood, wine, and other curious substances are all %^C114%^reverently%^C109%^ left here by those seeking her favor.%^CRST%^",
        ({ "chandelier", "chandeliers" }) : "%^C192%^These grandiose light fixtures, suspended from the ceiling, are adorned with intricate designs and %^C194%^sparkling crystals%^C192%^ that glimmer in the soft glow of their %^C191%^candles%^C192%^. The gentle flicker of the candlelight creates a serene and inviting ambiance, casting a warm light that envelops the entire room.%^CRST%^",
		({ "statue", "platform" }) : "%^C060%^A sinuous statue looms before you, its %^C054%^alluring%^C060%^ feminine form encapsulated in solid %^C061%^darksteel%^RESET%^%^C060%^, the edge of each detail picked out in a sinister %^C053%^viol%^C052%^e%^C053%^t tarni%^C052%^s%^C053%^h%^RESET%^%^C060%^. A smile tugs at the corner of her %^C059%^swollen lips%^RESET%^%^C060%^, her comely gaze cast downward to take in your measure. Six supple arms grace her slender body, the two at her shoulders reaching high and low along her curves to seek out the %^C059%^tantalizing%^C060%^ swell of a breast and the %^C059%^shaded secrets%^C060%^ between clenched thighs. The other four slink outwards from the serpentine curve of her back, her delicate hands palm upwards, awaiting the %^C066%^offerings%^C060%^ of her supplicants. An inscription wraps around the periphery of the platform, her charge to the faithful.%^CRST%^",
        "inscription" : ({"%^C102%^Words have been carved into the curve of the stone base.%^CRST%^", "%^C059%^\"She Who Drinks of the World.\"%^CRST%^", "common"}),
		({ "carpets", "divans" }) : "%^C089%^The plush, %^C090%^dark carpets%^C089%^ in the room have a dense, velvety texture that invites you to sink your toes into their softness. The %^C090%^lavish divans%^C089%^ are low to the ground and covered in %^C125%^delectable silk%^C089%^. They are arranged in intimate seating areas, creating a comfortable space for guests to lounge and indulge in the luxurious surroundings.%^CRST%^",
		({ "private chambers", "chambers", "alcoves", "curtains", "pillars" }) : "%^C255%^The %^C243%^towering pillars%^C255%^ are impressive feats of craftsmanship. The smooth surface of each one is polished to a high shine, reflecting the warm glow of the chandeliers above. The arched entrances that lead deeper into private chambers are draped in %^C089%^d%^C090%^a%^C089%^rk mau%^C090%^v%^C089%^e c%^C090%^u%^C089%^rtai%^C090%^n%^C089%^s%^C255%^, their %^C250%^sheerness%^C255%^ allowing a glimpse of the mysteries beyond. As you approach each alcove, you can feel the weight of temptation bearing down upon you. The curtains create a sense of mystery and anticipation, drawing you in and encouraging you to indulge in your desires.%^CRST%^",
        ]));
    set_exits(([
        "out" : ROOMS"courtyard",
        "west" : ROOMS"euphoria",
        "southwest" : ROOMS"gluttony",
        "south" : ROOMS"flesh",
        "southeast" : ROOMS"avarice",
        "east" : ROOMS"fury",
        ]));
        
    clutter = random(7) + 3;
    place_long();
    place_offerings();
}

void init(){
    ::init();
    add_action("read_charge", "read");
}

int read_charge(string str){
    object player;
    
    if(!str) return 0;
    if(str != "charge" && str != "inscription") return 0;
    
    player = this_player();
    tell_object(player, "%^C025%^The void will consume all in the end, thus the wise know to take all they want while they can. Indulge in the experiences of the world, challenge the taboo, and disregard the morals of civil society for they are only intended to oppress and suppress. Entice others to satiate their own vices often, laying the world open to Cacia.%^RESET%^%^CRST%^");
    if(!player->query_invis() || !player->query_hidden()) tell_room(environment(player), "%^CRST%^"+player->query_cap_name()+"%^CRST%^ looks over the charge.%^CRST%^", player);
   return 1;
}

void place_long(){
    string long_desc;
    
    long_desc = "%^C133%^As you enter the room, a wave of %^C090%^decadence%^C133%^ and %^C090%^sensuality%^C133%^ washes over you. The space is bathed in a %^C214%^w%^C220%^a%^C214%^rm%^C133%^, %^C220%^g%^C214%^o%^C220%^ld%^C214%^e%^C220%^n gl%^C214%^o%^C220%^w%^RESET%^%^C133%^ from the %^C220%^f%^C221%^l%^C227%^i%^C228%^c%^C229%^ke%^C228%^r%^C227%^i%^C221%^n%^C220%^g %^C220%^c%^C221%^h%^C227%^a%^C228%^n%^C229%^del%^C228%^i%^C227%^e%^C221%^r%^C220%^s%^C133%^, casting %^C243%^shadows%^C133%^ across the plush furnishings. At the heart of the chamber stands an exquisite statue of %^C213%^Cacia%^C133%^, crafted from %^C188%^d%^C145%^a%^C219%^r%^C213%^k%^C207%^s%^C201%^t%^C164%^e%^C127%^e%^C090%^l%^C133%^ and adorned with intricate %^C127%^violet detailing %^C133%^that shimmers seductively in the %^C220%^c%^C221%^a%^C227%^n%^C228%^d%^C229%^lel%^C228%^i%^C227%^g%^C221%^h%^C220%^t%^C133%^. Her curves are accentuated by the sensual play of %^C250%^light%^C133%^ and %^C243%^shadow%^C133%^ that dance tantalizingly across her surface.";
    switch(clutter){
        case 3..4:
            long_desc += " A %^C213%^few%^C133%^";
            break;
        case 5..7:
            long_desc += " A %^C213%^gathering %^C133%^of";
            break;
        case 8..10:
            long_desc += " A %^C213%^multitude %^C133%^of";
            break;
    }
    long_desc += " reverent %^C090%^offerings%^C133%^ are laid out at her feet, and cradled in her upturned palms, a testament to the worship and indulgence that takes place within these walls. The %^C059%^bla%^C243%^c%^C059%^k m%^C243%^a%^C059%^rble flo%^C243%^o%^C059%^r%^C133%^ is polished to a mirror-like finish, reflecting the glow of the chandeliers and adding to the room's sense of %^C090%^grandeur%^C133%^. Soft, %^C089%^pl%^C091%^u%^C090%^s%^C089%^h carp%^C091%^e%^C090%^t%^C089%^s%^C133%^ and %^C089%^l%^C090%^a%^C091%^v%^C089%^ish d%^C090%^i%^C091%^v%^C089%^ans%^C133%^ invite guests to sink into their luxurious embrace and give in to their deepest desires. Along the perimeter of the room, %^C243%^t%^C059%^o%^C243%^wer%^C059%^in%^C243%^g p%^C059%^i%^C243%^ll%^C059%^ar%^C243%^s%^C133%^ frame sheer, %^C140%^g%^C141%^o%^C105%^s%^C104%^s%^C140%^a%^C141%^m%^C105%^e%^C104%^r %^C140%^c%^C141%^u%^C105%^r%^C104%^t%^C140%^a%^C141%^i%^C105%^n%^C104%^s%^C133%^, offering teasing glimpses of the %^C090%^private chambers%^C133%^ beyond.%^CRST%^\n";
    set_long(long_desc);
    return;
}

void place_offerings(){
    string offerings_desc, *offerings;
    int i, selection;
    
    offerings = ({ "%^C245%^a s%^C248%^m%^C245%^all fla%^C248%^s%^C245%^k%^CRST%^", "%^C059%^sil%^C243%^k%^C059%^y un%^C243%^de%^C059%^rgarm%^C243%^en%^C059%^ts%^CRST%^", "%^C058%^a half-smoked %^C130%^c%^C136%^i%^C130%^g%^C136%^a%^C130%^r%^CRST%^", "%^C250%^a %^C243%^s%^C245%^i%^C250%^lv%^C245%^e%^C243%^r %^C250%^ci%^C101%^g%^C250%^ar%^C245%^e%^C250%^tte ca%^C245%^s%^C250%^e%^CRST%^", "%^C248%^an unopened %^C101%^bottle%^C248%^ of %^C255%^v%^C250%^o%^C255%^dka%^CRST%^", "%^C109%^a ri%^C103%^bb%^C109%^ed gla%^C103%^s%^C109%^s dil%^C103%^d%^C109%^o%^CRST%^", "%^C021%^a de%^C026%^e%^C021%^p bl%^C026%^u%^C021%^e m%^C026%^u%^C021%^shro%^C026%^o%^C021%^m%^CRST%^", "%^C088%^a r%^C089%^e%^C088%^d-cap%^C089%^p%^C088%^ed m%^C089%^u%^C088%^shro%^C089%^o%^C088%^m%^CRST%^", "%^C101%^an empty %^C100%^whiskey %^C101%^bottle%^CRST%^", "%^C090%^a plate of p%^C096%^a%^C089%^s%^C090%^tr%^C096%^ie%^C090%^s%^CRST%^", "%^C104%^a b%^C122%^o%^C104%^wl of gr%^C122%^a%^C104%^pes%^CRST%^", "%^C243%^a set of shackles%^CRST%^", "%^C052%^a le%^C053%^a%^C052%^ther whip%^CRST%^", "%^C059%^an obsidian ring%^CRST%^", "%^C184%^a go%^C190%^ld%^C184%^en ri%^C190%^n%^C184%^g%^CRST%^", "%^C255%^a d%^C159%^i%^C250%^a%^C255%^mo%^C159%^n%^C255%^d ri%^C159%^n%^C255%^g%^CRST%^", "%^C136%^a p%^C142%^i%^C148%^l%^C226%^e o%^C190%^f c%^C226%^o%^C148%^i%^C142%^n%^C136%^s%^CRST%^", "%^C161%^c%^C160%^o%^C088%^l%^C089%^o%^C090%^r%^C091%^f%^C092%^u%^C093%^l %^C021%^g%^C020%^e%^C025%^m %^C030%^s%^C035%^h%^C040%^a%^C047%^r%^C084%^d%^C085%^s%^CRST%^" });
    offerings += ({ "%^C188%^a small pouch of %^C195%^white powder%^CRST%^", "%^C124%^a sprinkling of %^C196%^r%^C124%^e%^C196%^d du%^C124%^s%^C196%^t%^CRST%^", "%^C101%^a %^C102%^pipe%^C101%^ packed full of %^C082%^h%^C076%^e%^C082%^rbs%^CRST%^", "%^C094%^c%^C095%^ho%^C094%^col%^C095%^at%^C094%^e %^C124%^st%^C088%^r%^C125%^a%^C124%^wberr%^C125%^i%^C088%^e%^C124%^s%^CRST%^", "%^C243%^a sp%^C060%^ik%^C243%^ed c%^C060%^o%^C243%^ll%^C060%^a%^C243%^r%^CRST%^", "%^C189%^a half-empty %^C183%^wine%^C189%^ glass%^CRST%^", "%^C101%^half of a %^C102%^bottle%^C101%^ of %^C100%^rum%^CRST%^", "%^C150%^a gl%^C144%^a%^C150%^ss e%^C144%^y%^C150%^e%^CRST%^", "%^C100%^a w%^C101%^o%^C100%^rn w%^C101%^o%^C100%^od%^C101%^e%^C100%^n dil%^C101%^d%^C100%^o%^CRST%^", "%^C243%^a ball gag%^CRST%^", "%^C159%^a p%^C158%^a%^C157%^i%^C156%^r %^C157%^o%^C158%^f %^C157%^d%^C158%^i%^C159%^r%^C158%^t%^C157%^y %^C156%^p%^C157%^a%^C158%^n%^C159%^t%^C158%^i%^C157%^e%^C156%^s%^CRST%^", "%^C143%^a small dish of %^C136%^h%^C142%^o%^C136%^ney%^CRST%^", "%^C102%^an empty %^C101%^beer stein%^CRST%^", "%^C191%^a sheaf of %^C184%^wheat%^CRST%^", "%^C083%^a bouquet of %^C127%^w%^C126%^i%^C125%^l%^C124%^d %^C196%^f%^C197%^l%^C198%^o%^C199%^w%^C200%^e%^C201%^r%^C207%^s%^CRST%^", "%^C255%^milky drippings%^CRST%^", "%^C053%^a %^C052%^scourge%^C053%^ whip%^CRST%^", "%^C250%^a %^C253%^shiny %^C243%^d%^C245%^a%^C247%^gg%^C245%^e%^C243%^r%^CRST%^", "%^C243%^a razor-edged poker%^CRST%^", "%^C231%^a jug of %^C195%^m%^C231%^o%^C195%^onshi%^C231%^n%^C195%^e%^CRST%^", "%^C059%^a t%^C058%^u%^C059%^ft of d%^C058%^a%^C059%^rk f%^C058%^u%^C059%^r%^CRST%^", "%^C176%^f%^C177%^u%^C176%^zzy h%^C177%^a%^C176%^n%^C177%^dc%^C176%^uf%^C177%^f%^C176%^s%^CRST%^", "%^C089%^a %^C124%^blo%^C088%^o%^C124%^dy%^C089%^ finger%^CRST%^", "%^C245%^a %^C243%^charred%^C245%^ portrait%^CRST%^", "%^C189%^a %^C195%^crusty drawing%^C189%^ of a %^C183%^woman%^CRST%^", "%^C101%^an old l%^C100%^u%^C101%^te%^CRST%^", "%^C124%^a single %^C088%^red%^C124%^ rose%^CRST%^", "%^C255%^a jar of milk%^CRST%^", "%^C040%^a %^C035%^l%^C030%^o%^C025%^n%^C020%^g %^C021%^p%^C026%^e%^C031%^a%^C036%^c%^C041%^o%^C046%^c%^C082%^k %^C047%^f%^C042%^e%^C037%^a%^C032%^t%^C027%^h%^C033%^e%^C038%^r%^CRST%^", "%^C076%^a small bag of %^C082%^c%^C083%^r%^C084%^y%^C085%^s%^C086%^t%^C158%^a%^C157%^l%^C156%^l%^C157%^i%^C158%^z%^C086%^e%^C085%^d %^C084%^h%^C083%^e%^C082%^r%^C083%^b%^C084%^s%^CRST%^", "%^C250%^a s%^C245%^c%^C101%^a%^C250%^tter%^C245%^i%^C101%^n%^C250%^g of %^C255%^ci%^C250%^ga%^C245%^r%^C101%^e%^C250%^tt%^C255%^es%^CRST%^", "%^C070%^a cup of %^C065%^green tea%^CRST%^", "%^C101%^a %^C243%^wafting %^C101%^stick of %^C103%^incense%^CRST%^", "%^C125%^a sensual %^C124%^r%^C088%^e%^C124%^d c%^C088%^a%^C124%^ndle%^CRST%^" });
    offerings_desc = "%^C109%^Placed with intention are traces of %^C245%^worldly vices%^C109%^: Bottles of spirits, cigarettes, pouches of pungent herbs. Splashes of blood, wine, and other curious substances are all %^C114%^reverently%^C109%^ left here by those seeking her favor. At a glance, you can see: %^CRST%^";
    for(i = 0; i < clutter; i++){
        selection = random(sizeof(offerings));
        if((i + 1) == clutter) offerings_desc += "and "+offerings[selection]+".%^CRST%^";
        else offerings_desc += offerings[selection]+", ";
        
        offerings -= ({ offerings[selection] });
        continue;
    }
    remove_item("offerings");
    add_item("offerings", offerings_desc);
    return;
}

