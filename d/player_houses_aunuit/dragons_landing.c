//Ryzan and Aunuit's House
//Coded by ~Circe~ 4/29/13

#include <std.h>
#include <player_housing.h>
#include <daemons.h>
#include "aunuit.h"

inherit VAULT;

int OPEN;
void set_auto_closed();

void create(){
    ::create();
    set_travel(PAVED_ROAD);
    set_terrain(STONE_BUILDING);
    set_name("Well-tended Courtyard");
    set_travel(PAVED_ROAD);
    set_terrain(BUILT_TUNNEL);
    set_light(1);
    set_indoors(1);
    set_short("%^RESET%^%^CRST%^%^C103%^Well-tended %^RESET%^%^C244%^Courtyard%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C103%^A sprawling %^RESET%^%^C244%^courtyard %^RESET%^%^C103%^lies before you, surrounded by a %^RESET%^%^C241%^palatial estate %^RESET%^%^C103%^whose %^RESET%^%^C241%^spires %^C103%^rise toward what appears to be an %^RESET%^%^C049%^a%^C050%^u%^C051%^r%^C087%^o%^C081%^r%^C075%^a %^RESET%^%^C153%^l%^C147%^i%^C141%^t %^C241%^night sky%^RESET%^%^C103%^. A %^C241%^path %^RESET%^%^C103%^leads from the gates and encircles an %^C230%^ivory statue %^C103%^central to the courtyard before reaching the front steps of the palace. Flanking the path are tall %^C241%^lamp posts %^RESET%^%^C103%^flying %^C055%^%^C129%^d%^C093%^a%^C129%^rk v%^C093%^i%^C129%^ol%^C093%^e%^C129%^t %^C103%^banners emblazoned with a %^RESET%^%^C244%^s%^C253%^e%^C255%^r%^C241%^p%^C253%^e%^C255%^n%^C253%^t%^C241%^i%^C255%^n%^C244%^e %^C255%^s%^C241%^i%^C255%^g%^C241%^i%^C244%^l%^RESET%^%^C103%^. %^C241%^W%^C244%^o%^C242%^o%^C241%^den b%^C242%^e%^C241%^nches %^RESET%^%^C103%^surround the statue and provide a place from which to enjoy the picturesque view of the immaculate %^RESET%^%^C022%^l%^C029%^a%^C036%^w%^C029%^n%^C022%^s %^RESET%^%^C103%^bordering the path. No matter the hour, rambunctious %^C171%^c%^C177%^h%^C183%^i%^C189%^l%^C195%^d%^C045%^r%^C039%^e%^C033%^n %^RESET%^%^C103%^play upon an enormous %^C093%^p%^C099%^l%^C105%^a%^C069%^y%^C063%^g%^C057%^r%^C056%^o%^C055%^u%^C054%^n%^C053%^d %^RESET%^%^C103%^that occupies the western yard. The walkway branches to the east, leading the way through a field of well-groomed %^RESET%^%^C040%^t%^C047%^r%^C084%^e%^C047%^e%^C040%^s %^RESET%^%^C103%^to a free-standing, multi-story %^C244%^dormitory%^C103%^. The walls of the cavern are lined with %^C241%^iron catwalks %^C103%^patrolled by %^RESET%^%^C241%^macabre m%^C244%^a%^C241%^r%^C247%^i%^C245%^o%^C241%^n%^C244%^e%^C241%^tt%^C245%^e%^C241%^s %^RESET%^%^C103%^that watch over the %^C022%^fields %^C103%^from all sides. Behind the dorm the ground gently slopes down toward a smaller %^C249%^cave%^RESET%^%^C103%^. The only obvious entrance to this place is barred by imposing wrought %^C241%^iron gates%^RESET%^%^C103%^.%^CRST%^\n");
    set_smell("default", "%^RESET%^%^CRST%^%^C032%^The %^C045%^c%^C051%^o%^C087%^o%^C045%^l air %^C032%^is %^C050%^f%^C051%^r%^C123%^e%^C122%^s%^C121%^h%^C032%^ but carries with it the slight %^RESET%^%^C245%^m%^C246%^e%^C247%^t%^C248%^a%^C249%^l%^C248%^l%^C247%^i%^C245%^c %^RESET%^%^C032%^tang of %^C088%^b%^C124%^l%^C160%^o%^C124%^o%^C088%^d%^C032%^.%^CRST%^");
    set_listen("default", "%^RESET%^%^CRST%^%^C244%^You hear the %^C088%^r%^C124%^a%^C160%^u%^C196%^c%^C160%^o%^C124%^u%^C088%^s %^RESET%^%^C244%^sounds of children playing against the the subtle backdrop of %^C027%^f%^C033%^l%^C039%^o%^C045%^w%^C051%^i%^C087%^n%^C123%^g %^C087%^w%^C051%^a%^C045%^t%^C039%^e%^C033%^r%^RESET%^%^C244%^.%^CRST%^");
    set_exits(([
        "cave" : ROOMS "pool",
        "gates" : ROOMS "gates",
        "north" : ROOMS "maw"
        ]));
    set_door("gates", ROOMS "gates", "gates", "aunuit_key_xyz", "runes"); //There is no key
    set_open("gates", 0);
    set_locked("gates", 1, "runes");
    lock_difficulty("gates",  LOCKS_LEGENDARY, "runes");
    set_door_description("gates", "%^RESET%^%^CRST%^%^C067%^Massive wrought %^RESET%^%^C241%^iron gates %^C067%^have been built into the sheer %^C244%^cavern wall %^RESET%^%^C067%^here. Crowned by intimidating %^C241%^spikes %^RESET%^%^C067%^and crawling with %^RESET%^%^C241%^a%^C243%^n%^C245%^i%^C247%^m%^C245%^a%^C243%^t%^C241%^e s%^C243%^h%^C245%^a%^C245%^d%^C247%^o%^C243%^w%^C241%^s %^RESET%^%^C067%^that obscure any view of what lies beyond, these gates give off an unnatural %^C045%^c%^C051%^h%^C087%^i%^C051%^l%^C045%^l%^RESET%^%^C067%^. A layer of %^C087%^r%^C123%^i%^C159%^m%^C195%^e %^RESET%^%^C067%^coats the %^C241%^bars%^RESET%^%^C067%^, causing them to %^C241%^t%^C195%^w%^C159%^i%^RESET%^%^C241%^n%^C195%^k%^C087%^l%^C241%^e %^RESET%^%^C067%^like %^C087%^s%^C123%^t%^C159%^a%^C195%^r%^C159%^d%^C123%^u%^C087%^s%^C123%^t %^C067%^within the %^RESET%^%^C241%^darkness%^RESET%^%^C067%^.%^CRST%^");
    set_lock_description("gates", "runes",
                         "%^BOLD%^%^BLACK%^Inscribed upon the door are various %^CYAN%^r"
                         "%^WHITE%^u%^CYAN%^nes %^BLACK%^of unknown origin.%^RESET%^");
    set_string("gates", "open", "%^RESET%^%^CRST%^%^C244%^The %^C241%^iron gates %^C244%^open with a soft %^C051%^h%^C087%^i%^C123%^s%^C159%^s%^RESET%^%^C244%^.%^CRST%^");
    set_string("gates", "close", "%^RESET%^%^CRST%^%^C244%^The %^C241%^iron gates %^C244%^close with a soft %^C051%^h%^C087%^i%^C123%^s%^C159%^s%^RESET%^%^C244%^.%^CRST%^");
    set_door("palace doors", ROOMS "maw", "north", "aunuit_key_xyz", "runes"); //There is no key
    set_open("palace doors", 0);
    set_locked("palace doors", 1, "lock");
    lock_difficulty("palace doors",  LOCKS_LEGENDARY, "lock");
    set_door_description("palace doors", "%^RESET%^%^CRST%^%^C244%^These beautiful %^C241%^ebon wood %^C244%^doors are set in an %^C230%^ivory frame %^C244%^that has been carved to depict countless humanoid %^C249%^phantoms%^C244%^, their faces twisted in varied expressions ranging from %^C126%^e%^C127%^c%^C128%^s%^C129%^t%^C128%^a%^C126%^s%^C126%^y %^C244%^to %^C088%^a%^C124%^g%^C160%^o%^C124%^n%^C088%^y%^RESET%^%^C244%^. The surface of the %^C241%^black wood %^C244%^is polished to a near %^C251%^m%^C252%^i%^C253%^r%^C255%^r%^C253%^o%^C251%^r s%^C252%^h%^C253%^e%^C255%^e%^C252%^n %^C244%^and serpentine %^C241%^iron handles %^C244%^have been crafted for each.%^CRST%^");
    set_search("default", "Whenever you are ready, it looks like you could simply <leave> through the gates.");
    set_items(([
        ({"catwalk", "catwalks"}) : "%^RESET%^%^CRST%^%^C241%^Iron catwalks %^RESET%^%^C059%^have been secured to the %^C244%^rock walls %^RESET%^%^C059%^and span the distance around the entirety of the courtyard. Patrolling these catwalks are dozens of macabre, multi-limbed %^RESET%^%^C241%^m%^C244%^a%^C241%^r%^C247%^i%^C245%^o%^C241%^n%^C244%^e%^C241%^tt%^C245%^e%^C241%^s %^RESET%^%^C059%^with all manner of %^C088%^w%^C124%^i%^C160%^c%^C196%^k%^C124%^e%^C088%^d %^RESET%^%^C059%^weapons gripped in their %^C241%^wooden hands%^RESET%^%^C059%^.%^CRST%^",
        ({"banner", "banners"}) : "%^RESET%^%^CRST%^%^C141%^These banners bear the crest of the %^RESET%^%^C241%^House of Black%^RESET%^%^C141%^; a stylized %^C245%^b%^C243%^l%^C242%^a%^C245%^c%^C242%^k %^C240%^B%^C141%^ with a %^C255%^w%^C253%^h%^C255%^i%^C253%^t%^C255%^e s%^C253%^e%^C255%^rp%^C253%^e%^C255%^n%^C253%^t%^C141%^ %^C255%^c%^C253%^o%^C251%^i%^C248%^l%^C253%^e%^C255%^d %^C141%^through it, set against a field of %^C129%^d%^C093%^a%^C129%^rk v%^C093%^i%^C129%^ol%^C093%^e%^C129%^t%^C141%^.%^CRST%^",
        ({"mansion", "estate", "palace"}) : "%^RESET%^%^CRST%^%^C241%^Grand spires %^RESET%^%^C110%^rise into the %^RESET%^%^C049%^a%^C050%^u%^C051%^r%^C087%^o%^C081%^r%^C075%^a %^RESET%^%^C153%^l%^C147%^i%^C141%^t%^, %^RESET%^%^C226%^s%^C227%^t%^C228%^a%^C229%^r%^C227%^r%^C226%^y %^RESET%^%^C110%^expanse of the %^C081%^h%^C075%^e%^C069%^a%^C097%^v%^C098%^e%^C099%^n%^C105%^s%^C110%^, creating an intimidating %^RESET%^%^C241%^silhouette %^C110%^for this palace. Crafted of %^C241%^black stone %^C110%^and %^C241%^ebon wood%^C110%^, the curving architecture is clearly a hybrid of Drow and human designs. Elegant arches, large %^RESET%^%^C053%^s%^C054%^t%^C055%^a%^C056%^i%^C057%^n%^C089%^e%^C090%^d%^RESET%^%^C244%^-%^C091%^g%^C092%^l%^C093%^a%^C057%^s%^C063%^s %^RESET%^%^C110%^windows, and spacious balconies are all heavily featured. Front and center, a wide staircase ascends to a spacious veranda supported by %^C241%^b%^C243%^l%^C245%^a%^C247%^c%^C245%^k %^C243%^m%^C241%^a%^C243%^r%^C245%^b%^C247%^l%^C245%^e %^C243%^p%^C241%^i%^C243%^l%^C245%^l%^C247%^a%^C245%^r%^C243%^s%^C110%^, %^C241%^large double doors %^RESET%^%^C110%^shielded by the patio. Outdoor seating options decorate the gallery, allowing one to lounge comfortably. %^RESET%^%^C241%^M%^C052%^a%^C088%^l%^C124%^e%^C088%^v%^C052%^o%^C241%^l%^C052%^e%^C088%^n%^C124%^t%^RESET%^%^C110%^-looking %^C244%^g%^C247%^a%^C244%^rg%^C242%^o%^C244%^yl%^C248%^e%^C244%^s %^RESET%^%^C110%^perch upon the uppermost ledges, overlooking the grounds.%^CRST%^",
        ({"western lawn", "playground"}) : "%^RESET%^%^CRST%^%^C072%^The western lawn is occupied by a massive playground crafted from solid %^C241%^ebon wood %^RESET%^%^C072%^and obstacle courses that appear to be cobbled-together from broken %^C247%^statuary%^C072%^, all of which has been defaced by childish %^C093%^g%^C099%^r%^C105%^a%^C069%^f%^C063%^f%^C057%^i%^C056%^t%^C055%^i%^C072%^. Countless children climb %^C058%^ladders %^C072%^and %^C249%^nets%^RESET%^%^C072%^, swing across %^C241%^iron monkey bars%^C072%^, and leap from place to place, including a statue of an %^C241%^obsidian dragon%^C072%^, its wings shattered. They %^C170%^l%^C176%^a%^C182%^u%^C183%^g%^C177%^h %^C072%^with %^C170%^joy %^C072%^and %^C040%^j%^C041%^e%^C042%^e%^C040%^r %^C072%^at each other, many of them clutching %^C088%^b%^C124%^l%^C196%^oo%^C124%^d%^C088%^y sh%^C124%^a%^C241%^r%^C088%^ds%^RESET%^%^C072%^ of %^C241%^obsidian %^RESET%^%^C072%^in their little hands. Dark %^C052%^sanguine stains %^C072%^spatter the %^C022%^grass%^C072%^, the playground, and the children themselves.%^CRST%^",
        "statue" : "%^RESET%^%^CRST%^%^C230%^This %^RESET%^%^C110%^e%^C123%^t%^C159%^h%^C153%^e%^C195%^r%^C189%^e%^C231%^a%^C225%^l %^C255%^ivory statue %^C230%^captures a %^RESET%^%^C124%^romantic %^C230%^moment in time. A handsome man in a %^C241%^macabre top hat %^C230%^and a lithe, horned woman in a %^RESET%^%^C092%^risque %^C230%^dress are pressed together in the traditional closed position; they each have one arm outstretched, hands clasped together, whilst her other arm is wrapped around his shoulder, and his is pressed to the small of her scarred back. The artist that sculpted this statue meticulously rendered every element, from the way the couple gazes %^C099%^longingly %^RESET%^%^C230%^at one another to the fine details of their clothing. The well-built man is %^RESET%^%^C093%^fa%^C092%^s%^C091%^h%^C089%^i%^C093%^on%^C089%^a%^C091%^b%^C092%^l%^C093%^y %^RESET%^%^C230%^dressed, wearing a vest, form-fitting slacks, and sleek shoes. The band of his aforementioned hat is slung with %^RESET%^%^C088%^a%^C124%^g%^C160%^o%^C196%^n%^C160%^i%^C124%^z%^C088%^e%^C124%^d %^RESET%^%^C230%^looking dolls, their %^C241%^forlorn %^C230%^stares also fixated on the %^C255%^beautiful %^C230%^woman in his arms. Conversely, she is dressed in as little as possible, a chain-bound snakeskin gown hugging her %^RESET%^%^C125%^a%^C126%^l%^C127%^l%^C128%^u%^C129%^r%^C128%^i%^C127%^n%^C125%^g %^RESET%^%^C230%^form as tightly as any lover, its plunging neckline revealing a starburst-shaped brand on her chest. Her upswept horns, curved and ridged like that of a ram, emerge from a sea of long hair caught mid-sway as they dance. %^RESET%^%^C241%^Un%^C246%^du%^C243%^la%^C246%^ti%^C241%^ng darkness %^C230%^encircles the duo, clinging to their supple limbs and trailing from their bodies, giving the statue an almost %^RESET%^%^C087%^l%^C086%^i%^C051%^v%^C050%^i%^C045%^n%^C044%^g %^RESET%^%^C230%^quality to it, despite its stillness. A plaque can be read at the base of the statue.%^CRST%^",
        "ceiling" : "%^RESET%^%^CRST%^%^C061%^Where there should be a ceiling of %^C058%^dirt %^C061%^and %^C244%^stone %^RESET%^%^C061%^instead is the vast beauty of the night sky, %^C189%^g%^C195%^l%^C231%^i%^C230%^t%^C255%^t%^C159%^e%^C087%^r%^C153%^i%^C123%^n%^C194%^g %^RESET%^%^C061%^with thousands upon thousands of %^C081%^s%^C123%^t%^C195%^a%^C159%^r%^C075%^s%^RESET%^%^C061%^. A brilliant %^RESET%^%^C049%^a%^C050%^u%^C051%^r%^C087%^o%^C081%^r%^C075%^a %^C061%^in hues of %^C027%^b%^C033%^l%^C039%^u%^C045%^e%^C061%^, %^RESET%^%^C040%^g%^C046%^r%^C082%^e%^C076%^e%^C070%^n%^C061%^, and %^RESET%^%^C129%^v%^C135%^i%^C141%^o%^C147%^l%^C141%^e%^C135%^t %^RESET%^%^C061%^splashes across the %^C027%^c%^C099%^o%^C228%^s%^C075%^m%^C147%^i%^C192%^c %^C061%^tapestry. The %^C244%^stone walls %^RESET%^%^C061%^rise up on all sides and disappear into the image as if being swallowed by the %^RESET%^%^C241%^night %^RESET%^%^C061%^itself.%^CRST%^",
        ({"trees", "eastern field", "dormitory"}) : "%^RESET%^%^CRST%^%^C072%^The eastern field is a stark contrast to the %^RESET%^%^C241%^utilitarian %^RESET%^%^C072%^landscape on the western side. While sharing the same %^C040%^v%^C041%^e%^C042%^r%^C043%^d%^C042%^a%^C041%^n%^C042%^t %^C041%^g%^C040%^r%^C041%^a%^C042%^s%^C043%^s%^RESET%^%^C072%^ carpet, the ground slopes and rises in %^C076%^r%^C077%^o%^C078%^l%^C077%^l%^C076%^i%^C077%^n%^C078%^g %^C077%^h%^C076%^i%^C076%^l%^C077%^l%^C078%^s %^C072%^with %^C082%^unnatural trees %^C072%^dotting its landscape. The %^C040%^leaves %^RESET%^%^C072%^of the trees %^C048%^p%^C047%^u%^C050%^l%^C049%^s%^C084%^a%^C085%^t%^C047%^e %^C072%^with a strange %^RESET%^%^C046%^p%^C047%^h%^C048%^o%^C049%^s%^C050%^p%^C051%^h%^C087%^o%^C086%^r%^C085%^e%^C084%^s%^C083%^c%^C082%^e%^C119%^n%^C120%^t light %^C072%^that casts flowing %^C241%^s%^C243%^h%^C245%^a%^C247%^d%^C245%^o%^C243%^w%^C241%^s %^RESET%^%^C072%^across the ground. The dominant feature of the field though is the tall %^C244%^s%^C243%^t%^C241%^o%^C243%^n%^C244%^e building %^RESET%^%^C072%^that houses dormitories for the many children who reside here. Behind the dorm is the narrow entrance to another %^RESET%^%^C249%^cave%^RESET%^%^C072%^.%^CRST%^",
            ]));
    OPEN = 0;
    set_property("teleport proof", TPWARD_LEGENDARY);
    set_property("scry proof", SCRYWARD_LEGENDARY);
}

