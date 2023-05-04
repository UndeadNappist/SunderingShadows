// Chernobog (4/28/23)
// Temple of Cacia - Fury
// Written by Branwen

#include <std.h>

inherit ROOM;

int pottery, armor, glassware, figurines, vases, bottles; 

void create(){
    ::create();
    set_terrain(CITY);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("wrath");
    set_short("%^C160%^The Temptation of Wrath, Cacia's Temple%^CRST%^");
    set_long("%^C160%^Your senses are assaulted by the %^C058%^pungent%^C160%^ and %^C058%^overpowering aroma%^C160%^ of %^C059%^smoldering wood%^C160%^ and the %^C196%^s%^C160%^c%^C124%^o%^C088%^r%^C052%^c%^C088%^h%^C124%^i%^C160%^n%^C196%^g %^C160%^h%^C124%^e%^C088%^a%^C052%^t%^C160%^ radiating from the %^C124%^r%^C088%^o%^C052%^a%^C124%^r%^C088%^i%^C052%^n%^C124%^g %^C160%^f%^C124%^i%^C130%^r%^C124%^e %^C124%^p%^C088%^i%^C052%^t%^C160%^ positioned in the center of the chamber. The %^C088%^f%^C052%^l%^C088%^a%^C052%^m%^C088%^e%^C052%^s%^C160%^ flicker and dance, casting %^C243%^e%^C059%^r%^C243%^ra%^C059%^ti%^C243%^c%^C160%^ and %^C059%^sinister shadows%^C160%^ across the walls and ceiling, which are covered with scenes of %^C088%^battle%^C160%^ and %^C088%^destruction%^C160%^, capturing the essence of %^C089%^war%^C160%^ and %^C089%^violence%^C160%^. The perimeter of the room is crowded with %^C100%^shelves%^C160%^ and %^C100%^tables%^C160%^ heaving with a wide assortment of objects ranging from %^C059%^antique armor%^C160%^ to %^C245%^d%^C247%^e%^C245%^l%^C243%^i%^C245%^c%^C247%^a%^C245%^t%^C243%^e %^C245%^g%^C247%^l%^C243%^a%^C245%^s%^C247%^s%^C245%^w%^C243%^a%^C245%^r%^C247%^e%^C160%^. An assortment of %^C100%^h%^C101%^e%^C100%^fty w%^C101%^o%^C100%^od%^C101%^e%^C100%^n clu%^C101%^b%^C100%^s%^C160%^ and %^C102%^hammers%^C160%^ lies stacked in one corner of the room, beckoning you to unleash%^C160%^ your innermost fury%^C160%^ and %^C054%^smash%^C160%^ something.%^CRST%^\n");
    set_smell("default", "%^C243%^The air is thick with the scent of %^C247%^sweat%^C243%^, %^C088%^blood%^C243%^, and %^C059%^smoke%^C243%^.%^CRST%^");
    set_listen("default", "%^C202%^The sounds of %^C094%^c%^C130%^r%^C166%^a%^C202%^ck%^C166%^l%^C130%^i%^C094%^n%^C130%^g %^C166%^f%^C202%^la%^C166%^m%^C130%^e%^C094%^s%^C202%^ fill the air, accompanied by the occasional %^C243%^sh%^C059%^a%^C243%^tter%^C059%^in%^C243%^g%^C202%^ of objects.%^CRST%^");
    set_items(([
		({ "shelves", "tables", "armor", "antique armor", "glassware", "pottery" }) : "%^C243%^Among the items on display are %^C245%^antique suits of armor%^C243%^, %^C253%^fragile glassware%^C243%^, and %^C101%^intricately designed pottery%^C243%^. The shelves also hold several small wooden %^C139%^figurines%^C243%^ of people and animals, as well as a few %^C092%^vases%^C243%^ and %^C036%^bottles%^C243%^ that appear to be centuries old. All of these objects beg to be destroyed by the weight of a %^C250%^hammer%^C243%^ or the force of a %^C100%^club%^C243%^.%^CRST%^",
		({ "clubs", "hammers" }) : "%^C243%^The %^C100%^clubs%^C243%^ look sturdy and heavy, and the %^C250%^hammers%^C243%^ have thick, weighted heads that would easily shatter anything they %^C088%^strike%^C243%^.%^CRST%^",
		({ "fire", "firepit", "fire pit", "pit" }) : "%^C059%^The firepit is large and blazing, the %^C124%^flames%^C059%^ consuming the %^C100%^logs%^C059%^ with a %^C052%^fierce intensity%^C059%^ that fills the room with crackling and popping sounds, along with the %^C243%^smoky aroma%^C059%^ of %^C058%^burning wood%^C059%^. The heat radiates outwards, creating a %^C088%^warm%^C059%^ and %^C058%^almost suffocating%^C059%^ atmosphere that envelopes everything and everyone in the room. %^C124%^Sparks%^C059%^ shoot upwards, occasionally landing on the floor or nearby objects, threatening to ignite anything that's close enough.%^CRST%^",
        "walls" : "%^C160%^The paintings on the walls depict scenes of %^C125%^battle%^C160%^ and %^C125%^destruction%^C160%^, capturing %^C243%^warriors%^C160%^ in the midst of intense combat, their faces contorted with %^C124%^rage%^C160%^ and %^C124%^fury%^C160%^. The paintings are skillfully rendered, with %^C052%^v%^C053%^i%^C054%^b%^C055%^r%^C061%^a%^C060%^n%^C059%^t %^C058%^c%^C052%^o%^C053%^l%^C054%^o%^C055%^r%^C061%^s%^C160%^ and sharp lines, but their subject matter is %^C059%^savage%^C160%^ and %^C059%^unsettling%^C160%^. The images seem to %^C196%^pulse%^C160%^ with an %^C160%^energy%^C160%^ that is both %^C089%^thrilling%^C160%^ and %^C089%^frightening%^C160%^, drawing you into their %^C243%^violent world%^C160%^.%^CRST%^",
        ]));
    set_exits(([
        "out" : "/d/magic/temples/cacia/cacia",
        ]));
    
    pottery = random(4) + 1;
    armor = random(4) + 1;
    glassware = random(4) + 1;
    figurines = random(4) + 1;
    vases = random(4) + 1;
    bottles = random(4) + 1;
}

