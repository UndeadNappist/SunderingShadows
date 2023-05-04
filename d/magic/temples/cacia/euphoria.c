// Chernobog (4/24/23)
// Temple of Cacia - Euphoria
// Written by Branwen

#include <std.h>

inherit ROOM;

void create(){
    ::create();
    set_terrain(CITY);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("euphoria");
    set_short("%^C133%^The Temptation of Euphoria, Cacia's Temple%^CRST%^");
    set_long("%^C133%^The air in this narrow chamber is thick with the %^C097%^heavy haze%^C133%^ of %^C244%^opium%^C133%^ and the heady scent of %^C034%^e%^C035%^n%^C042%^t%^C041%^i%^C040%^c%^C046%^i%^C047%^n%^C048%^g %^C047%^h%^C046%^e%^C040%^r%^C041%^b%^C040%^s%^C133%^. %^C184%^Fl%^C190%^ic%^C226%^ke%^C220%^ri%^C226%^ng %^C190%^c%^C226%^a%^C220%^n%^C226%^d%^C220%^l%^C226%^e%^C190%^s%^C133%^ provide the sole source of light, casting %^C244%^reflections%^C133%^ off the %^C203%^c%^C215%^o%^C230%^l%^C157%^o%^C121%^r%^C116%^f%^C117%^u%^C111%^l %^C110%^t%^C176%^a%^C183%^p%^C218%^e%^C224%^s%^C209%^t%^C222%^r%^C157%^i%^C121%^e%^C116%^s%^C133%^ that adorn the walls. %^C128%^P%^C134%^l%^C140%^u%^C134%^s%^C128%^h c%^C134%^u%^C140%^s%^C134%^h%^C128%^i%^C134%^o%^C140%^n%^C134%^s%^C133%^ and %^C247%^low tables%^C133%^ are scattered throughout the room, inviting guests to %^C134%^lounge%^C133%^ and %^C134%^relax%^C133%^. A %^C245%^stone table%^C133%^ covered in %^C125%^silk%^C133%^ dominates the center of the space, covered with bottles of %^C127%^wi%^C126%^n%^C127%^e%^C133%^ and %^C094%^l%^C130%^i%^C166%^q%^C178%^u%^C180%^o%^C214%^r%^C133%^, and bowls overflowing with %^C076%^f%^C048%^r%^C047%^a%^C040%^g%^C046%^r%^C047%^a%^C048%^n%^C076%^t h%^C048%^e%^C047%^r%^C040%^b%^C046%^s%^C133%^ and %^C015%^p%^C231%^o%^C255%^w%^C253%^d%^C255%^e%^C231%^r%^C015%^s%^C133%^. In one corner, a %^C128%^l%^C134%^a%^C140%^r%^C134%^g%^C128%^e %^C128%^h%^C134%^o%^C140%^o%^C134%^k%^C128%^a%^C092%^h%^C133%^ tempts devotees to indulge in %^C134%^hedonistic pleasures%^C133%^ of the body and mind, leaving them %^C134%^glassy-eyed%^C133%^ and lost in %^C218%^eu%^C219%^ph%^C224%^or%^C225%^ia%^C133%^.%^CRST%^\n");
    set_smell("default", "%^C128%^The room is infused with a %^C134%^p%^C140%^u%^C134%^nge%^C140%^n%^C134%^t%^C128%^, %^C134%^s%^C140%^wee%^C134%^t s%^C140%^mel%^C134%^l%^C128%^ that immediately %^C153%^i%^C147%^n%^C141%^t%^C147%^o%^C153%^x%^C159%^i%^C123%^c%^C159%^a%^C147%^t%^C141%^e%^C147%^s%^C128%^ your senses.%^CRST%^");
    set_listen("default", "%^C147%^The %^C105%^h%^C111%^y%^C117%^p%^C123%^n%^C159%^ot%^C123%^i%^C117%^c %^C111%^m%^C105%^u%^C111%^s%^C117%^i%^C123%^c%^C147%^ creates a %^C159%^me%^C195%^sm%^C231%^eri%^C194%^zi%^C159%^ng e%^C194%^f%^C231%^fe%^C195%^c%^C159%^t%^C147%^, immersing you completely in the moment.%^CRST%^");
    set_items(([
		"tapestries" : "%^C198%^C%^C199%^o%^C200%^l%^C201%^o%^C204%^r%^C203%^f%^C202%^u%^C208%^l%^C214%^ %^C220%^t%^C226%^a%^C227%^p%^C226%^e%^C220%^s%^C214%^t%^C208%^r%^C202%^i%^C203%^e%^C204%^s%^C033%^ adorn the walls of the room, their %^C081%^vibrant hues%^C033%^ and %^C081%^intricate designs%^C033%^ depicting scenes of %^C214%^revelry%^C033%^, %^C176%^intoxication%^C033%^, and %^C147%^hedonism%^C033%^. Figures dance and cavort on their surfaces, their bodies intertwined in a %^C128%^f%^C127%^r%^C126%^e%^C091%^n%^C090%^z%^C128%^y%^C033%^ of %^C090%^pleasure%^C033%^ and %^C090%^ecstasy%^C033%^. %^C038%^Goblets%^C033%^ and %^C038%^bowls%^C033%^ overflowing with %^C126%^wine%^C033%^ and %^C046%^exotic herbs%^C033%^ are depicted, tempting guests to partake in the intoxicating pleasures they offer. The tapestries are a %^C128%^celebration%^C033%^ of the senses, evoking a world of indulgence and excess that is at once alluring and decadent.%^CRST%^",
		"candles" : "%^C246%^The %^C255%^candles%^C246%^ in the room %^C193%^fl%^C194%^ic%^C230%^ke%^C229%^r s%^C228%^of%^C192%^tl%^C193%^y%^C246%^, casting a %^C184%^warm%^C246%^ and %^C184%^inviting glow%^C246%^ over everything they touch. They are tall and slender, fashioned from the finest quality wax and adorned with delicate designs and patterns that catch the eye and add a touch of %^C153%^elegance%^C246%^ to the room.%^CRST%^",
        "hookah" : "%^C110%^Towering in the corner of the room, the %^C099%^hookah%^C110%^ looms large and impressive. Its long, %^C092%^elegant stem%^C110%^ rises up from a wide, ornately decorated base, culminating in a %^C111%^sh%^C117%^im%^C111%^me%^C105%^ri%^C111%^ng%^C110%^, %^C111%^intricately crafted bowl%^C110%^. The base itself is adorned with %^C099%^detailed designs%^C110%^ and %^C099%^patterns%^C110%^, painstakingly etched by a skilled artisan. The long hose that extends from the bowl is wrapped in %^C091%^p%^C092%^l%^C093%^u%^C099%^s%^C098%^h %^C098%^v%^C097%^e%^C091%^l%^C092%^v%^C093%^e%^C099%^t%^C110%^, inviting guests to <start smoking> to indulge in the pleasures of the hookah.%^CRST%^",
        ({ "table", "stone table", "bottles", "bowls", "wine", "liquor", "herbs", "powders" }) : "%^C243%^The black stone table at the center of the room dominates the space, its smooth surface covered in a %^C124%^d%^C125%^e%^C126%^e%^C127%^p %^C091%^m%^C089%^a%^C088%^u%^C124%^v%^C125%^e %^C126%^s%^C127%^i%^C091%^l%^C090%^k %^C089%^c%^C088%^l%^C124%^o%^C125%^t%^C126%^h%^C243%^ that shimmers in the %^C178%^f%^C184%^l%^C190%^i%^C226%^c%^C227%^k%^C191%^e%^C185%^r%^C186%^i%^C192%^n%^C228%^g %^C227%^c%^C191%^a%^C185%^n%^C184%^d%^C190%^l%^C191%^e%^C185%^l%^C186%^i%^C192%^g%^C193%^h%^C192%^t%^C243%^. Rows of %^C125%^wine bottles%^C243%^ and %^C142%^liquor decanters%^C243%^ line its edges. Bowls overflowing with %^C083%^fragrant herbs%^C243%^ and %^C250%^alluring powders%^C243%^ rest alongside the bottles, their scents mingling with the heady aroma of %^C059%^opium%^C243%^.%^CRST%^",
		({ "tables", "low tables", "cushions" }) : "%^C101%^The tables are simple and elegant, fashioned from %^C102%^dark wood%^C101%^ and adorned with intricate carvings that catch the eye. The %^C069%^cushions%^C101%^ are soft and inviting, piled high with layers of %^C021%^s%^C027%^u%^C033%^m%^C039%^p%^C045%^t%^C051%^u%^C087%^o%^C081%^u%^C075%^s %^C069%^f%^C063%^a%^C057%^b%^C056%^r%^C062%^i%^C068%^c%^C074%^s%^C101%^ that offer a comfortable place to lounge and unwind. %^C127%^V%^C128%^i%^C129%^b%^C057%^r%^C056%^a%^C063%^n%^C141%^t %^C075%^c%^C080%^o%^C085%^l%^C048%^o%^C043%^r%^C038%^s%^C101%^ and %^C127%^i%^C132%^n%^C137%^t%^C142%^r%^C220%^i%^C227%^c%^C192%^a%^C185%^t%^C178%^e %^C100%^p%^C095%^a%^C090%^t%^C097%^t%^C104%^e%^C111%^r%^C116%^n%^C121%^s%^C101%^ adorn each cushion, adding to the %^C128%^exotic feel%^C101%^ of the space.%^CRST%^",
        ]));
    set_exits(([
        "out" : "/d/magic/temples/cacia/cacia",
        ]));
    set_pre_exit_functions(({ "out" }), ({ "leave_fun" }));
}

