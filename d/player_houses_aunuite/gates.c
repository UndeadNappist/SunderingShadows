//Ryzan and Aunuit's House
//Coded by ~Circe~ 5/3/13

#include <std.h>
#include <player_housing.h>
#include "aunuit.h"
#include <daemons.h>

inherit VAULT;

void set_auto_closed();
void guardian_death();

int OPEN, guardians;

string* enemies = SAVE_D->query_array("rilynath_enemies");
string* members = SAVE_D->query_array("rilynath_members");
string* owners = SAVE_D->query_array("rilynath_owners");
string* guests = SAVE_D->query_array("rilynath_guests");
string* leaders = SAVE_D->query_array("rilynath_leaders");

void create(){
    ::create();
    set_travel(PAVED_ROAD);
    set_terrain(BUILT_TUNNEL);
    set_name("The Great Gates");
    set_short("%^RESET%^%^CRST%^%^C244%^Outside the %^C241%^shadow%^C246%^-%^C244%^sh%^C242%^ro%^C244%^ud%^C246%^ed %^C241%^gates%^RESET%^%^CRST%^");
    set_light(2);
    set_indoors(1);
    set_long("%^RESET%^%^CRST%^%^C244%^A massive %^RESET%^%^C088%^e%^C124%^x%^C160%^p%^C196%^l%^C202%^o%^C196%^s%^C160%^i%^C124%^o%^RESET%^%^C088%^n %^RESET%^%^C244%^of %^RESET%^%^C088%^h%^C124%^e%^C160%^a%^C088%^t%^RESET%^%^C244%^ and %^C241%^pressure%^C244%^ must have been used to create this %^C241%^cavernous tunnel%^C244%^. At first glance the %^C241%^g%^C245%^l%^C246%^o%^C247%^s%^C245%^s%^C241%^y stone %^C244%^appears to be %^C241%^pitch black%^C244%^, but upon closer inspection %^RESET%^%^C022%^v%^C028%^e%^C034%^r%^C040%^d%^C034%^a%^C028%^n%^C022%^t s%^C070%^w%^C076%^ir%^C070%^l%^C022%^s %^RESET%^%^C244%^can be seen in its surface. Triangular %^C241%^iron sconces %^C244%^have been mounted to the walls, %^RESET%^%^C161%^f%^C162%^a%^C163%^e%^C164%^r%^C165%^i%^C201%^e %^C200%^f%^C199%^i%^C198%^r%^C197%^e%^RESET%^%^C244%^ undulating within and casting %^C161%^e%^C162%^e%^C163%^r%^C162%^i%^C161%^e %^RESET%^%^C241%^shadows%^C244%^ across the dark stone. Set back from the main thoroughfare, gargantuan %^C241%^shadow%^C244%^-s%^C246%^h%^C248%^r%^C241%^o%^C246%^u%^C248%^d%^C241%^e%^C244%^d, %^C087%^r%^C123%^i%^C159%^m%^C195%^e%^RESET%^%^C244%^-coated %^C241%^iron gates %^C244%^have been built directly into a sheer wall. Flanking the gates and just as tall is a pair of %^C246%^unsettling%^C244%^, four-armed %^C241%^marionettes%^RESET%^%^C244%^.%^RESET%^%^CRST%^\n");
    set_smell("default", "%^RESET%^%^CRST%^%^C075%^The %^C087%^cool air %^C075%^is tinged with a faint %^C245%^m%^C246%^e%^C247%^t%^C248%^a%^C249%^l%^C248%^l%^C247%^i%^C245%^c %^RESET%^%^C075%^scent.%^RESET%^%^CRST%^");
    set_listen("default", "%^RESET%^%^CRST%^%^C081%^The tunnel is bustling with activity as supply %^RESET%^%^C058%^carts%^C081%^ and %^C241%^carriages %^RESET%^%^C081%^make their way between the city and the docks.%^RESET%^%^CRST%^");
    set_items(([
        /*"mural" : "%^BOLD%^%^BLACK%^Carved into the large ad%^WHITE%^a%^BLACK%^mant%^RESET%^i%^BOLD%^%^BLACK%^te gates this %^RESET%^%^MAGENTA%^mural %^BOLD%^%^BLACK%^pictures two groups of %^GREEN%^e%^RESET%^%^GREEN%^l%^CYAN%^v%^GREEN%^e%^BOLD%^%^GREEN%^s %^BLACK%^coming together at the feet of a large %^RESET%^dragon%^BOLD%^%^BLACK%^. The %^BLUE%^elves %^BLACK%^on the left hand side are emerging from the depths of a %^RESET%^c%^ORANGE%^a%^WHITE%^v%^BOLD%^%^BLACK%^e and the %^RESET%^%^ORANGE%^elves %^BOLD%^%^BLACK%^on the right hand side are stepping out of a %^GREEN%^lush f%^RESET%^%^GREEN%^o%^CYAN%^r%^GREEN%^e%^BOLD%^%^GREEN%^st. The %^RESET%^dragon %^BOLD%^%^BLACK%^they gather around has spread its we%^RESET%^b%^BOLD%^%^WHITE%^b%^BLACK%^ed w%^WHITE%^i%^BLACK%^ngs to shelter the %^GREEN%^fey%^BLACK%^.%^RESET%^",
        ({ "sconce", "sconces" }) : "%^BOLD%^%^BLACK%^Every twenty feet triangular ad%^RESET%^a%^BOLD%^%^BLACK%^m%^RESET%^a%^BOLD%^%^BLACK%^nt%^WHITE%^i%^BLACK%^te sc%^RESET%^o%^BOLD%^%^BLACK%^n%^WHITE%^c%^BLACK%^es have been mounted to the wall. Vivid %^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^i%^WHITE%^o%^MAGENTA%^l%^RESET%^%^MAGENTA%^et f%^BOLD%^%^MAGENTA%^a%^WHITE%^e%^MAGENTA%^r%^RESET%^%^MAGENTA%^ie f%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^re %^BOLD%^%^BLACK%^fli%^MAGENTA%^c%^BLACK%^kers within, casting %^MAGENTA%^eerie %^BLACK%^sh%^WHITE%^a%^BLACK%^d%^RESET%^o%^BOLD%^%^BLACK%^ws across the surfaces of the tunnel.%^RESET%^",
        ({ "obsidian", "dragon glass", "walls", "floor", "ceiling" }) : "%^BOLD%^%^BLACK%^As bla%^RESET%^c%^BOLD%^%^BLACK%^k as p%^WHITE%^i%^BLACK%^tch and fl%^RESET%^a%^BOLD%^%^BLACK%^wl%^WHITE%^e%^RESET%^s%^BOLD%^%^BLACK%^s to the touch this st%^RESET%^o%^BOLD%^%^BLACK%^ne has a gl%^RESET%^o%^BOLD%^%^WHITE%^s%^BLACK%^sy sh%^WHITE%^e%^RESET%^e%^BOLD%^%^BLACK%^n akin to that of a %^MAGENTA%^g%^RESET%^%^MAGENTA%^e%^BOLD%^%^MAGENTA%^mst%^RESET%^%^MAGENTA%^o%^BOLD%^%^MAGENTA%^ne%^BLACK%^. It has been created from a massive explosion of %^RED%^h%^RESET%^%^RED%^e%^BOLD%^%^ORANGE%^a%^RED%^t %^BLACK%^and %^RESET%^%^ORANGE%^pressure%^BOLD%^%^BLACK%^, the r%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^ck having c%^CYAN%^o%^RESET%^%^CYAN%^o%^BOLD%^%^BLACK%^led so quickly afterward that the pattern of the sto%^RESET%^n%^BOLD%^%^BLACK%^e resembles a rapidly %^CYAN%^fl%^RESET%^%^CYAN%^o%^BOLD%^%^CYAN%^w%^WHITE%^i%^CYAN%^ng r%^RESET%^%^CYAN%^i%^GREEN%^v%^BOLD%^%^CYAN%^er%^BLACK%^, its surface sw%^WHITE%^e%^BLACK%^lling and e%^WHITE%^b%^RESET%^b%^BOLD%^%^BLACK%^ing. The entirety of the tunnel is forged from this exquisite sto%^RESET%^n%^BOLD%^%^BLACK%^e.%^RESET%^",
        ({ "draconic sentinel", "dragon", "construct", "statue", "sentinel", "sentinels", "dragons" }) : "%^RESET%^Standing opposite of its twin this %^BOLD%^%^BLACK%^adam%^RESET%^a%^BOLD%^%^BLACK%^nt%^WHITE%^i%^BLACK%^te draconic effigy %^RESET%^guards the %^BOLD%^%^BLACK%^gargantuan gates%^RESET%^. The lower portion of its body is %^BOLD%^%^BLACK%^c%^RESET%^o%^BOLD%^%^WHITE%^i%^BLACK%^l%^RESET%^e%^BOLD%^%^BLACK%^d%^RESET%^, its powerful %^BOLD%^%^BLACK%^mus%^RESET%^c%^BOLD%^%^BLACK%^les fle%^RESET%^x%^BOLD%^%^BLACK%^ed %^RESET%^with the effort of take-off, and its %^BOLD%^%^BLACK%^wings %^RESET%^are arched as they gather %^CYAN%^w%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^nd %^WHITE%^beneath them. One of its %^RED%^claws %^WHITE%^barely grazes the ground and the other is suspended in the %^BOLD%^%^CYAN%^air %^RESET%^before it. The dragon's %^BOLD%^%^BLACK%^h%^RESET%^o%^BOLD%^%^BLACK%^rned head %^RESET%^and n%^BOLD%^%^BLACK%^e%^RESET%^ck are arched no less elegantly than a %^BOLD%^%^WHITE%^swan's %^RESET%^and its sharp %^BOLD%^%^BLACK%^black scales gl%^WHITE%^e%^RESET%^a%^BOLD%^%^BLACK%^m %^RESET%^danger%^BOLD%^%^RED%^o%^RESET%^usly. Its open mouth is lined with countless ra%^BOLD%^%^WHITE%^z%^RED%^o%^WHITE%^r%^RESET%^-sh%^BOLD%^%^WHITE%^a%^RESET%^rp teeth and the statue's skilled craftsman has even detailed a %^GREEN%^r%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^ptil%^CYAN%^i%^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^n t%^BOLD%^%^GREEN%^o%^RESET%^%^GREEN%^ng%^CYAN%^u%^GREEN%^e %^RESET%^that licks restlessly at the air.%^RESET%^",*/
        "marionettes" : "%^RESET%^%^CRST%^%^C244%^These %^C071%^a%^C072%^l%^C073%^i%^C072%^e%^C071%^n%^RESET%^%^C244%^-like constructs appear to be carved from l%^C246%^u%^C248%^s%^C250%^t%^C252%^r%^C248%^o%^C246%^u%^C244%^s %^C241%^ebony wood%^C244%^. They stand on either side of the %^C241%^iron gates%^C244%^, guarding them like two %^C249%^disquieting %^C244%^giants. Each one is equipped with four %^C241%^s%^C242%^p%^C124%^i%^C244%^d%^C246%^e%^C242%^r%^C241%^y %^C244%^arms that seem to be %^RESET%^%^C051%^f%^C087%^r%^C123%^o%^C195%^z%^C087%^e%^C051%^n %^RESET%^%^C244%^mid-movement, giving the impression that they could %^C049%^s%^C050%^p%^C051%^r%^C123%^i%^C122%^n%^C121%^g %^RESET%^%^C244%^back to life at any moment. Their heads are humanoid in shape, but where there would normally be a face, instead is a s%^C243%^m%^C242%^o%^C241%^o%^C243%^t%^C242%^h %^C241%^featureless %^C244%^expanse %^C250%^buffed %^C244%^to a %^C245%^r%^C246%^e%^C247%^f%^C248%^l%^C249%^e%^C246%^c%^C248%^t%^C249%^i%^C250%^v%^C249%^e sheen%^RESET%^%^C244%^. There is no distinguishable personality to these marionettes; they maintain their %^C241%^silent vigil%^C244%^.%^RESET%^%^CRST%^",
        ]));
    set_exits(([
        "gates" : ROOMS "dragons_landing",
        "west" : ROOMS "tunnel05",
        "east" : ROOMS "tunnel216",
        ]));
    set_door("gates", ROOMS "dragons_landing", "gates", "aunuit_key_xyz", "runes"); //There is no key
    set_open("gates", 0);
    set_locked("gates", 1, "runes");
    lock_difficulty("gates",  LOCKS_LEGENDARY, "runes");
    set_lock_description("gates", "runes", "%^BOLD%^%^BLACK%^Inscribed upon the door are various %^CYAN%^r%^WHITE%^u%^CYAN%^nes %^BLACK%^of unknown origin.%^RESET%^");
    set_door_description("gates", "%^RESET%^%^CRST%^%^C067%^Massive wrought %^RESET%^%^C241%^iron gates %^C067%^have been built into the sheer %^C244%^cavern wall %^RESET%^%^C067%^here. Crowned by intimidating %^C241%^spikes %^RESET%^%^C067%^and crawling with %^RESET%^%^C241%^a%^C243%^n%^C245%^i%^C247%^m%^C245%^a%^C243%^t%^C241%^e s%^C243%^h%^C245%^a%^C245%^d%^C247%^o%^C243%^w%^C241%^s %^RESET%^%^C067%^that obscure any view of what lies beyond, these gates give off an unnatural %^C045%^c%^C051%^h%^C087%^i%^C051%^l%^C045%^l%^RESET%^%^C067%^. A layer of %^C087%^r%^C123%^i%^C159%^m%^C195%^e %^RESET%^%^C067%^coats the %^C241%^bars%^RESET%^%^C067%^, causing them to %^C241%^t%^C195%^w%^C159%^i%^RESET%^%^C241%^n%^C195%^k%^C087%^l%^C241%^e %^RESET%^%^C067%^like %^C087%^s%^C123%^t%^C159%^a%^C195%^r%^C159%^d%^C123%^u%^C087%^s%^C123%^t %^C067%^within the %^RESET%^%^C241%^darkness%^RESET%^%^C067%^. Flanking the gates and just as tall is a pair of %^C246%^unsettling%^RESET%^%^C067%^, four-armed %^C241%^marionettes%^RESET%^%^C067%^.%^RESET%^%^CRST%^");
    set_string("gates", "open", "%^RESET%^%^CRST%^%^C244%^The %^C241%^iron gates %^C244%^open with a soft %^C051%^h%^C087%^i%^C123%^s%^C159%^s%^RESET%^%^C244%^.%^CRST%^");
    set_string("gates", "close", "%^RESET%^%^CRST%^%^C244%^The %^C241%^iron gates %^C244%^close with a soft %^C051%^h%^C087%^i%^C123%^s%^C159%^s%^RESET%^%^C244%^.%^CRST%^");
    OPEN = 0;
    guardians = 2;
    set_pre_exit_functions(({ "GoThroughDoor" }), ({ "gates" }));
    set_property("no phase", 1);
}

