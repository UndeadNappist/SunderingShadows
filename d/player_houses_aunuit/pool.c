//Ryzan and Aunuit's House
//Coded by ~Circe~ 5/2/13

#include <std.h>
#include "aunuit.h"
#include <daemons.h>
#include <player_housing.h>

inherit ROOM;

#define POSITIONS ({"enemies","guests","members","leaders","owners"})

string *enemies = SAVE_D->query_array("rilynath_enemies");
string *members = SAVE_D->query_array("rilynath_members");
string *owners = SAVE_D->query_array("rilynath_owners");
string *guests = SAVE_D->query_array("rilynath_guests");
string *leaders = SAVE_D->query_array("rilynath_leaders");

int help_em(string str);
int get_authority(object obj);
void update();
int is_enemy(string str); //attempted this way to see if it would avoid the need to update the room before the changes take place, but the delay is still there.

void create(){
    ::create();
    set_name("Pools of the Lost");
    set_travel(PAVED_ROAD);
    set_terrain(BUILT_TUNNEL);
    set_light(1);
    set_indoors(1);
    set_short("%^RESET%^%^CRST%^%^C027%^P%^C033%^o%^C039%^o%^C045%^l%^C051%^s %^C024%^of the %^RESET%^%^C244%^Lost%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C024%^Enveloped in %^C057%^u%^C056%^n%^C055%^n%^C054%^a%^C053%^t%^C052%^u%^C088%^r%^C124%^a%^C125%^l f%^C126%^l%^C127%^o%^C128%^r%^C129%^a %^RESET%^%^C024%^that winds throughout the cavern completely obscuring its %^C244%^stone walls%^RESET%^%^C024%^, this %^C043%^o%^C044%^a%^C045%^s%^C050%^i%^C049%^s %^C024%^is clearly the work of powerful %^C027%^magic %^C024%^and dedicated maintenance. The central feature of this %^C034%^g%^C040%^a%^C046%^r%^C082%^d%^C076%^e%^C070%^n %^RESET%^%^C024%^are two trees - one %^RESET%^%^C241%^gl%^C243%^o%^C245%^s%^C241%^sy black %^RESET%^%^C024%^and the other %^C244%^g%^C102%^r%^C145%^a%^RESET%^%^C244%^y %^RESET%^%^C024%^and gnarled - %^RESET%^%^C241%^t%^C243%^w%^C241%^i%^C102%^s%^C241%^t%^C145%^e%^RESET%^%^C241%^d %^C024%^around one another, their boughs heavy with %^RESET%^%^C241%^dark fruit %^RESET%^%^C024%^and %^C088%^m%^C124%^a%^C160%^c%^C196%^a%^C160%^b%^C124%^r%^RESET%^%^C088%^e o%^C124%^r%^C160%^n%^C196%^a%^C160%^m%^C124%^e%^C088%^n%^C124%^t%^C160%^s%^RESET%^%^C024%^. They stand exalted on a hill that rises out of one of many %^C033%^p%^C039%^o%^C045%^o%^C039%^l%^C033%^s%^C024%^ which are connected by smaller %^C039%^s%^C045%^t%^C051%^r%^C087%^e%^C051%^a%^C045%^m%^C039%^s%^C024%^. A %^RESET%^%^C025%^w%^C026%^a%^C027%^t%^C033%^e%^C032%^r%^C031%^f%^C039%^a%^C038%^l%^C045%^l %^RESET%^%^C024%^descends through the %^C046%^v%^C080%^i%^C081%^n%^C080%^e%^C046%^s %^RESET%^%^C024%^along the north wall feeding the winding channels with its %^C051%^c%^C087%^r%^RESET%^%^C123%^y%^C195%^s%^C123%^t%^C087%^a%^C051%^l%^C087%^l%^C123%^i%^C195%^n%^C123%^e %^C195%^w%^C123%^a%^C087%^t%^C051%^e%^C087%^r%^RESET%^%^C024%^. There are no paved paths interrupting the growth and coiled %^C046%^th%^C022%^o%^C046%^rny creepers %^RESET%^%^C024%^threaten any who delve too deeply into the foliage. Near the opening to this chamber is a %^RESET%^%^C241%^wooden trellis%^C024%^, similarly overgrown, messages hanging from the %^C028%^thorns%^RESET%^%^C024%^.%^CRST%^\n");
    set_smell("default", "%^RESET%^%^CRST%^%^C023%^The heady scent of %^C057%^f%^C056%^l%^C055%^o%^C054%^w%^C053%^e%^C052%^r%^C088%^s %^RESET%^%^C023%^fills the cave.%^CRST%^");
    set_listen("default", "%^RESET%^%^CRST%^%^C030%^Except for the occasional shout or laugh of children the %^C024%^b%^C025%^a%^C026%^b%^C027%^b%^C033%^l%^C039%^i%^C045%^n%^C051%^g %^C030%^of the waterfall masks the sounds of the main cavern.%^CRST%^");
    set_items(([
        ({"stream", "waterfall", "pond"}) : "%^RESET%^%^CRST%^%^C038%^Water trickles down the north face of the %^RESET%^%^C244%^cavern wall%^C038%^, winding its way between %^C046%^v%^C080%^i%^C081%^n%^C080%^e%^C046%^s %^RESET%^%^C038%^and over large %^C057%^b%^C056%^l%^C055%^o%^C054%^o%^C053%^m%^C052%^in%^C088%^g%^C124%^ %^C125%^f%^C126%^l%^C127%^o%^C128%^w%^C129%^e%^C135%^r%^C141%^s%^RESET%^%^C038%^, leaving everything %^RESET%^%^C051%^g%^C087%^l%^C123%^i%^C195%^s%^C159%^t%^C195%^e%^C123%^n%^C087%^i%^C051%^n%^C087%^g %^RESET%^%^C038%^in its wake. The %^C025%^w%^C026%^a%^C027%^t%^C033%^e%^C032%^r%^C031%^f%^C039%^a%^C038%^l%^C045%^l %^RESET%^%^C038%^feeds %^C039%^s%^C045%^t%^C051%^r%^C087%^e%^C051%^a%^C045%^m%^C039%^s%^C038%^ that crisscross the cavern floor and collect in the natural valleys of the %^RESET%^%^C244%^stone %^C038%^to create several %^C033%^p%^C039%^o%^C045%^o%^C039%^l%^C033%^s%^C038%^.%^CRST%^",
        ({"pool", "pools"}) : "%^RESET%^%^CRST%^%^C045%^Closer inspection of the %^C033%^p%^C039%^o%^C045%^o%^C039%^l%^C033%^s %^RESET%^%^C045%^reveals a %^RESET%^%^C107%^g%^C108%^h%^C150%^a%^C151%^s%^C150%^t%^C108%^l%^C107%^y %^RESET%^%^C045%^scene. Deep within the %^C159%^clear water %^RESET%^%^C045%^among the slowly swaying %^C035%^a%^C036%^q%^C037%^u%^C038%^a%^C039%^t%^C045%^i%^C044%^c %^C043%^f%^C042%^o%^C042%^l%^C041%^i%^C040%^a%^C046%^g%^C047%^e %^C045%^are dozens of elven %^C102%^c%^C252%^o%^C102%^rps%^C108%^e%^C102%^s %^RESET%^%^C045%^in various states of %^RESET%^%^C101%^d%^C102%^e%^C108%^c%^C107%^a%^C101%^y%^RESET%^%^C045%^. Men, women, and children stare upward from the depths with %^RESET%^%^C255%^milky eyes%^RESET%^%^C045%^, their jaws agape as if they all died with %^C052%^s%^C088%^c%^C124%^r%^C160%^e%^C124%^a%^C088%^m%^C052%^s %^RESET%^%^C045%^on their lips.%^CRST%^",
        "trellis" : "%^RESET%^%^CRST%^%^C034%^Snake-like %^C046%^v%^C080%^i%^C081%^n%^C080%^e%^C046%^s %^C034%^climb up an %^RESET%^%^C241%^ebon wood trellis %^C034%^that extends from a %^C244%^stone base%^RESET%^%^C034%^. Any passersby that wish to leave a message can by impaling their %^C230%^p%^C244%^a%^C230%^rchm%^C101%^e%^C230%^nt %^RESET%^%^C034%^on one of the many %^C022%^thorns %^C034%^that extend from the thick, %^C046%^glowing vines%^RESET%^%^C034%^.%^CRST%^",
        ({"vines", "foliage"}) : "%^RESET%^%^CRST%^%^C121%^The foliage that exists within this cave is %^RESET%^%^C027%^o%^C033%^t%^C039%^h%^C045%^e%^C051%^r%^C087%^w%^C087%^o%^C081%^r%^C075%^l%^C069%^d%^C063%^l%^C062%^y%^RESET%^%^C121%^; the walls and floors are a veritable smorgasbord of glowing colors that reflect off the %^C087%^water %^C121%^and %^C051%^m%^C087%^o%^C123%^t%^C159%^e%^C051%^s %^C121%^of %^C024%^p%^C025%^r%^C026%^e%^C027%^c%^C033%^i%^C032%^p%^C031%^i%^C039%^t%^C038%^a%^C045%^t%^C051%^i%^C087%^o%^C123%^n %^RESET%^%^C121%^to create a %^RESET%^%^C046%^p%^C047%^h%^C048%^o%^C049%^s%^C050%^p%^C051%^h%^C087%^o%^C086%^r%^C085%^e%^C084%^s%^C083%^c%^C082%^e%^C119%^n%^C120%^t %^RESET%^%^C121%^h%^C122%^a%^C123%^z%^C051%^e%^RESET%^%^C121%^. Spiny, snake-like %^C046%^v%^C080%^i%^C081%^n%^C080%^e%^RESET%^%^C046%^s glow softly%^RESET%^%^C121%^, illuminating the %^RESET%^%^C241%^nooks %^RESET%^%^C121%^and %^C244%^crannies %^C121%^of the room. Large flowers burst forth from the meandering creepers, their stems bedecked in sharp %^RESET%^%^C022%^thorns%^C121%^. The petals of the flowers display a %^RESET%^%^C057%^b%^C056%^r%^C055%^i%^C054%^l%^C053%^l%^C052%^i%^C088%^a%^C124%^n%^C125%^t %^C126%^a%^C127%^r%^C128%^r%^C129%^a%^C135%^y %^RESET%^%^C121%^of silhouettes and hues, from a star-shaped, %^C055%^deep purple flower %^C121%^with %^C046%^bright green flecks %^C121%^to a %^RESET%^%^C088%^c%^C124%^r%^C160%^i%^C124%^m%^C088%^s%^C124%^o%^C160%^n %^RESET%^%^C121%^bell-like bulb with %^C241%^black stripes%^RESET%^%^C121%^.%^CRST%^",
        "tree" : "%^RESET%^%^CRST%^%^C069%^Standing tall and casting their %^C129%^v%^C135%^i%^C141%^o%^C146%^l%^C140%^e%^C134%^t%^C128%^ %^C093%^l%^C099%^u%^C105%^m%^C104%^i%^C098%^n%^C092%^e%^C055%^s%^C056%^c%^C057%^e%^C063%^n%^C105%^c%^C141%^e %^RESET%^%^C069%^across the %^C033%^p%^C039%^o%^C045%^o%^C039%^l%^C033%^s %^RESET%^%^C069%^these trees are the defining feature of the %^C040%^g%^C035%^a%^C036%^r%^C042%^d%^C041%^e%^C040%^n%^C069%^. Compared to the beauty of the rest of the %^C046%^foliage%^RESET%^%^C069%^, there is something %^C244%^disquieting %^RESET%^%^C069%^about the parasitic coupling of the beautiful %^RESET%^%^C241%^obsidian tree %^C069%^and the gnarled and %^C101%^l%^C058%^e%^C094%^a%^C101%^fl%^C243%^e%^RESET%^%^C101%^ss m%^C058%^o%^C101%^nstr%^C058%^o%^C101%^s%^RESET%^%^C094%^i%^C101%^ty %^RESET%^%^C069%^that twists around it. The %^C241%^dark limbs %^RESET%^%^C069%^are choked by the thick %^C246%^gr%^C248%^a%^C246%^y b%^C248%^o%^C245%^u%^C246%^ghs %^RESET%^%^C069%^and there is a %^C147%^dim%^RESET%^%^C069%^, %^C244%^fl%^C147%^i%^C141%^c%^RESET%^%^C244%^ke%^C105%^r%^C099%^i%^RESET%^%^C244%^ng %^C099%^violet light %^RESET%^%^C069%^that emanates from within them. %^C062%^O%^C063%^i%^C069%^l%^C062%^y %^RESET%^%^C241%^black fruit %^C069%^can be seen growing among the tangle of limbs as well as %^C088%^m%^C124%^a%^C160%^c%^C196%^a%^C160%^b%^C124%^r%^C088%^e t%^C124%^o%^C160%^y%^C088%^s %^RESET%^%^C069%^tied by %^C241%^black string %^RESET%^%^C069%^to the branches. A %^RESET%^%^C241%^black ichor %^RESET%^%^C069%^bleeds from the %^C246%^gray bark %^RESET%^%^C069%^while the smooth %^RESET%^%^C241%^gl%^C243%^a%^C247%^s%^C241%^sy %^RESET%^%^C069%^surface of the other tree has faintly %^C135%^glowing lines %^RESET%^%^C069%^etched upon its surface. Upon closer inspection it is apparent that they form script that flows seamlessly into itself and %^C129%^s%^C135%^h%^C141%^if%^C135%^t%^C129%^s %^RESET%^%^C069%^into your native tongue before your very eyes:%^CRST%^\n\n%^RESET%^%^CRST%^%^C135%^In m%^C141%^e%^C189%^m%^C141%^o%^C135%^ry of all who f%^C141%^o%^C189%^ug%^C141%^h%^C135%^t to r%^C135%^e%^C141%^s%^C189%^to%^C141%^r%^C135%^e what was lost. May their f%^C141%^a%^C189%^ilur%^C141%^e%^C135%^s h%^C141%^a%^C189%^u%^C141%^n%^C135%^t them for e%^C141%^t%^C189%^erni%^C141%^t%^C135%^y.%^CRST%^\n\n%^RESET%^%^CRST%^%^C069%^Beneath the %^C135%^m%^C141%^es%^C189%^sa%^C141%^ge%^RESET%^%^C069%^, hundreds of %^C135%^n%^C141%^a%^C189%^m%^C141%^e%^C135%^s %^C069%^are also etched into the surface of the %^RESET%^%^C241%^tree%^RESET%^%^C069%^, apparent record of the fallen.%^CRST%^",
        ]));
    set_property("silent update",1);
    set_exits(([
        "west": ROOMS"dragons_landing"
        ]));
    set_property("teleport proof", TPWARD_LEGENDARY);
    set_property("scry proof", SCRYWARD_LEGENDARY);
}

