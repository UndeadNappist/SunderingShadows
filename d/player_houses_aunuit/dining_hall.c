
//Coded by ~Circe~ 7/24/13, updated by Faebala 08/03/22
//menu added by Tsera 06/19/14

#include <std.h>
#include <player_housing.h>
#include <daemons.h>
#include "aunuit.h"

inherit ROOM;


void init() {
    ::init();
    add_action("read", "read");
}



void create(){
   ::create();
   set_name("Nightshade Lounge");
   set_travel(PAVED_ROAD);
   set_terrain(BUILT_TUNNEL);
   set_light(1);
   set_indoors(1);
   set_short("%^RESET%^%^CRST%^%^C240%^N%^C241%^i%^C242%^g%^C243%^h%^C244%^t%^C245%^s%^C243%^h%^C242%^a%^C241%^d%^C240%^e L%^C241%^o%^C242%^u%^C243%^n%^C241%^g%^C240%^e%^CRST%^");
   set_long("%^CRST%^%^RESET%^%^C244%^This spacious lounge immediately overwhelms the senses with its %^C240%^disorienting darkness%^RESET%^%^C244%^, the black walls a %^C246%^f%^C248%^r%^C250%^i%^C246%^e%^C248%^z%^C250%^e %^RESET%^%^C244%^of shifting %^RESET%^%^C241%^b%^C242%^e%^C243%^s%^C244%^h%^C245%^a%^C244%^d%^C243%^o%^C242%^w%^C241%^e%^C242%^d %^C243%^l%^C244%^a%^C245%^n%^C244%^d%^RESET%^%^C243%^s%^C242%^c%^C241%^a%^C242%^p%^C243%^e%^C244%^s and images plucked from the realm of %^C245%^n%^C244%^i%^C243%^g%^C241%^h%^C240%^t%^RESET%^%^C052%^m%^C088%^a%^C124%^r%^C160%^e%^C196%^s%^RESET%^%^C244%^. The g%^C246%^l%^C248%^o%^C241%^s%^C246%^s%^C244%^y %^C241%^black floor %^C244%^makes it seem as if you are walking across a %^C240%^void%^C244%^, though the occasional %^RESET%^%^C015%^f%^C255%^l%^C231%^a%^C230%^s%^C229%^h %^C228%^o%^C227%^f %^C226%^l%^C227%^i%^C228%^g%^C229%^h%^C230%^t %^RESET%^%^C244%^suggests that something lies below. Large %^RESET%^%^C015%^s%^C255%^c%^C231%^r%^C230%^i%^C231%^m%^C255%^s%^C015%^h%^C255%^a%^C231%^w %^C230%^p%^C231%^i%^C255%^l%^C015%^l%^C255%^a%^C231%^r%^C230%^s %^RESET%^%^C244%^support the arched %^C231%^ceiling%^RESET%^%^C244%^, also carved from ancient %^RESET%^%^C015%^d%^C255%^r%^C231%^a%^C230%^g%^C231%^o%^C255%^n %^C015%^b%^C255%^o%^C231%^n%^C230%^e %^RESET%^%^C244%^and lush with climbing %^RESET%^%^C046%^p%^C047%^h%^C048%^o%^C049%^s%^C050%^p%^C051%^h%^C087%^o%^C086%^r%^C085%^e%^C084%^s%^C083%^c%^C082%^e%^C119%^n%^C120%^t %^C121%^p%^C122%^l%^C123%^a%^C051%^n%^C050%^t%^C049%^s%^RESET%^%^C244%^. The lounge contains ample seating, the tables and chairs decorated with %^C118%^l%^C119%^u%^C120%^m%^C121%^i%^C122%^n%^C123%^o%^C153%^u%^C147%^s %^C141%^e%^C135%^n%^C129%^g%^C128%^r%^C127%^a%^C126%^v%^C125%^i%^C161%^n%^C162%^g%^C163%^s %^RESET%^%^C244%^that make them easy to find in the %^C242%^gloom %^C244%^as well as a large space cleared in the center for dancing and mingling. Along the western wall is a sunken area enclosed with fine %^C241%^wooden railings %^C244%^and filled with plush %^C055%^c%^C241%^u%^C055%^s%^C054%^h%^C241%^i%^C243%^o%^C055%^ns %^RESET%^%^C244%^and a %^C241%^s%^C245%^e%^C250%^r%^C183%^p%^RESET%^%^C250%^e%^C245%^n%^C241%^t%^C245%^i%^C250%^n%^C159%^e %^C250%^s%^C245%^t%^C241%^a%^C245%^t%^C250%^u%^C225%^e%^RESET%^%^C244%^. Dominating the northern wall is a spacious %^C241%^stage %^C244%^featuring a %^C241%^g%^C243%^r%^C245%^a%^C243%^n%^C241%^d p%^C243%^i%^C245%^a%^C243%^n%^C241%^o %^C244%^and a band sporting %^C255%^harlequin masks%^C244%^, while the eastern wall houses a %^C241%^bar %^C244%^with %^C198%^b%^C197%^a%^C199%^c%^C200%^k%^C201%^l%^C165%^i%^C164%^t %^RESET%^%^C241%^shelving %^RESET%^%^C244%^crowded with dozens of exotic %^C214%^a%^C220%^l%^C221%^c%^C226%^oh%^C221%^o%^C220%^l%^C214%^s %^RESET%^%^C244%^behind it, as well as the doorway to the %^C248%^kitchen%^C244%^ %^RESET%^%^C161%^h%^C162%^i%^C163%^g%^C164%^h%^C165%^l%^C201%^i%^C200%^g%^C199%^h%^C198%^t%^C197%^e%^C198%^d %^RESET%^%^C244%^by undulating %^RESET%^%^C161%^f%^C162%^a%^C163%^e%^C164%^r%^C165%^i%^C201%^e %^RESET%^%^C200%^f%^C199%^i%^C198%^r%^C197%^e%^RESET%^%^C244%^. A raised %^C241%^m%^C243%^a%^C245%^r%^C243%^b%^C241%^l%^C243%^e %^RESET%^%^C245%^d%^C243%^a%^C241%^i%^C243%^s %^RESET%^%^C244%^occupies the southern portion of the lounge, a %^C241%^long table %^C244%^set upon it as well as a pair of high-backed %^C241%^c%^C243%^h%^C230%^a%^C255%^i%^C243%^r%^C241%^s %^RESET%^%^C244%^positioned so they can observe any and all %^C088%^f%^C124%^e%^C196%^s%^C124%^t%^C088%^i%^C124%^v%^C196%^i%^C124%^t%^C088%^i%^C124%^e%^C196%^s%^RESET%^%^C244%^. Toward the east, an intricately %^C241%^c%^C243%^a%^C245%^r%^C243%^v%^C241%^e%^C243%^d %^C241%^a%^C243%^r%^C245%^c%^C243%^h%^C241%^w%^C243%^a%^C241%^y %^RESET%^%^C244%^leads into %^C240%^darkness%^C244%^.%^CRST%^\n");

   set_smell("default","%^RESET%^%^CRST%^%^C088%^The s%^C124%^a%^C160%^vo%^C124%^r%^C088%^y s%^C124%^c%^C160%^en%^C124%^t%^RESET%^%^C088%^s of delicious %^C094%^food %^RESET%^%^C088%^and potent %^C214%^l%^C220%^i%^C221%^q%^C226%^u%^C220%^o%^C214%^r %^RESET%^%^C088%^fill the air.%^CRST%^");
   set_listen("default","%^RESET%^%^CRST%^%^C202%^L%^C208%^%^a%^C214%^u%^C220%^g%^h%^C214%^t%^C208%^e%^C202%^r%^RESET%^%^C124%^ and m%^C160%^o%^C196%^a%^RESET%^%^C160%^n%^RESET%^%^C124%^s of p%^C160%^l%^C196%^e%^C197%^a%^C198%^s%^C197%^u%^C196%^r%^RESET%^%^C124%^e can be heard amidst the %^C051%^m%^C087%^u%^C123%^s%^C087%^i%^C051%^c%^RESET%^%^C124%^.%^CRST%^");

   set_items(([
      "menu" : "%^RESET%^%^CRST%^%^C244%^There are menus here that can be read.%^CRST%^",
      ({"walls","wall","frieze"}) : "%^RESET%^%^CRST%^%^C244%^The walls are composed of %^C240%^s%^C241%^m%^C242%^o%^C243%^k%^C245%^y %^C246%^b%^C245%^l%^C244%^a%^C243%^c%^C242%^k %^C241%^f%^C240%^r%^C241%^i%^C242%^e%^C243%^z%^RESET%^%^C244%^e, sculpted from %^C240%^shadowstuff %^C244%^that portrays %^C246%^s%^C247%^h%^C248%^i%^C249%^f%^C246%^t%^C248%^i%^C249%^n%^C250%^g %^RESET%^%^C244%^landscapes from great %^RESET%^%^C022%^f%^C028%^o%^C034%^r%^C040%^e%^C034%^s%^C028%^t%^RESET%^%^C022%^s %^C244%^to vast %^C024%^s%^C025%^e%^C026%^a%^C027%^s%^C033%^c%^C039%^a%^C038%^p%^C032%^e%^C031%^s%^RESET%^%^C244%^. Populating these varied vistas are numerous %^C124%^p%^C160%^a%^C196%^n%^C160%^i%^C124%^c%^RESET%^%^C244%^-stricken humanoids, fleeing and hiding from the %^RESET%^%^C088%^monstrous beasts %^C244%^and %^C051%^otherworldly specters %^RESET%^%^C244%^that hunt them. Ghastly %^C252%^w%^C251%^r%^C250%^a%^C249%^i%^C250%^t%^C251%^h%^C252%^s %^RESET%^%^C244%^and vicious %^C052%^w%^C088%^e%^C124%^r%^C160%^e%^C124%^b%^C088%^e%^C052%^a%^C088%^s%^C124%^t%^C160%^s %^RESET%^%^C244%^chase a group of terrified victims through the woods while %^C240%^tentacled nightmares %^C244%^rise from the sea elsewhere to crush a large %^C094%^ship%^RESET%^%^C244%^, its occupants diving into the sea only to be torn to pieces by beautiful %^C023%^m%^C030%^e%^C037%^r%^C044%^f%^C037%^o%^C030%^l%^C023%^k%^RESET%^%^C244%^. The %^C088%^b%^C124%^u%^C160%^r%^C196%^n%^C160%^i%^C124%^n%^C088%^g %^RESET%^%^C124%^red eyes %^C244%^of the frightening predators create a haunting %^C088%^c%^C124%^r%^C160%^i%^C196%^m%^C160%^s%^C124%^o%^C088%^n %^RESET%^%^C088%^g%^C124%^l%^C160%^o%^C088%^w %^RESET%^%^C244%^that serves to %^C124%^highlight %^RESET%^%^C244%^the details of the %^C240%^s%^C241%^h%^C242%^a%^C243%^d%^C245%^o%^C246%^w%^C247%^e%^C248%^d %^RESET%^%^C244%^images.%^CRST%^",
      "bar" : "%^RESET%^%^C244%^The %^C241%^shelves %^C244%^behind the %^C241%^bar %^C244%^are lined with exotic %^C214%^l%^C220%^i%^C221%^q%^C226%^u%^C221%^o%^C220%^r %^C214%^b%^C220%^o%^C221%^t%^C226%^t%^C221%^l%^C220%^e%^C214%^s %^RESET%^%^C244%^of all shapes, sizes, and colors. %^C198%^B%^C197%^a%^C199%^c%^C200%^k%^C201%^l%^C165%^i%^C164%^t %^RESET%^%^C244%^by the glow of %^C161%^f%^C162%^a%^C163%^e%^C164%^r%^C165%^i%^C201%^e %^C200%^f%^C199%^i%^C198%^r%^C197%^e %^RESET%^%^C244%^these bottles cast %^C241%^l%^C243%^i%^C245%^q%^C247%^u%^C241%^i%^C243%^d %^C245%^s%^C247%^h%^C241%^a%^C243%^d%^C245%^o%^C247%^w%^C241%^s %^RESET%^%^C244%^across the polished %^C241%^ebony bar top%^C244%^, creating the %^C039%^s%^C045%^u%^C051%^r%^C087%^r%^C081%^e%^C075%^a%^C069%^l %^RESET%^%^C244%^sense of being submerged beneath %^C030%^m%^C031%^u%^C032%^r%^C033%^k%^C032%^y %^C031%^w%^C030%^a%^C031%^t%^C032%^e%^C033%^r%^C032%^s%^RESET%^%^C244%^. %^C241%^Ebony stools %^C244%^with comfortable %^C241%^black leather %^C244%^cushions line the bar and along its base runs an %^C241%^iron footrest%^C244%^. Behind the bar there is a %^C248%^doorway%^C244%^, also bordered by %^%^C161%^m%^C162%^a%^C163%^g%^C164%^i%^C165%^c%^C201%^a%^C200%^l f%^C199%^i%^C198%^r%^C197%^e %^RESET%^%^C244%^and hung with strands of %^C088%^r%^C124%^u%^C160%^b%^C124%^y %^C088%^b%^C124%^e%^C160%^a%^C124%^d%^C088%^s%^RESET%^%^C244%^. Judging from the activity %^C045%^b%^C044%^u%^C050%^s%^C051%^t%^C045%^l%^C044%^i%^C050%^n%^C051%^g %^RESET%^%^C244%^within and the servers leaving with %^C058%^delicious %^RESET%^%^C244%^smelling food or returning with empty %^C255%^plates %^C244%^and %^C159%^glasses%^RESET%^%^C244%^, this is the kitchen.%^CRST%^",
      ({"dais","chairs" }) : "%^RESET%^%^C244%^A semi-circular %^C241%^dais %^C244%^dominates the southern portion of the room and from its heights, the entire lounge can be observed. A long %^C241%^ebony table %^C244%^with legs carved to resemble pillars of %^C241%^s%^C243%^w%^C245%^i%^C243%^r%^C241%^l%^C243%^i%^C245%^n%^C241%^g %^C243%^s%^C245%^h%^C243%^a%^C241%^d%^C243%^o%^C245%^w %^C244%^stands here with two massive chairs prominently featured. One is composed of %^C241%^ebony wood %^C244%^and the other the finest polished %^C015%^i%^C231%^v%^C230%^o%^C231%^r%^C015%^y%^RESET%^%^C244%^. Both are works of art carved to depict hundreds of serpents %^C241%^c%^C248%^o%^C255%^i%^C241%^l%^C230%^e%^C248%^d %^RESET%^%^C244%^about one another to form the high backs of the chairs. %^C087%^S%^C123%^o%^C159%^f%^C195%^t%^C159%^ %^C123%^h%^C087%^i%^C123%^s%^C159%^s%^C195%^i%^C159%^n%^C123%^g %^RESET%^%^C244%^can be heard from the nest of %^C241%^s%^C245%^e%^C255%^r%^C255%^p%^C241%^e%^C245%^n%^C255%^t%^C245%^s %^C244%^as they slither across each other as if alive. %^C231%^G%^C195%^l%^C231%^i%^C230%^t%^C194%^t%^C255%^e%^C231%^r%^C195%^i%^C195%^n%^C194%^g %^RESET%^%^C244%^gemstones have been used for their eyes, %^C046%^e%^C047%^m%^C048%^e%^C049%^r%^C050%^a%^C049%^l%^C048%^d%^C046%^s %^RESET%^%^C244%^for the %^C241%^ebony %^C244%^and %^C094%^a%^C172%^m%^C220%^b%^C172%^e%^C094%^r %^RESET%^%^C244%^for the %^C015%^i%^C255%^v%^C231%^o%^C255%^r%^C015%^y%^RESET%^%^C244%^, giving them a %^C052%^s%^C088%^i%^C124%^n%^C160%^i%^C196%^s%^C124%^t%^C088%^e%^C052%^r %^RESET%^%^C244%^air as the %^C024%^e%^C031%^n%^C038%^c%^C045%^h%^C038%^a%^C031%^n%^C024%^t%^C031%^e%^C038%^d %^RESET%^%^C244%^carvings %^C241%^w%^C243%^r%^C255%^i%^C241%^t%^C015%^h%^C241%^e %^RESET%^%^C244%^under your gaze. Plush %^C241%^black velvet cushions %^C244%^provide a bit of added comfort to the chairs. The remaining seating around the table is more mundane, but still well made and comfortable. Judging from its location at the head of the room and the opulence displayed there, this area is reserved for people of great prestige.%^CRST%^",
      ({"stage","band","piano" }) : "%^RESET%^%^C244%^Occupying the northern wall is a spacious, raised %^C241%^stage %^C244%^with thick, %^RESET%^%^C055%^violet velvet curtains %^C244%^serving as a backdrop. The sleek surface of the stage is composed of polished %^C241%^ebony planks %^C244%^and along its %^C161%^f%^C162%^a%^C163%^e%^C164%^r%^C165%^i%^C201%^e %^C200%^f%^C199%^i%^C198%^r%^C197%^e%^RESET%^%^C244%^-limned perimeter, a border depicting %^C052%^s%^C088%^u%^C124%^f%^C160%^f%^C124%^e%^C088%^r%^C052%^i%^C088%^n%^C124%^g %^RESET%^%^C244%^humanoids writhing within a nest of %^C241%^serpents %^C244%^has been carved. A beautiful %^C241%^g%^C243%^r%^C245%^a%^C243%^n%^C241%^d p%^C243%^i%^C245%^a%^C243%^n%^C241%^o %^C244%^rests upon the stage, its %^C015%^i%^C231%^v%^C230%^o%^C231%^r%^C015%^y k%^C231%^e%^C230%^y%^RESET%^%^C015%^s %^C085%^glowing %^RESET%^%^C244%^with a %^C050%^soft v%^C085%^e%^C122%^r%^C158%^d%^C050%^a%^C049%^n%^C050%^t l%^C122%^i%^C158%^g%^C121%^h%^C050%^t%^RESET%^%^C244%^. To the right of the piano, a %^C241%^s%^C244%^h%^C248%^a%^C252%^r%^C248%^p%^C244%^l%^C241%^y d%^C244%^r%^C248%^e%^C252%^ss%^C248%^e%^C241%^d band %^RESET%^%^C244%^plays music for the occupants of the lounge, each wearing a unique %^C255%^harlequin mask%^C244%^.%^CRST%^",
      ({"ceiling","pillars" }) : "%^RESET%^%^C230%^Made from the same material as the %^RESET%^%^C015%^pillars%^C230%^, the arched %^C015%^ceiling %^RESET%^%^C230%^is composed of pale %^RESET%^%^C015%^d%^C255%^r%^C231%^a%^C230%^g%^C231%^o%^RESET%^%^C015%^n %^C015%^b%^C255%^o%^C231%^n%^C230%^e %^RESET%^%^C015%^s%^C255%^c%^C231%^r%^C230%^i%^C231%^m%^C255%^s%^C015%^h%^C255%^a%^C231%^w%^RESET%^%^C230%^. It has been treated so that its color is a %^C015%^pr%^C231%^i%^C015%^st%^C225%^i%^C015%^n%^C195%^e %^RESET%^%^C015%^i%^C231%^v%^C230%^o%^C231%^r%^RESET%^%^C015%^y %^C230%^and there is no residual %^C225%^tissue %^C230%^but the natural texture remains, the bone like thick %^C015%^w%^C248%^e%^C230%^b%^C231%^b%^C250%^i%^C255%^n%^RESET%^%^C015%^g %^C230%^in some places and completely %^RESET%^%^C015%^solid %^C230%^in others. %^RESET%^%^C046%^L%^C047%^u%^C048%^m%^C049%^i%^C050%^n%^C051%^o%^C087%^u%^C086%^s %^C085%^t%^C084%^h%^C083%^o%^C082%^r%^C119%^n%^C120%^y %^C121%^v%^C122%^i%^C051%^n%^C050%^e%^C049%^s %^RESET%^%^C230%^with %^C049%^b%^C048%^r%^C050%^o%^C051%^a%^C049%^d l%^C050%^e%^C051%^a%^C049%^v%^C048%^e%^C049%^s %^RESET%^%^C230%^wind their way around the %^RESET%^%^C015%^pillars %^C230%^and branch across the %^RESET%^%^C015%^ceiling%^C230%^, casting them in an %^RESET%^%^C050%^e%^C085%^e%^C122%^r%^C158%^i%^C050%^e l%^C122%^i%^C158%^g%^C121%^h%^C050%^t%^C230%^.%^CRST%^",
      ({"floor","glass" }) : "%^RESET%^%^C243%^The %^C045%^c%^C051%^o%^C087%^o%^C045%^l%^RESET%^%^C243%^, seemingly %^RESET%^%^C241%^black%^C243%^, glass floor has a disturbingly %^C241%^endless depth %^C243%^to its %^C241%^darkness%^C243%^, as if just beneath its surface is the Abyss itself. The more closely one looks, the more apparent it becomes that the floor is actually %^C159%^cl%^C195%^e%^C015%^a%^C159%^r g%^C195%^l%^C159%^a%^C015%^s%^C159%^s%^RESET%^%^C243%^, and the longer, the more obvious it is that the %^C241%^darkness %^C243%^beneath is a thick %^C241%^black liquid%^RESET%^%^C243%^. %^RESET%^%^C015%^G%^C250%^h%^C159%^o%^C195%^s%^C250%^t%^RESET%^%^C015%^ly l%^C230%^i%^C159%^g%^C195%^h%^RESET%^%^C015%^ts f%^C250%^l%^C243%^i%^C015%^c%^C250%^k%^C243%^e%^RESET%^%^C015%^r %^C243%^from the depths revealing the rotted features of %^RESET%^%^C015%^sightless %^C109%^c%^C252%^o%^C108%^r%^C109%^ps%^C252%^e%^C109%^s %^RESET%^%^C243%^adrift in the %^C241%^dark%^C243%^. Small %^C027%^b%^C033%^i%^C039%^o%^C045%^l%^C051%^u%^C045%^m%^C039%^i%^C033%^n%^C027%^e%^C033%^s%^C039%^c%^C045%^e%^C051%^n%^C045%^t %^C039%^f%^C033%^i%^C027%^%^C033%^s%^C039%^h %^RESET%^%^C243%^and other %^RESET%^%^C160%^g%^C196%^l%^C197%^o%^C198%^w%^C199%^i%^C200%^n%^C201%^g%^RESET%^%^C243%^, %^C231%^j%^C225%^e%^C213%^l%^C231%^l%^C225%^y%^C219%^f%^C231%^i%^C225%^s%^C219%^h %^RESET%^%^C243%^feast upon their %^C109%^p%^C108%^u%^C107%^t%^C113%^r%^C114%^i%^C115%^d %^C114%^f%^C113%^l%^C107%^e%^C109%^s%^C108%^h%^RESET%^%^C243%^.%^CRST%^",
      "pit" : "%^RESET%^%^C244%^This area of the lounge is sunken by a few steps, creating a sizeable %^C241%^pit %^C244%^surrounded by a finely carved %^C241%^ebony railing%^C244%^. Thick, %^C054%^l%^C055%^u%^C056%^x%^C093%^u%^C092%^r%^C091%^i%^C090%^o%^C089%^u%^C053%^s r%^C054%^u%^C055%^g%^C056%^s %^RESET%^%^C244%^lie on the floor, which is %^C241%^w%^C243%^o%^C245%^o%^C241%^d %^C244%^rather than %^C159%^g%^C195%^l%^C195%^a%^C015%^s%^C159%^s%^RESET%^%^C244%^. %^RESET%^%^C015%^D%^C102%^o%^RESET%^%^C255%^w%^RESET%^%^C015%^n%^RESET%^%^C244%^-filled %^C241%^v%^C243%^e%^C245%^l%^C241%^v%^C243%^e%^C245%^t %^RESET%^%^C244%^pillows in %^C241%^black %^C244%^and %^C055%^violet%^RESET%^%^C244%^ have been strewn about. At the center of the sunken circle is an %^C015%^i%^C231%^v%^C230%^o%^C231%^r%^RESET%^%^C015%^y p%^C231%^e%^C230%^d%^C231%^e%^C015%^st%^C231%^a%^C015%^l %^RESET%^%^C244%^with an intricately carved %^C241%^s%^C245%^e%^C250%^r%^C183%^p%^RESET%^%^C250%^e%^C245%^n%^C241%^t%^C245%^i%^C250%^n%^C159%^e %^C250%^s%^C245%^t%^C241%^a%^C245%^t%^C250%^u%^C225%^e %^RESET%^%^C244%^resting upon it.%^CRST%^",
      "statue" : "%^RESET%^%^C244%^Resting upon a beautifully carved %^C015%^i%^C231%^v%^C230%^o%^C231%^r%^RESET%^%^C015%^y p%^C231%^e%^C230%^d%^C231%^e%^C015%^st%^C231%^a%^C015%^l %^RESET%^%^C244%^is a strikingly life-like statue of a coiled, %^C241%^black serpent %^C244%^with %^C129%^a%^C135%^m%^C141%^e%^C099%^t%^C093%^h%^C092%^y%^C091%^s%^C090%^t %^C089%^e%^C053%^y%^C054%^e%^C055%^s%^RESET%^%^C244%^. Its %^C241%^g%^C243%^l%^C245%^o%^C243%^s%^C241%^sy black scales %^C244%^have an %^C231%^o%^C195%^p%^C225%^a%^C159%^l%^C231%^e%^C230%^s%^C194%^c%^C189%^e%^C158%^n%^C231%^t s%^C230%^h%^C195%^e%^C189%^e%^C231%^n %^RESET%^%^C244%^and looking into their depths one could get lost in the %^C045%^c%^C051%^o%^C087%^s%^C159%^m%^C051%^i%^C045%^c s%^C051%^p%^C087%^l%^C123%^a%^C051%^s%^C045%^h %^RESET%^%^C244%^of %^C189%^c%^C225%^o%^C230%^l%^C194%^o%^C231%^r%^C195%^s %^C225%^s%^C189%^w%^C231%^i%^C230%^r%^C158%^l%^C159%^i%^C195%^n%^C153%^g %^RESET%^%^C244%^within the %^C241%^void%^C244%^. Reared back as if about to strike, the serpent's open mouth is equipped with two %^C088%^w%^C124%^i%^C196%^c%^C124%^k%^C088%^e%^C124%^d%^C088%^l%^C124%^y %^RESET%^%^C015%^s%^C255%^h%^C230%^a%^C255%^r%^C015%^p f%^C255%^a%^C230%^n%^C255%^g%^RESET%^%^C015%^s %^C244%^that %^C231%^g%^C230%^l%^C189%^e%^C195%^a%^C231%^m %^RESET%^%^C244%^in the %^C241%^d%^C243%^i%^C245%^m %^C248%^l%^C241%^i%^C243%^g%^C245%^h%^C248%^t%^C241%^i%^C243%^n%^C245%^g%^C244%^.%^CRST%^"
   ]));
   set_exits(([
      "east" : ROOMS"west_wing"
   ]));
   set_property("teleport proof", TPWARD_LEGENDARY);
   set_property("scry proof", SCRYWARD_LEGENDARY);
}