int GoThroughDoor()
{
    if (present("marionette sentinel", TO) && !TP->query_true_invis()) {
        tell_object(TP, "The marionette sentinel is blocking the way!");
        return 0;
    }
    return ::GoThroughDoor();
}

void reset()
{
    ::reset();
    guardians = 2;
}

void init()
{
    ::init();
    add_action("present_em", "present");
}

void guardian_death()
{
    guardians--;
    return;
}

int present_em(string str)
{
    string race, name;
    object sigil, dest;
    int authority;
    enemies = SAVE_D->query_array("rilynath_enemies");
    name = TPQN;
    if (!str || str != "sigil") {
        tell_object(TP, "What are you trying to present?");
        return 1;
    }
    race = TP->query_race();
    sigil = present("rilynath_sigil", TP);
    dest = find_object_or_load("/d/player_houses/aunuit/dragons_landing.c");
    if (!sigil) {
        tell_object(TP, "You don't have any sigil!");
        return 1;
    }
    if (member_array(TP->query_name(), owners) != -1) {
        tell_object(TP, "Before you can even present your sigil, a voice welcomes you home.");
        tell_room(TO, "Before " + TPQCN + " can present " + TP->QP + " sigil, a sibilant voice speaks.", TP);
        if ((string)TP->query_name() == "ryzan") {
            tell_room(TO, "%^RESET%^%^MAGENTA%^The voice murmurs:%^RESET%^ Welcome home, Valuuuk.");
        }else if ((string)TP->query_name() == "aunuit") {
            tell_room(TO, "%^RESET%^%^MAGENTA%^The voice murmurs:%^RESET%^ Welcome home, Valsssharesss.");
        }else {
            tell_room(TO, "%^RESET%^%^MAGENTA%^The voice murmurs:%^RESET%^ Welcome home, massster.");
        }
    }
    authority = "/d/player_houses/aunuit/pool.c"->get_authority(TP);
    tell_room(TO, "%^RESET%^%^CRST%^%^C244%^One of the %^C241%^marionettes s%^C243%^h%^C245%^u%^C243%^d%^C241%^d%^C243%^e%^C245%^r%^C243%^s %^C244%^to %^C049%^l%^C050%^i%^C051%^f%^C049%^e%^RESET%^%^C244%^, leaning in to inspect you, your own features %^C243%^r%^C245%^e%^C247%^f%^C249%^l%^C243%^e%^C245%^c%^C247%^t%^C249%^e%^C243%^d %^C244%^in the smooth, convex %^C241%^surface %^C244%^of its face. After a moment, it turns toward the %^C241%^gates %^C244%^and reaches into the %^C241%^w%^C243%^r%^C245%^i%^C241%^t%^C243%^h%^C245%^i%^C241%^n%^C243%^g %^C245%^s%^C241%^h%^C243%^a%^C245%^d%^C241%^o%^C243%^w %^C244%^there, opening the way for you.%^CRST%^");
    set_locked("gates", 0, "runes");
    set_open("gates", 1);
    tell_room(dest, "%^RESET%^%^CRST%^%^C244%^The %^C241%^iron gates %^C244%^open with a soft %^C051%^h%^C087%^i%^C123%^s%^C159%^s%^RESET%^%^C244%^.%^CRST%^");
    dest->set_locked("gates", 0, "runes");
    dest->set_open("gates", 1);
    call_out("set_auto_closed", 15);
    OPEN = 1;
    if (authority < 1) {
        if (race != "drow" || race != "elf" || member_array(name, enemies) != -1) {
            if (guardians && !present("draconic sentinel", TO)) {
                tell_room(TO, "%^BOLD%^%^BLACK%^A deafening commotion of metal "
                          "grinding against metal fills the cavern as the dragons "
                          "begin to move. They let out a shrill, metallic roar "
                          "and move to block the entrance.%^RESET%^");
                tell_room(dest, "%^BOLD%^%^BLACK%^A deafening commotion of metal "
                          "grinding against metal fills the cavern as the dragons "
                          "begin to move. They let out a shrill, metallic roar "
                          "and move to block the entrance.%^RESET%^");
                new(OBJ "draconic_sentinel")->move(TO);
                new(OBJ "draconic_sentinel")->move(TO);
            }
        }
    }
    return 1;
}

