//Ryzan and Aunuit's House
//Coded by ~Circe~ 5/3/13

#include <std.h>
#include "aunuit.h"

inherit ROOM;

void create(){
    ::create();
    set_travel(PAVED_ROAD);
    set_terrain(BUILT_TUNNEL);
    set_name("Foreboding Tunnel");
    set_short("%^RESET%^%^CRST%^%^C244%^Foreboding tunnel%^RESET%^%^CRST%^");
    set_light(2);
    set_indoors(1);
    set_long("%^RESET%^%^CRST%^%^C244%^A massive %^RESET%^%^C088%^e%^C124%^x%^C160%^p%^C196%^l%^C202%^o%^C196%^s%^C160%^i%^C124%^o%^RESET%^%^C088%^n %^RESET%^%^C244%^of %^RESET%^%^C088%^h%^C124%^e%^C160%^a%^C088%^t%^RESET%^%^C244%^ and %^C241%^pressure%^C244%^ must have been used to create this %^C241%^cavernous tunnel%^C244%^. It is large enough for an army to march through and has been bore into the %^RESET%^%^C058%^earth%^RESET%^%^C244%^ at an angle descending subtly enough for foot traffic to easily pass in each direction. At first glance the %^C241%^g%^C245%^l%^C246%^o%^C247%^s%^C245%^s%^C241%^y stone %^C244%^appears to be %^C241%^pitch black%^C244%^, but upon closer inspection %^RESET%^%^C022%^v%^C028%^e%^C034%^r%^C040%^d%^C034%^a%^C028%^n%^C022%^t s%^C070%^w%^C076%^ir%^C070%^l%^C022%^s %^RESET%^%^C244%^can be seen in its surface. Triangular %^C241%^iron sconces %^C244%^have been mounted to the walls, %^RESET%^%^C161%^f%^C162%^a%^C163%^e%^C164%^r%^C165%^i%^C201%^e %^C200%^f%^C199%^i%^C198%^r%^C197%^e%^RESET%^%^C244%^ undulating within and casting %^C161%^e%^C162%^e%^C163%^r%^C162%^i%^C161%^e %^RESET%^%^C241%^shadows%^C244%^ across the dark stone.%^RESET%^%^CRST%^\n");
    set_smell("default","%^RESET%^%^CRST%^%^C075%^The %^C087%^cool air %^C075%^is tinged with a faint %^C245%^m%^C246%^e%^C247%^t%^C248%^a%^C249%^l%^C248%^l%^C247%^i%^C245%^c %^RESET%^%^C075%^scent.%^RESET%^%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C081%^The tunnel is bustling with activity as supply %^RESET%^%^C058%^carts%^C081%^ and %^C241%^carriages %^RESET%^%^C081%^make their way between the city and the docks.%^RESET%^%^CRST%^");
    /*set_items(([
        ({"sconce","sconces"}) : "%^BOLD%^%^BLACK%^Every twenty feet triangular ad%^RESET%^a%^BOLD%^%^BLACK%^m%^RESET%^a%^BOLD%^%^BLACK%^nt%^WHITE%^i%^BLACK%^te sc%^RESET%^o%^BOLD%^%^BLACK%^n%^WHITE%^c%^BLACK%^es have been mounted to the wall. Vivid %^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^i%^WHITE%^o%^MAGENTA%^l%^RESET%^%^MAGENTA%^et f%^BOLD%^%^MAGENTA%^a%^WHITE%^e%^MAGENTA%^r%^RESET%^%^MAGENTA%^ie f%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^re %^BOLD%^%^BLACK%^fli%^MAGENTA%^c%^BLACK%^kers within, casting %^MAGENTA%^eerie %^BLACK%^sh%^WHITE%^a%^BLACK%^d%^RESET%^o%^BOLD%^%^BLACK%^ws across the surfaces of the tunnel.%^RESET%^",
        ({"obsidian","dragon glass","walls","floor","ceiling"}) : "%^BOLD%^%^BLACK%^As bla%^RESET%^c%^BOLD%^%^BLACK%^k as p%^WHITE%^i%^BLACK%^tch and fl%^RESET%^a%^BOLD%^%^BLACK%^wl%^WHITE%^e%^RESET%^s%^BOLD%^%^BLACK%^s to the touch this st%^RESET%^o%^BOLD%^%^BLACK%^ne has a gl%^RESET%^o%^BOLD%^%^WHITE%^s%^BLACK%^sy sh%^WHITE%^e%^RESET%^e%^BOLD%^%^BLACK%^n akin to that of a %^MAGENTA%^g%^RESET%^%^MAGENTA%^e%^BOLD%^%^MAGENTA%^mst%^RESET%^%^MAGENTA%^o%^BOLD%^%^MAGENTA%^ne%^BLACK%^. It has been created from a massive explosion of %^RED%^h%^RESET%^%^RED%^e%^BOLD%^%^ORANGE%^a%^RED%^t %^BLACK%^and %^RESET%^%^ORANGE%^pressure%^BOLD%^%^BLACK%^, the r%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^ck having c%^CYAN%^o%^RESET%^%^CYAN%^o%^BOLD%^%^BLACK%^led so quickly afterward that the pattern of the sto%^RESET%^n%^BOLD%^%^BLACK%^e resembles a rapidly %^CYAN%^fl%^RESET%^%^CYAN%^o%^BOLD%^%^CYAN%^w%^WHITE%^i%^CYAN%^ng r%^RESET%^%^CYAN%^i%^GREEN%^v%^BOLD%^%^CYAN%^er%^BLACK%^, its surface sw%^WHITE%^e%^BLACK%^lling and e%^WHITE%^b%^RESET%^b%^BOLD%^%^BLACK%^ing. The entirety of the tunnel is forged from this exquisite sto%^RESET%^n%^BOLD%^%^BLACK%^e.%^RESET%^\n",
        ]));*/
    set_exits(([
        "west" : ROOMS"shadow15",
        "southeast" : ROOMS"tunnel02"
        ]));
}