void reset(){
    object ob;
    ::reset();
    if(!objectp(present(getuid(TO)+"_board"))){
        ob = new("std/bboard");
        ob->set_name(getuid(TO)+"board");
        ob->set_id( ({ "board", getuid(TO)+"_board", "my board" }) );
        ob->set_board_id(geteuid(TO)+"_board");
        ob->set_short("%^RESET%^%^CRST%^%^C022%^A %^C046%^v%^C080%^i%^C081%^n%^C080%^e%^C046%^-strewn %^RESET%^%^C230%^m%^C144%^e%^C230%^ss%^C144%^a%^C230%^g%^C101%^e %^RESET%^%^C230%^b%^C144%^o%^C101%^a%^C230%^rd%^CRST%^");
        ob->set_long("%^RESET%^%^C034%^Snake-like %^C046%^v%^C080%^i%^C081%^n%^C080%^e%^C046%^s %^RESET%^%^C034%^climb up an %^RESET%^%^C241%^ebon wood trellis %^C034%^that extends from a %^C244%^stone base%^RESET%^%^C034%^. Any passersby that wish to leave a message can by impaling their %^C230%^p%^C244%^a%^C230%^rchm%^C101%^e%^C230%^nt %^RESET%^%^C034%^on one of the many %^C022%^thorns %^C034%^that extend from the thick, %^C046%^glowing vines%^RESET%^%^C034%^.%^CRST%^\n");
        ob->set_max_posts(20);
        ob->set_ooc_board(0);
        ob->set_location(base_name(TO));
        ob->move(TO);
        ob->set_property("no steal",1);
    }
    switch(random(7)){
        case 0 : 
            tell_room(TO,"%^RESET%^%^CRST%^%^C130%^With a %^C064%^s%^C065%^i%^C066%^c%^C065%^k%^C064%^e%^C065%^n%^C066%^i%^C065%^n%^C064%^g burble %^C130%^a %^C109%^c%^C108%^o%^C107%^rp%^C108%^s%^C109%^e %^C130%^pierces the surface of one of the %^C045%^p%^C051%^o%^C087%^o%^C051%^l%^C045%^s%^C130%^. A fat %^C094%^w%^C130%^a%^C058%^t%^C130%^e%^C094%^r b%^C130%^u%^C094%^g %^C130%^slips out of its mouth, taking flight with a %^C094%^b%^C058%^u%^C064%^z%^C070%^z%^RESET%^%^C130%^. A moment later the body is sucked back beneath the %^C045%^w%^C051%^a%^C123%^t%^C051%^e%^C045%^r%^C130%^.%^CRST%^");
            break;
        case 1 : 
            tell_room(TO,"%^RESET%^%^CRST%^%^C037%^A %^C027%^b%^C033%^i%^C039%^o%^C045%^l%^C051%^u%^C045%^m%^C039%^i%^C033%^n%^C027%^e%^C033%^s%^C039%^c%^C045%^e%^C051%^n%^C045%^t %^C039%^d%^C033%^r%^C027%^%^C033%^a%^C039%^g%^C045%^o%^C051%^n %^C045%^f%^C039%^l%^C033%^y %^RESET%^%^C037%^buzzes past.%^CRST%^");
            break;
        case 2 : 
            tell_room(TO,"%^RESET%^%^CRST%^%^C027%^The %^C094%^pl%^C058%^ai%^C094%^nt%^C058%^i%^C094%^v%^C058%^e %^C094%^cr%^C058%^oa%^C094%^k %^C027%^of a %^C021%^c%^C027%^a%^C033%^v%^C039%^e t%^C045%^o%^C033%^a%^C021%^d %^C027%^can be heard from somewhere nearby.%^CRST%^");
            break;
        case 3 : 
            tell_room(TO,"%^RESET%^%^CRST%^%^C109%^A %^C102%^h%^C145%^a%^C152%^u%^C145%^n%^C102%^t%^C145%^i%^C152%^n%^C102%^g%^C109%^, %^C031%^s%^C032%^o%^C033%^r%^C038%^r%^C039%^o%^C081%^w%^C075%^f%^C069%^u%^C068%^l %^RESET%^%^C109%^wail suddenly pierces the air.%^CRST%^");
            break;
        case 4 : 
            tell_room(TO,"%^RESET%^%^CRST%^%^C244%^A %^C051%^c%^C087%^o%^C123%^o%^C159%^l %^C123%^b%^C087%^r%^C051%^e%^C087%^e%^C123%^z%^C159%^e %^RESET%^%^C244%^moves through the cave, causing the %^C088%^o%^C124%^r%^C160%^n%^C196%^a%^C160%^m%^C124%^e%^C088%^n%^C124%^t%^C160%^s %^C244%^to clink %^C241%^eerily%^C244%^.%^CRST%^");
            break;
        case 5 : 
            tell_room(TO,"%^RESET%^%^CRST%^%^C044%^A nearby %^C125%^f%^C126%^l%^C127%^o%^C128%^w%^C126%^e%^C125%^r %^C044%^bursts into %^C125%^bloom%^C044%^, releasing motes of %^C226%^g%^C227%^o%^C228%^l%^C229%^d%^C228%^e%^C227%^n %^C226%^p%^C227%^o%^C228%^l%^C229%^l%^C228%^e%^C227%^n %^RESET%^%^C044%^into the air.%^CRST%^");
            break;
        default : 
            tell_room(TO,"%^RESET%^%^CRST%^%^C046%^A %^C047%^g%^C048%^ro%^C049%^up %^C050%^of %^C051%^c%^C123%^h%^C122%^i%^C121%^l%^C120%^d%^C119%^r%^C118%^e%^C190%^n %^C191%^r%^C192%^ac%^C193%^e i%^C194%^n%^C195%^t%^C159%^o t%^C158%^he %^C157%^ca%^C156%^ve%^C155%^, %^C154%^l%^C082%^au%^C083%^ghi%^C084%^n%^C085%^g b%^C086%^r%^C087%^e%^C159%^a%^C158%^t%^C157%^hl%^C156%^e%^C155%^s%^C154%^s%^C118%^ly %^C119%^a%^C120%^s %^C121%^th%^C122%^e%^C123%^y %^C051%^c%^C050%^ra%^C049%^w%^RESET%^%^C048%^l b%^C047%^e%^C046%^n%^C040%^e%^C041%^at%^C042%^h %^C043%^a %^C044%^c%^C045%^ur%^C051%^t%^C123%^ai%^C122%^n %^C121%^o%^C120%^f %^C119%^th%^C118%^o%^C190%^r%^C191%^n%^C192%^y v%^C193%^i%^C194%^n%^C195%^e%^C159%^s, %^C087%^d%^C086%^is%^C085%^a%^C084%^p%^C083%^pe%^C082%^a%^C046%^r%^C047%^i%^C048%^n%^C049%^g f%^C050%^r%^C051%^o%^C123%^m %^C122%^v%^C119%^ie%^C118%^w%^C082%^.%^CRST%^");
            break;
    }
}