void init(){
    ::init();
    add_action("read_em", "read");
    add_action("leave_em", "leave");
}

int read_em(string str){
    if(!str) return 0;
    if(str == "plaque") {
        tell_object(TP, "%^RESET%^%^CRST%^%^C244%^The plaque reads:%^CRST%^\n%^RESET%^%^C251%^Bound together by darkest fate,%^CRST%^\n%^RESET%^%^C253%^A hunger they could never sate,%^CRST%^\n%^RESET%^%^C251%^The stars grew dim and the heavens wept,%^CRST%^\n%^RESET%^%^C249%^The night the Herald and the Serpent met,%^CRST%^\n%^RESET%^%^C247%^Now dancing to Her siren's song,%^CRST%^\n%^RESET%^%^C245%^The days grow short and the shadows long,%^CRST%^\n%^RESET%^%^C243%^Beneath their steps the world does crack,%^CRST%^\n%^RESET%^%^C241%^And thus was born the House of Black%^CRST%^");
        if(!TP->query_invis() && !TP->query_hidden()) tell_room(TO, "" + TPQCN + " seems to be studying the plaque.");
        return 1;
    }
}

int leave_em(){
    object dest = find_object_or_load("/d/player_houses/aunuit/gates.c");
    tell_object(TP, "As you walk toward the gates, they begin to open.");
    tell_room(TO, "%^RESET%^%^CRST%^%^C244%^The %^C241%^iron gates %^C244%^open with a soft %^C051%^h%^C087%^i%^C123%^s%^C159%^s%^RESET%^%^C244%^.%^RESET%^%^CRST%^");
    set_locked("gates", 0, "runes");
    set_open("gates", 1);
    tell_room(dest, "%^RESET%^%^CRST%^%^C244%^One of the %^C241%^marionettes s%^C243%^h%^C245%^u%^C243%^d%^C241%^d%^C243%^e%^C245%^r%^C243%^s %^C244%^to %^C049%^l%^C050%^i%^C051%^f%^C049%^e%^RESET%^%^C244%^, leaning in to inspect you, your own features %^C243%^r%^C245%^e%^C247%^f%^C249%^l%^C243%^e%^C245%^c%^C247%^t%^C249%^e%^C243%^d %^C244%^in the smooth, convex %^C241%^surface %^C244%^of its face. After a moment, it turns toward the %^C241%^gates %^C244%^and reaches into the %^C241%^w%^C243%^r%^C245%^i%^C241%^t%^C243%^h%^C245%^i%^C241%^n%^C243%^g %^C245%^s%^C241%^h%^C243%^a%^C245%^d%^C241%^o%^C243%^w %^C244%^there, opening the way for you.%^CRST%^");
    dest->set_locked("gates", 0, "runes");
    dest->set_open("gates", 1);
    call_out("set_auto_closed", 15);
    OPEN = 1;
    return 1;
}