void init(){
    ::init();
    add_action("start_fun", "start");
    add_action("smoke_fun", "smoke");
    add_action("stop_fun", "stop");
}

int leave_fun(string str){
    object player = this_player();
    if(player->query_property("smoking hookah") == 1) {
        tell_object(player, "%^C059%^You can't bring the hookah with you, you'll need to stop smoking first.%^CRST%^");
        return 0;
    }
    return 1;
}

int start_fun(string str){
    object player = this_player();
    
    if(!str || str != "smoking") {
        tell_object(player, "%^C059%^Try 'start smoking'.%^CRST%^");
        return 0;
    }
    if(player->query_property("smoking hookah")){
        tell_object(player, "%^C059%^Perhaps you've had enough! You're already smoking the hookah.%^CRST%^");
        return 1;
    }
    tell_object(player, "%^C245%^You sink into one of the %^C103%^soft cushions%^C245%^ and take up one of the hoses. You %^C249%^inhale%^C245%^, and as the %^C059%^opium%^C245%^ fills your lungs, %^C132%^warmth%^C245%^ begins to spread throughout your body. You may <smoke> whenever you like or <stop smoking> when you are finished.%^CRST%^");
    tell_room(environment(player), "%^C245%^"+player->query_cap_name()+" settles on one of the cushions and begins smoking the hookah.%^CRST%^", player);
    player->set_property("smoking hookah", 1);
    return 1;
}