void init(){
   ::init();
   add_action("add_em","add");
   add_action("erase_em","erase");
   add_action("list_em","list");
   add_action("help_em","help");
}

int get_authority(object obj){
   int authority;
   if(avatarp(obj)) return 3;
   if(member_array(obj->query_name(), owners) != -1){
      authority = 3;
   }else if(member_array(obj->query_name(), leaders) != -1){
      authority = 2;
   }else if(member_array(obj->query_name(), members) != -1){
      authority = 1;
   }else{
      authority = 0;
   }
   return authority;
}

int is_enemy(string str){
   int enemy;
   if(member_array(str,enemies) != -1){
      enemy = 1;
   }else{
      enemy = 0;
   }
   return enemy;
}

int add_em(string str){
   string name,position,real;
   int auth;
   if(!str){
      help_em("here");
      return 1;
   }
   if(sscanf(str,"%s to %s",name,position) != 2){
      help_em("here");
      return 1;
   }
   if(member_array(position,POSITIONS) == -1){
      help_em("here");
      return 1;
   }
   if(TP->isKnown(name)){ 
      real = name; 
   }else{ 
      real = (string)TP->realName(name); 
   }
   if(real == ""){
      tell_object(TP,"You don't seem to know anyone named "+name+".");
      return 1;
   }
   auth = get_authority(TP);
   switch(position){
      case "enemies": if(auth < 1){
                         tell_object(TP,"You don't have the authority to do that!");
                         return 1;
                      }
                      if(is_enemy(real)){
                         tell_object(TP,""+capitalize(name)+" is already an enemy of the House!");
                         break;
                      }else{
                         SAVE_D->set_value("rilynath_enemies",real);
                         tell_object(TP,""+capitalize(name)+" has been added to the list of House enemies.");
                         break;
                      }
      case "members": if(auth < 2){
                         tell_object(TP,"You don't have the authority to do that!");
                         return 1;
                      }
                      if(member_array(real,members) != -1){
                         tell_object(TP,""+capitalize(name)+" is already a member of the House!");
                         break;
                      }else{
                         SAVE_D->set_value("rilynath_members",real);
                         tell_object(TP,""+capitalize(name)+" has been added to the list of House members.");
                         break;
                      }
      case "guests": if(auth < 1){
                         tell_object(TP,"You don't have the authority to do that!");
                         return 1;
                      }
                      if(member_array(real,guests) != -1){
                         tell_object(TP,""+capitalize(name)+" is already a guest of the House!");
                         break;
                      }else{
                         SAVE_D->set_value("rilynath_guests",real);
                         tell_object(TP,""+capitalize(name)+" has been added to the list of House guests.");
                         break;
                      }
      case "leaders":  if(auth < 3){
                         tell_object(TP,"You don't have the authority to do that! Please talk to a House owner.");
                         break;
                      }
                      if(member_array(real,leaders) != -1){
                         tell_object(TP,""+capitalize(name)+" is already a leader of the House!");
                         break;
                      }else{
                         SAVE_D->set_value("rilynath_leaders",real);
                         tell_object(TP,""+capitalize(name)+" has been added to the list of House leaders.");
                         break;
                      }
      case "owners":  if(auth < 3){
                         tell_object(TP,"You don't have the authority to do that! Please talk to a House owner.");
                         break;
                      }
                      if(member_array(real,owners) == 1){
                         tell_object(TP,""+capitalize(name)+" is already an owner of the House!");
                         break;
                      }else{
                         SAVE_D->set_value("rilynath_owners",real);
                         tell_object(TP,""+capitalize(name)+" has been added to the list of House owners.");
                         break;
                      }
      default: tell_object(TP,"Something seems to have gone wrong! Please try again.");
               break;
   }
   update();
   return 1;
}