void set_auto_closed()
{
    object dest;
    dest = find_object_or_load("/d/player_houses/aunuit/gates.c");
    tell_room(TO, "%^RESET%^%^CRST%^%^C244%^The %^C241%^iron gates %^C244%^close with a soft %^C051%^h%^C087%^i%^C123%^s%^C159%^s%^RESET%^%^C244%^.%^CRST%^");
    set_locked("gates", 1, "runes");
    set_open("gates", 0);
    tell_room(dest, "%^RESET%^%^CRST%^%^C244%^One of the %^C241%^marionettes s%^C243%^h%^C245%^u%^C243%^d%^C241%^d%^C243%^e%^C245%^r%^C243%^s %^C244%^to %^C049%^l%^C050%^i%^C051%^f%^C049%^e%^RESET%^%^C244%^, reaching out to close the %^C241%^gates %^C244%^behind you. If not for the fact that it does not have a mouth, you would swear you hear it %^C159%^sigh %^C244%^in %^C045%^ex%^C051%^as%^C087%^pe%^C123%^ra%^C051%^ti%^C045%^on%^RESET%^%^C244%^. Perhaps that was only the sound of the gates closing...%^CRST%^");
    dest->set_locked("gates", 1, "runes");
    dest->set_open("gates", 0);
    OPEN = 0;
    return;
}