int smoke_fun(string str){
    object player = this_player();
    
    if(!str || str == "hookah"){
        if(!player->query_property("smoking hookah")){
            tell_object(player, "%^C059%^You have not started smoking the hookah!%^CRST%^");
            return 0;
        }
        tell_object(player, "%^C248%^You take a long drag off the hookah and feel your body relax.%^CRST%^");
        tell_room(environment(player), "%^C248%^"+player->query_cap_name()+"%^C248%^ takes a drag off the hookah, sending a small puff of smoke into the air.%^CRST%^", player);
        switch(random(6)){
            case 0:
                tell_object(player, "%^C181%^Your eyelids grow %^C180%^heavier%^C181%^ as the tenseness in your muscles begins to %^C180%^u%^C181%^n%^C182%^rav%^C181%^el%^C181%^.%^CRST%^");
                break;
            case 1:
                tell_object(player, "%^C243%^Yo%^C245%^u wa%^C246%^t%^C243%^ch t%^C247%^h%^C246%^e s%^C244%^mo%^C243%^ke %^C244%^sw%^C246%^ir%^C245%^l o%^C243%^ver%^C246%^he%^C244%^ad%^C243%^, ad%^C245%^ri%^C244%^ft %^C243%^in t%^C245%^h%^C246%^e di%^C244%^m li%^C246%^gh%^C243%^ti%^C244%^n%^C243%^g.%^CRST%^");
                break;
            case 2:
                tell_object(player, "%^C219%^A pleasant %^C170%^w%^C169%^a%^C168%^r%^C167%^m%^C166%^t%^C172%^h%^C219%^ spreads through your body, %^C172%^in%^C166%^vi%^C167%^go%^C168%^ra%^C169%^ti%^C170%^ng%^C219%^ your senses.%^CRST%^");
                break;
            case 3:
                tell_object(player, "%^C044%^You sink into the %^C045%^pl%^C044%^us%^C043%^hn%^C042%^ess%^C044%^ of your cushion as a wave of %^C042%^eu%^C043%^ph%^C044%^or%^C045%^ia%^C044%^ pulls you %^C045%^d%^C044%^o%^C043%^wn%^C044%^, %^C045%^d%^C044%^o%^C043%^wn%^C044%^, %^C045%^d%^C044%^o%^C043%^wn%^C044%^...%^CRST%^");
                break;
            case 4:
                tell_object(player, "%^C243%^All of your worldly worries %^C244%^d%^C245%^r%^C246%^i%^C247%^f%^C245%^t%^C243%^ away just like that %^C245%^p%^C246%^u%^C247%^f%^C245%^f%^C243%^ of smo%^C245%^k%^C243%^e...%^CRST%^");
                break;
            case 5:
                tell_object(player, "%^C153%^You are floating...%^CRST%^");
                break;
        }
        tell_room(environment(player), "%^C245%^"+player->query_cap_name()+" %^C245%^stares into space with half-lidded eyes.%^CRST%^", player);
        player->add_intox(300);
        return 1;
    }
    return 0;
}

int stop_fun(string str){
    object player = this_player();
    if(!str || str != "smoking"){
        tell_object(player, "%^C059%^Try 'stop smoking'.%^CRST%^");
        return 0;
    }
    if(!player->query_property("smoking hookah")){
        tell_object(player, "%^C059%^You are not smoking the hookah.%^CRST%^");
        return 1;
    }
    tell_object(player, "%^C245%^You set the hose aside and stand feeling slightly dizzy.%^CRST%^");
    tell_room(environment(player), "%^CRST%^%^RESET%^%^C245%^"+player->query_cap_name()+" %^CRST%^%^RESET%^%^C245%^puts the pipe aside and stands.%^CRST%^", player);
    player->remove_property("smoking hookah");
    return 1;
}