int erase_em(string str){
   string name,position,real;
   int auth;
   if(!str){
      help_em("here");
      return 1;
   }
   if(sscanf(str,"%s from %s",name,position) != 2){
      help_em("here");
      return 1;
   }
   if(member_array(position,POSITIONS) == -1){
      help_em("here");
      return 1;
   }
   if(TP->isKnown(name)){ 
      real = name; 
   }else{ 
      real = (string)TP->realName(name); 
   }
   if(real == ""){
      tell_object(TP,"You don't seem to know anyone named "+name+".");
      return 1;
   }
   auth = get_authority(TP);
   switch(position){
      case "enemies": if(auth < 1){
                         tell_object(TP,"You don't have the authority to do that!");
                         return 1;
                      }
                      if(is_enemy(real)){
                         SAVE_D->remove_name_from_array("rilynath_enemies",real);
                         tell_object(TP,""+capitalize(name)+" has been removed from the list of House enemies.");
                         break;
                      }else{
                         tell_object(TP,""+capitalize(name)+" is not an enemy of the House!");
                         break;
                      }
      case "members": if(auth < 2){
                         tell_object(TP,"You don't have the authority to do that!");
                         return 1;
                      }
                      if(member_array(real,members) == -1){
                         tell_object(TP,""+capitalize(name)+" is not a member of the House!");
                         break;
                      }else{
                         SAVE_D->remove_name_from_array("rilynath_members",real);
                         tell_object(TP,""+capitalize(name)+" has been removed from the list of House members.");
                         break;
                      }
      case "guests": if(auth < 1){
                         tell_object(TP,"You don't have the authority to do that!");
                         return 1;
                      }
                      if(member_array(real,guests) == -1){
                         tell_object(TP,""+capitalize(name)+" is not a guest of the House!");
                         break;
                      }else{
                         SAVE_D->remove_name_from_array("rilynath_guests",real);
                         tell_object(TP,""+capitalize(name)+" has been removed from the list of House guests.");
                         break;
                      }
      case "leaders":  if(auth < 3){
                         tell_object(TP,"You don't have the authority to do that! Please talk to a House owner.");
                         break;
                      }
                      if(member_array(real,leaders) == -1){
                         tell_object(TP,""+capitalize(name)+" is not a leader of the House!");
                         break;
                      }else{
                         SAVE_D->remove_name_from_array("rilynath_leaders",real);
                         tell_object(TP,""+capitalize(name)+" has been removed from the list of House leaders.");
                         break;
                      }
      case "owners":  if(auth < 3){
                         tell_object(TP,"You don't have the authority to do that! Please talk to a House owner.");
                         break;
                      }
                      if(member_array(real,owners) == -1){
                         tell_object(TP,""+capitalize(name)+" is not an owner of the House!");
                         break;
                      }else{
                         SAVE_D->remove_name_from_array("rilynath_owners",real);
                         tell_object(TP,""+capitalize(name)+" has been removed from the list of House owners.");
                         break;
                      }
      default: tell_object(TP,"Something seems to have gone wrong! Please try again.");
               break;
   }
   update();
   return 1;
}