void init(){
    ::init();
    add_action("break_fun", "break");
    add_action("break_fun", "smash");
    add_action("burn_fun", "burn");
}

void reset(){
    ::reset();
    if(!pottery) pottery = random(4) + 1;
    if(!armor) armor = random(4) + 1;
    if(!glassware) glassware = random(4) + 1;
    if(!figurines) figurines = random(4) + 1;
    if(!vases) vases = random(4) + 1;
    if(!bottles) bottles = random(4) + 1;
    
    tell_room(this_object(), "%^C126%^Acolytes enter the room, moving about and mending various pieces on the shelves and tables.%^CRST%^");
}

int burn_fun(string str){
    object obj, player;
    
    if(!str) return notify_fail("What do you want to burn?\n");
    
    player = this_player();
    if(player->query_bound()){
        player->send_paralyzed_message("info", player);
        return 1;
    }
    if(!(obj = present(str, player))){
        tell_object(player, "%^C059%^The "+str+" must be within your inventory.%^RESET%^");
        return 1;
    }
    if(obj->query_worn()) return notify_fail("You must remove that first.\n");
    if(obj->query_wielded()) return notify_fail("You must unwield that first.\n");
    if(obj->query_property("soulbound")) return notify_fail("Cacia will not accept that offering.\n");
    if(obj->query_property("no offer")) return notify_fail("Cacia will not accept that offering.\n");
    
    tell_object(player, "%^C133%^You consign the %^C090%^"+obj->query_name()+"%^C133%^ to the %^C208%^f%^C214%^l%^C208%^a%^C202%^m%^C208%^e%^C214%^s %^C133%^in %^C213%^Cacia's name!%^CRST%^");
    tell_room(this_object(), "%^C133%^"+player->query_cap_name()+"%^C133%^ consigns the %^C090%^"+obj->query_name()+"%^C133%^ to the %^C208%^f%^C214%^l%^C208%^a%^C202%^m%^C208%^e%^C214%^s %^C133%^in %^C213%^Cacia's name!%^CRST%^", player);
    obj->remove();
    return 1;
}