void set_auto_closed()
{
    object dest;
    dest = find_object_or_load("/d/player_houses/aunuit/dragons_landing.c");
    tell_room(TO, "%^RESET%^%^CRST%^%^C244%^One of the %^C241%^marionettes s%^C243%^h%^C245%^u%^C243%^d%^C241%^d%^C243%^e%^C245%^r%^C243%^s %^C244%^to %^C049%^l%^C050%^i%^C051%^f%^C049%^e%^RESET%^%^C244%^, reaching out to close the %^C241%^gates %^C244%^behind you. If not for the fact that it does not have a mouth, you would swear you hear it %^C159%^sigh %^C244%^in %^C045%^ex%^C051%^as%^C087%^pe%^C123%^ra%^C051%^ti%^C045%^on%^RESET%^%^C244%^. Perhaps that was only the sound of the gates closing...%^CRST%^");
    set_locked("gates", 1, "runes");
    set_open("gates", 0);
    tell_room(dest, "%^RESET%^%^CRST%^%^C244%^The %^C241%^iron gates %^C244%^close with a soft %^C051%^h%^C087%^i%^C123%^s%^C159%^s%^RESET%^%^C244%^.%^CRST%^");
    dest->set_locked("gates", 1, "runes");
    dest->set_open("gates", 0);
    OPEN = 0;
    return;
}

/*
   Gate functions
   Ok disregard all the gate function stuff from the previous mail. Rewrote this with the idea of the place being broken into equally well by any class while allowing us to still scry/tp proof the area. No longer is there a door in the gate with a gatekeeper. Please replace the gate description in the "Dragons landing" room with this new one along with adding the mural.

   The new function will be "present sigil" at the gate. This will only work if the player has a house sigil(lootable from the wandering guards and assassins which should travel in groups and be strong enough to be a challenge to solo high level players just to make the keys not super easy to get)


   We need a way to list enemies who will be attacked on sight by wandering guards and assassins. All who murder a guard for his sigil should immediately be added to this list. We need to be able to add and remove individuals from the list as well.

   Also a function added to list house members we can add to and remove from and those will be able to "request sigil" from guards to replace any they might have lost or to give to a potential new member.

   You can add a few more tunnel rooms as well, more space for the wandering guards to travel on. The foreboding tunnel generic can be used as many times as you like. Maybe add a line to the thief tunnel it joins that the wall has been melted out to indicate the fire burrowing that was done.




 */
