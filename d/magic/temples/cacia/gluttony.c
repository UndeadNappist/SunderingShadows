// Chernobog (4/24/23)
// Temple of Cacia - Gluttony
// Written by Branwen

#include <std.h>

inherit ROOM;

void create(){
    ::create();
    set_terrain(CITY);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("gluttony");
    set_short("%^C101%^The Temptation of Gluttony, Cacia's Temple%^CRST%^");
    set_long("%^C101%^As you step into the chamber, the scent of %^C095%^savory food%^C101%^ immediately envelopes you, making your mouth water and your stomach rumble with hunger. Your eyes are drawn to the center of the room, where a %^C243%^massive table%^C101%^ groans under the weight of an indulgent spread that seems to go on forever. Piles of %^C137%^r%^C143%^o%^C149%^a%^C150%^s%^C137%^t%^C143%^e%^C149%^d %^C150%^m%^C137%^e%^C143%^a%^C149%^t%^C150%^s%^C101%^, perfectly cooked %^C040%^v%^C112%^e%^C184%^g%^C214%^etab%^C184%^l%^C112%^e%^C040%^s%^C101%^, and baskets of warm, %^C102%^c%^C101%^r%^C100%^u%^C101%^s%^C102%^ty b%^C101%^r%^C100%^e%^C101%^a%^C102%^d%^C101%^ are artfully arranged between %^C182%^de%^C188%^ca%^C194%^de%^C188%^nt %^C182%^de%^C188%^ss%^C194%^er%^C188%^ts%^C101%^ that look almost too beautiful to eat. %^C253%^Cr%^C250%^yst%^C253%^al dec%^C250%^ant%^C253%^ers%^C101%^ filled with %^C125%^ri%^C124%^c%^C125%^h %^C124%^red %^C125%^w%^C124%^i%^C125%^nes%^C101%^ and %^C142%^a%^C148%^m%^C142%^ber al%^C148%^e%^C142%^s%^C101%^ sparkle enticingly, their allure enhanced by the warm, %^C227%^fl%^C228%^ic%^C192%^ke%^C191%^ri%^C227%^ng %^C192%^ca%^C191%^nd%^C227%^le%^C228%^li%^C192%^gh%^C191%^t%^C101%^ that bathes the table in a cozy glow. Ornate %^C251%^si%^C249%^l%^C247%^v%^C245%^e%^C243%^r %^C251%^c%^C249%^a%^C247%^n%^C245%^d%^C243%^ela%^C245%^b%^C247%^r%^C249%^a%^C251%^s%^C101%^, placed at intervals around the table, stand tall, their %^C160%^f%^C196%^l%^C202%^a%^C166%^m%^C160%^e%^C196%^s%^C101%^ casting %^C059%^enchanting shadows%^C101%^ that dance and sway, adding to the captivating atmosphere. As you approach the table, %^C090%^p%^C089%^l%^C088%^u%^C089%^s%^C090%^h %^C091%^c%^C090%^h%^C089%^a%^C088%^i%^C089%^r%^C090%^s%^C101%^ beckon invitingly, urging you to sit down and partake in the feast before you.%^CRST%^\n");
    set_smell("default", "%^C100%^The air is filled with the %^C136%^rich%^C100%^, %^C137%^mouth-watering%^C100%^ aromas.%^CRST%^");
    set_listen("default", "%^C139%^Soft %^C146%^conversation%^C139%^ and the clinking of %^C146%^silverware%^C139%^ enliven the room.%^CRST%^");
    set_items(([
		({ "table", "meats", "vegetables", "desserts", "bread" }) : "%^C144%^The meats are arranged in tempting piles, with succulent roasts of %^C130%^beef%^C144%^, %^C150%^pork%^C144%^, and %^C138%^lamb%^C144%^ alongside platters of juicy %^C151%^chicken%^C144%^ and %^C143%^turkey%^RESET%^%^C144%^. The %^C040%^v%^C112%^e%^C184%^g%^C214%^etab%^C184%^l%^C112%^e%^C040%^s%^C144%^ are cooked to perfection, with bright colors and crisp textures that promise a burst of flavor with each bite. The %^C130%^bread%^C144%^ is fresh and warm, with a crusty exterior and a soft, fluffy interior that begs to be slathered with %^C227%^butter%^C144%^. And then there are the %^C170%^desserts%^C144%^, a feast for the senses, each one a tantalizing masterpiece of culinary craftsmanship. Delicate filigrees of %^C250%^frosting%^C144%^ adorn cakes and pastries, while drizzles of syrup cascade over each sweet creation, glimmering in the candlelight. Towering pyramids of %^C223%^pastries%^C144%^ beckon with their flaky layers and decadent fillings, while %^C230%^creamy puddings%^C144%^ tempt with their richness and velvety texture. All of it begs you to <feast> on such bounty.%^CRST%^",
		"candelabras" : "%^C255%^Each silver candelabra is intricately crafted, with slender arms that curve and twist like vines, culminating in delicate flower-shaped holders for the candles. The candelabras are positioned strategically throughout the table, ensuring that every corner of the room is bathed in their %^C226%^w%^C220%^a%^C214%^r%^C220%^m %^C226%^l%^C220%^i%^C214%^g%^C220%^h%^C226%^t%^C255%^.%^CRST%^",
        "chairs" : "%^C091%^The extravagant chairs are upholstered in plush purple. As you take a seat, the chair seems to cradle you in a soft, %^C097%^warm embrace%^C091%^, making you feel %^C097%^safe%^C091%^ and %^C097%^secure%^C091%^.%^CRST%^",
		({ "decanters", "wines", "ales" }) : "%^C153%^The decanters are filled with rich, %^C126%^full-bodied wines%^C153%^ and %^C143%^ales%^C153%^ that have been carefully selected to complement the decadent feast on the table. The %^C124%^red wines%^C153%^ are a deep, velvety crimson, while the %^C143%^ales%^C153%^ are a warm amber hue that glows invitingly in the flickering candlelight. Each one is hand-crafted and exquisitely detailed, with intricate patterns etched into the crystal that catch the light and refract it in a %^C033%^m%^C105%^y%^C177%^ri%^C105%^a%^C033%^d%^C153%^ of dazzling colors.%^CRST%^",
        ]));
    set_exits(([
        "out" : "/d/magic/temples/cacia/cacia",
        ]));
}

void init(){
    ::init();
    add_action("feast_fun", "feast");
}

int feast_fun(string str){
    object player;
    int penalty;
    
    if(str) return 0;
    
    player = this_player();
    if(sizeof(player->query_attackers())){
        tell_object(player, "%^C196%^You can't do that while under attack!%^CRST%^");
        return 1;
    }
    penalty = player->query_stuffed();
    player->set_stuffed(penalty - 1000);
    penalty = player->query_quenched();
    player->set_quenched(penalty - 1000);
    tell_object(player, "%^CRST%^%^C097%^As you take a bite of the %^C096%^sumptuous food%^C097%^ before you, you hear a %^C248%^soft whisper%^C097%^ in your ear, enticing you to %^C089%^savor%^C097%^ every flavor and %^C089%^delight%^C097%^ in every sensation. The whisper grows louder and more insistent with each passing moment, until it seems to fill your entire being with an overwhelming desire to %^C125%^eat%^C097%^, %^C126%^drink%^C097%^, and %^C127%^be merry%^C097%^.%^CRST%^");
    return 1;
}
 