void reset() {
    ::reset();	
    //if(!present("nethess")) find_object_or_load("/realms/faebala/aunuit/staff/nethess")->move(TO);
    if(!present("nethess")) find_object_or_load("/d/player_houses/aunuit/staff/nethess")->move(TO);
    // Okay, so there's a bit to unpack that had to be changed here. In the first part with present, it was looking for anything with "enkahut" as an ID. We have to change that to nethess (or any of her other ids) otherwise it'll never find what it's looking for and spawn an infinite number of enkahut.c files. I've changed the path to the enkahut.c file in your realms folder, just remember to change it back before you dsync. You also don't need to put the ".c" at the end of the file reference, it always assumes it.
    
   switch(random(5)){
        case 0 : 
            tell_room(TO,"%^RESET%^%^CRST%^%^C110%^A giant %^RESET%^%^C059%^g%^C102%^r%^C251%^a%^C059%^y t%^C102%^e%^C251%^n%^C102%^t%^C059%^a%^C102%^c%^C251%^l%^C102%^e %^C110%^undulates in the %^C241%^darkness %^RESET%^%^C110%^below, its %^C188%^pale suckers %^C110%^sticking to the underside of the floor before it disappears.%^CRST%^");
            break;
        case 1 : 
            tell_room(TO,"%^RESET%^%^CRST%^%^C027%^A school of %^RESET%^%^C033%^b%^C039%^i%^C045%^o%^C051%^l%^C045%^u%^C039%^m%^C033%^i%^C039%^n%^C045%^e%^C051%^s%^C045%^c%^C039%^e%^C033%^n%^C039%^t %^C045%^f%^C051%^i%^C045%^s%^C039%^h %^RESET%^%^C027%^swims just beneath the %^RESET%^%^C159%^g%^C195%^l%^C159%^a%^C015%^s%^C159%^s %^C195%^f%^RESET%^%^C015%^l%^C195%^o%^C159%^o%^C015%^r%^RESET%^%^C027%^.%^CRST%^");
            break;
	case 2:
 	    tell_room(TO,"%^RESET%^%^CRST%^%^C244%^A %^C241%^m%^C243%^a%^C247%^r%^C241%^i%^C243%^o%^C245%^n%^C241%^e%^C243%^t%^C247%^t%^C241%^e %^RESET%^%^C244%^moves through the room tidying up and wiping empty tables %^C255%^clean %^C244%^with a %^RESET%^%^C250%^damp rag%^RESET%^%^C244%^.%^CRST%^");
            break;
	case 3:
 	    tell_room(TO,"%^RESET%^%^CRST%^%^C241%^So%^C243%^m%^C245%^et%^C247%^h%^C249%^in%^C241%^g %^C243%^ma%^C245%^ss%^C247%^i%^C249%^ve %^C241%^c%^C243%^a%^C245%^us%^C247%^e%^C249%^s %^C241%^th%^C243%^e %^C240%^darkness %^RESET%^%^C245%^be%^C247%^l%^C249%^o%^C241%^w t%^C243%^h%^C245%^e f%^C247%^l%^C249%^oo%^C241%^r %^C243%^to %^C245%^s%^C247%^ti%^C249%^r, %^RESET%^%^C241%^b%^C243%^um%^C245%^p%^C247%^in%^C249%^g %^C241%^t%^C243%^he %^C245%^g%^C247%^l%^C249%^as%^RESET%^%^C241%^s h%^C243%^a%^C245%^rd %^C247%^e%^C249%^n%^C241%^o%^C243%^ug%^C245%^h %^C247%^t%^C241%^ha%^C243%^t %^C245%^i%^C247%^t s%^C249%^h%^C241%^u%^RESET%^%^C243%^dd%^C245%^e%^C247%^r%^C249%^s%^C244%^.%^CRST%^");
            break;
        default : 
            tell_room(TO,"%^RESET%^%^CRST%^%^C244%^An %^C229%^e%^C228%^e%^C227%^r%^C228%^i%^C229%^e %^C230%^p%^C229%^a%^C228%^l%^C227%^e %^C228%^y%^C229%^e%^C230%^l%^C229%^l%^C228%^o%^C227%^w %^C228%^l%^C229%^i%^C230%^g%^C229%^h%^C228%^t %^C244%^passes through the %^RESET%^%^C240%^gloom %^C244%^below the %^RESET%^%^C159%^g%^C195%^l%^C159%^a%^C015%^s%^C159%^s %^C195%^f%^RESET%^%^C015%^l%^C195%^o%^C159%^o%^C015%^r%^RESET%^%^C244%^.%^CRST%^");
            break;
    }
}    
   