void reset(){
    ::reset();
    switch(random(7)){
        case 0 : 
            tell_room(TO, "%^RESET%^%^CRST%^%^C038%^A %^C051%^c%^C087%^h%^C123%^i%^C159%^l%^C123%^l%^C087%^i%^C051%^n%^C087%^g %^C123%^w%^C159%^a%^C123%^i%^C087%^l %^RESET%^%^C038%^arises from the %^C028%^l%^C034%^a%^C040%^w%^C028%^n %^RESET%^%^C038%^outside the %^RESET%^%^C244%^dormitory %^C038%^as one child robs another of their toy. Within moments, they’re in a %^RESET%^%^C088%^b%^C124%^r%^C160%^u%^C124%^t%^C088%^a%^C124%^l %^C160%^b%^C124%^r%^C088%^a%^C124%^w%^C160%^l%^RESET%^%^C038%^, their tiny fists flying.%^CRST%^");
            break;
        case 1 : 
            tell_room(TO, "%^RESET%^%^C204%^High-pitched %^C202%^l%^C208%^a%^C209%^u%^C210%^g%^C209%^h%^C208%^t%^C202%^e%^C203%^r %^C204%^rings out as a pair of %^C255%^doll%^RESET%^%^C204%^-like little %^C211%^girls %^C204%^play on a %^RESET%^%^C094%^seesaw %^C204%^on the playground.%^CRST%^");
            break;
        case 2 : 
            tell_room(TO, "%^RESET%^%^CRST%^%^C080%^A group of %^C171%^c%^C177%^h%^C183%^i%^C189%^l%^C195%^d%^C045%^r%^C039%^e%^C033%^n %^RESET%^%^C080%^spills from the back of the %^RESET%^%^C244%^dormitories%^RESET%^%^C080%^, %^C033%^r%^C039%^u%^C045%^n%^C051%^n%^C045%^i%^C039%^n%^C033%^g %^C080%^and %^C202%^l%^C208%^a%^C209%^u%^C210%^g%^C209%^h%^C208%^i%^C202%^n%^C203%^g %^RESET%^%^C080%^as they head for the smaller cave behind the building.%^CRST%^");
            break;
        case 3 : 
            tell_room(TO, "%^RESET%^%^CRST%^%^C024%^A young boy falls from the %^RESET%^%^C241%^monkey bars%^C024%^, crying despondently until a lanky %^C241%^m%^C243%^a%^C245%^r%^C243%^i%^C241%^o%^C243%^n%^C245%^e%^C243%^t%^C241%^t%^C243%^e %^RESET%^%^C024%^approaches, pulls him to his feet, and %^C094%^dusts %^RESET%^%^C024%^him off.%^CRST%^");
            break;
        case 4 : 
            tell_room(TO, "%^RESET%^%^CRST%^%^C121%^A pair of %^C045%^older boys %^C121%^get into a tussle, %^C243%^s%^C245%^h%^C247%^o%^C245%^v%^C243%^i%^C245%^n%^C247%^g %^RESET%^%^C121%^each other back and forth and %^C088%^s%^C124%^h%^C160%^o%^C124%^u%^C088%^t%^C124%^i%^C160%^n%^C124%^g%^RESET%^%^C121%^. In a %^C231%^f%^C230%^l%^C229%^a%^C230%^s%^C231%^h%^RESET%^%^C121%^, one pulls out a shard of %^RESET%^%^C241%^obsidian %^C121%^and runs the other one through!%^CRST%^");
            break;
        case 5 : 
            tell_room(TO, "%^RESET%^%^CRST%^%^C088%^A %^C241%^m%^C243%^a%^C245%^r%^C243%^i%^C241%^o%^C243%^n%^C245%^e%^C243%^t%^C241%^t%^C243%^e %^RESET%^%^C088%^drags the b%^C124%^a%^C160%^t%^C124%^t%^C088%^e%^C124%^r%^C160%^e%^C124%^d%^C088%^, %^RESET%^%^C252%^lifeless body %^C088%^of a teenager toward the cave behind the %^C244%^dormitories%^RESET%^%^C088%^.%^CRST%^");
            break;
        default :
            tell_room(TO, "%^RESET%^%^CRST%^%^C242%^A %^C241%^m%^C243%^a%^C245%^r%^C243%^i%^C241%^o%^C243%^n%^C245%^e%^C243%^t%^C241%^t%^C243%^e %^C242%^stands at the center of a group of excited %^C171%^c%^C177%^h%^C183%^i%^C189%^l%^C195%^d%^C045%^r%^C039%^e%^C033%^n%^RESET%^%^C242%^, handing out big round %^RESET%^%^C161%^l%^C162%^o%^C163%^l%^C164%^l%^C163%^i%^C162%^p%^C161%^o%^C162%^p%^C163%^s%^RESET%^%^C242%^.%^CRST%^");
            break;
    }
}