int break_fun(string str){
    object player, room;
    player = this_player();
    room = this_object();
    
    if(!str){
        tell_object(player, "%^C059%^There are so many things here begging to be destroyed: %^C101%^intricate pottery%^C059%^, %^C245%^antique armor%^C059%^, %^C253%^fragile glassware%^C059%^, %^C139%^figurines%^C059%^, %^C092%^vases%^C059%^, and %^C036%^bottles%^C059%^.%^CRST%^");
        return 0;
    }
    switch(str){
        case "pottery":
        case "intricate pottery":
            if(pottery){
                switch(random(3)){
                    case 0:
                        tell_object(player, "%^C124%^You palm a piece of %^C101%^clay pottery%^C124%^, hefting it a moment before shattering it against the far wall!%^CRST%^");
                        tell_room(room, "%^C124%^"+player->query_cap_name()+"%^C124%^ palms a piece of %^C101%^clay pottery%^C124%^, hefting it a moment before shattering against the far wall!%^CRST%^", player);
                        break;
                    case 1:
                        tell_object(player, "%^C124%^Heaving a rather squat and heavy %^C101%^piece of pottery%^C124%^ over your head, you lob it in a slow arc to crash into the stone floor!%^CRST%^");
                        tell_room(room, "%^C124%^Heaving a rather squat and heavy %^C101%^piece of pottery%^C124%^ over "+player->query_possessive()+" head, "+player->query_cap_name()+"%^C124%^ lobs it in a slow arc to crash into the stone floor!%^CRST%^", player);
                        break;
                    case 2:
                        tell_object(player, "%^C124%^You line up several %^C101%^pieces of pottery%^C124%^ along the edge of a table before swatting them all in a row with the swing from a club, shattering them in a flurry of ochre fragments!%^CRST%^");
                        tell_room(room, "%^C124%^"+player->query_cap_name()+"%^C124%^ lines up several %^C101%^pieces of pottery%^C124%^ along the edge of a table before swatting them all in a row with the swing of a club, shattering them in a flurry of ochre fragments!%^CRST%^", player);
                        break;
                }
                pottery--;
            }
            else tell_object(player, "%^C059%^It appears that all of the %^C101%^"+str+" %^C059%^has been completely shattered.%^CRST%^");
            return 1;
            break;
        case "armor":
        case "antique armor":
            if(armor){
                switch(random(3)){
                    case 0:
                        tell_object(player, "%^C124%^Taking up a hammer, you bring it down on an especially %^C245%^ornate helm%^C124%^, ruining the finer details and caving it in!%^CRST%^");
                        tell_room(room, "%^C124%^Taking up a hammer, "+player->query_cap_name()+"%^C124%^ brings it down on an especially %^C245%^ornate helm%^C124%^, ruining the finer details and caving it in!%^CRST%^", player);
                        break;
                    case 1:
                        tell_object(player, "%^C124%^Clangs ring out as you hammer away at a %^C245%^breastplate%^C124%^, denting it several times before it cracks open!%^CRST%^");
                        tell_room(room, "%^C124%^Clangs ring out as "+player->query_possessive()+" head, "+player->query_cap_name()+"%^C124%^ hammers away at a %^C245%^breastplate%^C124%^, denting it several times before it cracks open!%^CRST%^", player);
                        break;
                    case 2:
                        tell_object(player, "%^C124%^Flipping a hammer to the clawed back end, you slam it into a collection of %^C245%^greaves and gauntlets%^C124%^, peppering them with gnarled holes!%^CRST%^");
                        tell_room(room, "%^C124%^Flipping a hammer to the clawed back end, "+player->query_cap_name()+"%^C124%^ slams it into a collection of %^C245%^greaves and gauntlets%^C124%^, peppering them with gnarled holes!%^CRST%^", player);
                        break;
                }
                armor--;
            }
            else tell_object(player, "%^C059%^Not a single piece of %^C245%^"+str+" %^C059%^is left undamaged, each surface defiled by dents and cracks.%^CRST%^");
            return 1;
            break;
        case "figurines":
        case "figurine":
            if(figurines){
                switch(random(3)){
                    case 0:
                        tell_object(player, "%^C124%^You admire a small %^C139%^wooden figurine of a horse %^C124%^before throwing it to the floor and stomping it to pieces!%^CRST%^");
                        tell_room(room, "%^C124%^"+player->query_cap_name()+"%^C124%^ admires a small %^C139%^wooden figurine of a horse %^C124%^before throwing it to the floor and stomping it to pieces!%^CRST%^", player);
                        break;
                    case 1:
                        tell_object(player, "%^C124%^The small %^C139%^childlike figurine %^C124%^seems to call out to you before you crush it in your hand!%^CRST%^");
                        tell_room(room, "%^C124%^"+player->query_cap_name()+"%^C124%^ stares down at a small %^C139%^childlike figurine %^C124%^before crushing it "+player->query_possessive()+" hand!%^CRST%^", player);
                        break;
                    case 2:
                        tell_object(player, "%^C124%^You set up a whole caravan of figurines on the floor: %^C139%^soldiers%^C124%^, %^C139%^wagons%^C124%^, %^C139%^horses%^C124%^... and then stomp down on them like a gigantic monster!%^CRST%^");
                        tell_room(room, "%^C124%^"+player->query_cap_name()+"%^C124%^ sets up a whole caravan of figurines on the floor: %^C139%^soldiers%^C124%^, %^C139%^wagons%^C124%^, %^C139%^horses%^C124%^... and then stomps down on them like a gigantic monster!%^CRST%^", player);
                        break;
                }
                figurines--;
            }
            else tell_object(player, "%^C059%^Every last %^C139%^figurine %^C059%^has been broken, nothing more than kindling left laying about the room.%^CRST%^");
            return 1;
            break;
        case "glassware":
        case "fragile glassware":
            if(glassware){
                switch(random(3)){
                    case 0:
                        tell_object(player, "%^C124%^Small droplets of wine flick away as you throw a delicate %^C253%^glass goblet%^C124%^, dashing it against the stone walls!%^CRST%^");
                        tell_room(room, "%^C124%^Small droplets of wine flick away as "+player->query_cap_name()+"%^C124%^ throws a delicate %^C253%^glass goblet%^C124%^, dashing it against the stone walls!%^CRST%^", player);
                        break;
                    case 1:
                        tell_object(player, "%^C124%^Grabbing a handful of %^C253%^plates%^C124%^, you spin them through the air to shatter against the far wall!%^CRST%^");
                        tell_room(room, "%^C124%^Grabbing a handful of %^C253%^plates%^C124%^, "+player->query_cap_name()+"%^C124%^ spins them through the air to shatter against the far wall!%^CRST%^", player);
                        break;
                    case 2:
                        tell_object(player, "%^C124%^Taking up a %^C253%^teacup%^C124%^, you throw it at a shelf of %^C253%^plates%^C124%^, shattering them to pieces!%^CRST%^");
                        tell_room(room, "%^C124%^Taking up a %^C253%^teacup%^C124%^, "+player->query_cap_name()+"%^C124%^ throws it at a shelf of %^C253%^plates%^C124%^, shattering them to pieces!%^CRST%^", player);
                        break;
                }
                glassware--;
            }
            else tell_object(player, "%^C059%^Nothing but the broken shards of %^C253%^"+str+" %^C059%^remain.%^CRST%^");
            return 1;
            break;
        case "vases":
        case "vase":
            if(vases){
                switch(random(3)){
                    case 0:
                        tell_object(player, "%^C124%^Placing a hand to the shelf, you bring your arm across and upend a whole %^C092%^row of vases %^C124%^to crash onto the floor!%^CRST%^");
                        tell_room(room, "%^C124%^Placing a hand to the shelf, "+player->query_cap_name()+"%^C124%^ brings "+player->query_possessive()+" arm across and upends a whole %^C092%^row of vases %^C124%^to crash onto the floor!%^CRST%^", player);
                        break;
                    case 1:
                        tell_object(player, "%^C124%^You dash a %^C092%^vase %^C124%^against the floor, water splashing amid shards of porcelain and dying flowers!%^CRST%^");
                        tell_room(room, "%^C124%^"+player->query_cap_name()+"%^C124%^ dashes a %^C092%^vase %^C124%^against the floor, water splashing amid shards of porcelain and dying flowers!%^CRST%^", player);
                        break;
                    case 2:
                        tell_object(player, "%^C124%^Taking up a hammer, you bring it down onto a %^C092%^lone vase %^C124%^with a satisfying crunch!%^CRST%^");
                        tell_room(room, "%^C124%^Taking up a hammer, "+player->query_cap_name()+"%^C124%^ brings it down onto a %^C092%^lone vase %^C124%^with a satisfying crunch!%^CRST%^", player);
                        break;
                }
                vases--;
            }
            else tell_object(player, "%^C059%^Not a single %^C092%^vase %^C059%^remains unscathed.%^CRST%^");
            return 1;
            break;
        case "bottles":
        case "bottle":
            if(bottles){
                switch(random(3)){
                    case 0:
                        tell_object(player, "%^C124%^Grabbing a club, you toss a %^C036%^bottle %^C124%^up in the air before batting it out of the air, sending shards of glass flying across the room!%^CRST%^");
                        tell_room(room, "%^C124%^Grabbing a club, "+player->query_cap_name()+"%^C124%^ tosses a %^C036%^bottle %^C124%^up in the air before batting it out of the air, sending shards of glass flying across the room!%^CRST%^", player);
                        break;
                    case 1:
                        tell_object(player, "%^C124%^Snatching a pair of hammers, you bring them down in rapid succession along a %^C036%^row of bottles%^C124%^!%^CRST%^");
                        tell_room(room, "%^C124%^Snatching a pair of hammers, "+player->query_cap_name()+"%^C124%^ brings them down in rapid succession along a %^C036%^row of bottles%^C124%^!%^CRST%^", player);
                        break;
                    case 2:
                        tell_object(player, "%^C124%^You stack a %^C036%^few bottles %^C124%^on top of each other before throwing another through the pile, smashing them all apart!%^CRST%^");
                        tell_room(room, "%^C124%^"+player->query_cap_name()+"%^C124%^ stacks a %^C036%^few bottles %^C124%^on top of each other before throwing another through the pile, smashing them all apart!%^CRST%^", player);
                        break;
                }
                bottles--;
            }
            else tell_object(player, "%^C059%^Every last %^C036%^bottle %^C059%^has been broken.%^CRST%^");
            return 1;
            break;
    }
    
    return 0;
}

// burn stuff