int read(string str) {
    object ob;
    int i;

  if(str!="menu")
    return 0;
    write("%^RESET%^%^C240%^The following items are being served.");
   
   
    write("  %^RESET%^%^C093%^*%^C099%^*%^C105%^*%^C111%^*%^CRST%^"
"%^RESET%^%^C117%^*%^RESET%^%^C123%^*%^RESET%^%^C159%^*%^RESET%^%^C153%^*%^RESET%^%^C147%^*%^CRST%^"
"%^RESET%^%^C135%^*%^RESET%^%^C129%^*%^RESET%^%^C135%^*%^RESET%^%^C141%^*%^RESET%^%^C147%^*%^CRST%^"
"%^RESET%^%^C153%^*%^RESET%^%^C159%^*%^RESET%^%^C123%^*%^RESET%^%^C117%^*%^RESET%^%^C111%^*%^CRST%^"
"%^RESET%^%^C105%^*%^RESET%^%^C099%^*%^RESET%^%^C093%^*%^RESET%^%^C099%^*%^RESET%^%^C105%^*%^CRST%^"
"%^RESET%^%^C111%^*%^RESET%^%^C117%^*%^RESET%^%^C123%^*%^RESET%^%^C159%^*%^RESET%^%^C153%^*%^CRST%^\n");
   write("%^RESET%^%^C093%^           Appetizers%^CRST%^\n");
    write("\t%^RESET%^%^C240%^Food for %^RESET%^%^C039%^T%^C045%^h%^C051%^o%^C087%^u%^C051%^g%^C045%^h%^C039%^t%^CRST%^");
    write("\t%^RESET%^%^C240%^Bounty of the %^RESET%^%^C024%^D%^C031%^e%^C038%^e%^C024%^p%^CRST%^");
    write("\t%^RESET%^%^C240%^Finger %^RESET%^%^C048%^L%^C047%^i%^C046%^c%^C047%^h%^C048%^e%^C049%^n %^RESET%^%^C240%^Good%^CRST%^\n");
    write("  %^RESET%^%^C093%^*%^C099%^*%^C105%^*%^C111%^*%^CRST%^"
"%^RESET%^%^C117%^*%^RESET%^%^C123%^*%^RESET%^%^C159%^*%^RESET%^%^C153%^*%^RESET%^%^C147%^*%^CRST%^"
"%^RESET%^%^C135%^*%^RESET%^%^C129%^*%^RESET%^%^C135%^*%^RESET%^%^C141%^*%^RESET%^%^C147%^*%^CRST%^"
"%^RESET%^%^C153%^*%^RESET%^%^C159%^*%^RESET%^%^C123%^*%^RESET%^%^C117%^*%^RESET%^%^C111%^*%^CRST%^"
"%^RESET%^%^C105%^*%^RESET%^%^C099%^*%^RESET%^%^C093%^*%^RESET%^%^C099%^*%^RESET%^%^C105%^*%^CRST%^"
"%^RESET%^%^C111%^*%^RESET%^%^C117%^*%^RESET%^%^C123%^*%^RESET%^%^C159%^*%^RESET%^%^C153%^*%^CRST%^\n");
write("%^RESET%^%^C099%^             Entrees%^CRST%^\n");
    write("\t%^RESET%^%^C240%^Wrong or %^RESET%^C088%^R%^C124%^o%^C160%^t%^C124%^h%^C088%^e%^CRST%^");
    write("\t%^RESET%^%^C240%^Rolling in the %^BLUE%^D%^CYAN%^e%^RESET%^%^CYAN%^e%^BOLD%^%^BLUE%^p%^RESET%^");
    write("\t%^RESET%^%^C021%^S%^C027%^p%^C033%^i%^C039%^d%^C045%^e%^C051%^r%^C045%^k%^C039%^i%^C033%^s%^C027%^s%^C021%^e%^C027%^r %^RESET%^%^C240%^Surprise%^CRST%^\n");
    write("  %^RESET%^%^C093%^*%^C099%^*%^C105%^*%^C111%^*%^CRST%^"
"%^RESET%^%^C117%^*%^RESET%^%^C123%^*%^RESET%^%^C159%^*%^RESET%^%^C153%^*%^RESET%^%^C147%^*%^CRST%^"
"%^RESET%^%^C135%^*%^RESET%^%^C129%^*%^RESET%^%^C135%^*%^RESET%^%^C141%^*%^RESET%^%^C147%^*%^CRST%^"
"%^RESET%^%^C153%^*%^RESET%^%^C159%^*%^RESET%^%^C123%^*%^RESET%^%^C117%^*%^RESET%^%^C111%^*%^CRST%^"
"%^RESET%^%^C105%^*%^RESET%^%^C099%^*%^RESET%^%^C093%^*%^RESET%^%^C099%^*%^RESET%^%^C105%^*%^CRST%^"
"%^RESET%^%^C111%^*%^RESET%^%^C117%^*%^RESET%^%^C123%^*%^RESET%^%^C159%^*%^RESET%^%^C153%^*%^CRST%^\n");
   write("%^RESET%^%^C105%^            Desserts%^CRST%^\n");
   write("\t%^RESET%^%^C052%^B%^C088%^l%^C124%^oo%^C088%^d%^C052%^y %^RESET%^%^C240%^Good Pudding%^CRST%^");
    write("\t%^RESET%^%^C094%^Cr%^C136%^unc%^C094%^hy %^RESET%^%^C240%^Cave Delight%^CRST%^ ");
    write("\t%^RESET%^%^C240%^Eye of the %^RESET%^%^C129%^B%^C135%^e%^C141%^h%^C147%^ol%^C141%^d%^C135%^e%^C129%^r%^CRST%^\n");
    write("  %^RESET%^%^C093%^*%^C099%^*%^C105%^*%^C111%^*%^CRST%^"
"%^RESET%^%^C117%^*%^RESET%^%^C123%^*%^RESET%^%^C159%^*%^RESET%^%^C153%^*%^RESET%^%^C147%^*%^CRST%^"
"%^RESET%^%^C135%^*%^RESET%^%^C129%^*%^RESET%^%^C135%^*%^RESET%^%^C141%^*%^RESET%^%^C147%^*%^CRST%^"
"%^RESET%^%^C153%^*%^RESET%^%^C159%^*%^RESET%^%^C123%^*%^RESET%^%^C117%^*%^RESET%^%^C111%^*%^CRST%^"
"%^RESET%^%^C105%^*%^RESET%^%^C099%^*%^RESET%^%^C093%^*%^RESET%^%^C099%^*%^RESET%^%^C105%^*%^CRST%^"
"%^RESET%^%^C111%^*%^RESET%^%^C117%^*%^RESET%^%^C123%^*%^RESET%^%^C159%^*%^RESET%^%^C153%^*%^CRST%^\n");
   write("%^RESET%^%^C111%^             Drinks%^CRST%^\n");
    write("\t%^RESET%^%^C240%^Simple and %^C051%^C%^C087%^l%^C123%^e%^C087%^a%^C051%^n%^CRST%^");
   write("\t%^RESET%^%^C240%^Bazi %^RESET%^%^C094%^Tea%^CRST%^");
    write("\t%^RESET%^%^C240%^Black W%^RESET%^%^C230%^i%^C240%^ne%^CRST%^");
    write("\t%^RESET%^%^C240%^Mother's %^RESET%^%^C230%^M%^C231%^i%^C015%^l%^RESET%^%^C230%^k%^CRST%^");
    write("\t%^RESET%^%^C240%^Deep %^C242%^A%^C243%^b%^C244%^y%^C245%^s%^C244%^s%^C243%^a%^C242%^l %^RESET%^%^C240%^Ale%^CRST%^");
    write("\t%^RESET%^%^C240%^Drow %^RESET%^%^C051%^A%^C087%^z%^C123%^u%^C159%^r%^C195%^e %^RESET%^%^C240%^Wine%^CRST%^");
    write("\t%^RESET%^%^C240%^Spider%^C088%^b%^C124%^l%^C160%^oo%^C124%^%^C088%^d%^CRST%^\n");
    write("  %^RESET%^%^C093%^*%^C099%^*%^C105%^*%^C111%^*%^CRST%^"
"%^RESET%^%^C117%^*%^RESET%^%^C123%^*%^RESET%^%^C159%^*%^RESET%^%^C153%^*%^RESET%^%^C147%^*%^CRST%^"
"%^RESET%^%^C135%^*%^RESET%^%^C129%^*%^RESET%^%^C135%^*%^RESET%^%^C141%^*%^RESET%^%^C147%^*%^CRST%^"
"%^RESET%^%^C153%^*%^RESET%^%^C159%^*%^RESET%^%^C123%^*%^RESET%^%^C117%^*%^RESET%^%^C111%^*%^CRST%^"
"%^RESET%^%^C105%^*%^RESET%^%^C099%^*%^RESET%^%^C093%^*%^RESET%^%^C099%^*%^RESET%^%^C105%^*%^CRST%^"
"%^RESET%^%^C111%^*%^RESET%^%^C117%^*%^RESET%^%^C123%^*%^RESET%^%^C159%^*%^RESET%^%^C153%^*%^CRST%^\n");
   
    write("<order dish_name> will get you the food or drink.");
    return 1;
}