int list_em(string str){
   string listtext, *listkeys, name;
   mapping list;
   int i,access,auth;

   list = ([]);

   if(!str){
      help_em("here");
      return 1;
   }
   if(member_array(str,POSITIONS) == -1){
      help_em("here");
      return 1;
   }
   auth = get_authority(TP);
   switch(str){
      case "enemies": if(auth < 1){
                         tell_object(TP,"You don't have the authority to do that!");
                         return 1;
                      }
                      list = SAVE_D->query_array("rilynath_enemies");
                      break;
      case "members": if(auth < 1){
                         tell_object(TP,"You don't have the authority to do that!");
                         return 1;
                      }
                      list = SAVE_D->query_array("rilynath_members");
                      break;
      case "owners": if(auth < 1){
                         tell_object(TP,"You don't have the authority to do that!");
                         return 1;
                      }
                      list = SAVE_D->query_array("rilynath_owners");
                      break;
      case "guests": if(auth < 1){
                         tell_object(TP,"You don't have the authority to do that!");
                         return 1;
                     }
                     list = SAVE_D->query_array("rilynath_guests");
                     break;
      case "leaders": if(auth < 1){
                         tell_object(TP,"You don't have the authority to do that!");
                         return 1;
                     }
                     list = SAVE_D->query_array("rilynath_leaders");
                     break;
   }
   listtext = "The following individuals are "+str+" of House Rilynath.\n";
   listtext += ""
   "%^BOLD%^%^BLACK%^====================================================================%^RESET%^\n";
   
   if(!list || list == ""){
      tell_object(TP,"There are no "+str+" for House Rilynath!");
      return 1;
   }
   for(i=0;i<sizeof(list);i++){
      name = list[i];
      if(TP->isKnown(name)){
         name = TP->knownAs(name);
      }else{
         name = name;
      }
      if(name == "circe") continue;
      listtext += ""+capitalize(name)+"\n";
   }
   listtext += ""
   "%^BOLD%^%^BLACK%^====================================================================%^RESET%^\n";
   TP->more(explode(listtext,"\n"));
   return 1;    
}

void update(){
   "/cmds/system/_update.c"->cmd_update();
   return 1;
}

int help_em(string str){
   if(!str || str == "here"){
      write("A member of House Rilynath may:\n"
         "   add [name] to [guests | enemies]\n"
         "   erase [name] from [guests | enemies]\n"
         "   list [enemies | guests | members | leaders | owners]\n\n"
         "In addition, a leader of House Rilynath may:\n"
         "   add [name] to [members]\n"
         "   erase [name] from [members]\n\n"
         "House owners may also:\n"
         "   add [name] to [leaders | owners]\n"
         "   erase [name] from [leaders | owners]\n");
      return 1;
   }
   return 0;
}
