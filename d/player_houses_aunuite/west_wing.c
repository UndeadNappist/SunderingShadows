//Ryzan and Aunuit's House
//Coded by ~Circe~ 7/24/13

#include <std.h>
#include <player_housing.h>
#include <daemons.h>
#include "aunuit.h"

inherit VAULT;

void create(){
   ::create();
   set_name("West wing");
   set_travel(PAVED_ROAD);
   set_terrain(BUILT_TUNNEL);
   set_light(1);
   set_indoors(1);
   set_short("%^BOLD%^%^BLACK%^West wing%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^The rich%^RESET%^%^ORANGE%^ darkwood "
      "panels %^BOLD%^%^BLACK%^that make up the walls here reach up "
      "to an %^WHITE%^arched ceiling %^BLACK%^braced in dragon bone "
      "%^WHITE%^sc%^RESET%^r%^BOLD%^%^ORANGE%^i%^RESET%^m%^BOLD%^%^WHITE%^"
      "sh%^RESET%^a%^BOLD%^%^WHITE%^w%^BLACK%^. Both to the north and "
      "to the south a set of stairs leads to a landing that houses a "
      "door to a %^RESET%^%^MAGENTA%^guest room%^BOLD%^%^BLACK%^. Long "
      "%^RESET%^%^RED%^tapestries %^BOLD%^%^BLACK%^hang from the upper "
      "portions of the walls bearing stylized symbols. Tall %^WHITE%^vases "
      "%^BLACK%^are placed strategically along the edges of the main walkway, "
      "their large %^WHITE%^lum%^MAGENTA%^i%^WHITE%^n%^RESET%^o%^BOLD%^%^ORANGE%^u"
      "%^WHITE%^s %^MAGENTA%^f%^RESET%^%^MAGENTA%^l%^BOLD%^%^ORANGE%^o%^RESET%^"
      "%^MAGENTA%^r%^BOLD%^%^MAGENTA%^a %^BLACK%^providing the only %^WHITE%^light "
      "%^BLACK%^in the passage. The gl%^WHITE%^o%^BLACK%^ssy black marble of the "
      "floor stretches out like a pool of %^RESET%^%^BLUE%^darkness %^BOLD%^"
      "%^BLACK%^under foot. At the west end of the hall a large archway leads "
      "to what appears to be a massive dining area. To the east another leads "
      "to the common room of the palace.%^RESET%^\n");
   set_listen("default","%^BOLD%^%^BLACK%^Any sounds such as footsteps on the marble "
      "or even a soft cough are muted by the wood paneling on the walls.%^RESET%^");
   set_smell("default","%^RESET%^%^CYAN%^The heady scent of the beautiful "
      "phosphorescent flowers fills the hallway.%^RESET%^");
   set_items(([
      "ceiling" : "%^BOLD%^%^WHITE%^Made from the same material as the pillars, "
         "the arched ceiling is composed of pale dr%^RESET%^a%^BOLD%^%^WHITE%^"
         "gon bone scr%^RESET%^i%^BOLD%^%^WHITE%^msh%^ORANGE%^a%^WHITE%^w. "
         "It has been treated so that its color is a pristine i%^RESET%^v%^BOLD%^"
         "%^ORANGE%^o%^RESET%^r%^BOLD%^%^WHITE%^y and there is no residual "
         "%^MAGENTA%^tissue %^WHITE%^but the natural texture remains, the bone "
         "like thick w%^BLACK%^e%^WHITE%^bb%^RESET%^i%^BOLD%^%^WHITE%^ng in some "
         "places and completely s%^ORANGE%^o%^WHITE%^lid in others.%^RESET%^",
      ({"walls","wall","panels","paneling"}) : "%^BOLD%^%^BLACK%^The walls are "
         "lined with rich %^RESET%^%^ORANGE%^darkwood panels %^BOLD%^%^BLACK%^"
         "that insulate the room, keeping it at a comfortable temperature and "
         "reducing reverberation.%^RESET%^",
      ({"vases","vase","flora","flowers"}) : "%^BOLD%^%^BLACK%^Standing about "
         "three feet in height, these delicate %^WHITE%^white porcelain %^BLACK%^"
         "vases hold beautiful flowers. The petals of the flowers display a "
         "brilliant array of shapes and %^RESET%^%^RED%^h%^ORANGE%^u%^GREEN%^e"
         "%^BOLD%^%^BLUE%^s%^BLACK%^, from a star-shaped, %^RESET%^%^MAGENTA%^deep "
         "purple fl%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^wer %^BOLD%^%^BLACK%^with "
         "gl%^WHITE%^o%^BLACK%^wing %^WHITE%^white flecks %^BLACK%^to a %^ORANGE%^"
         "yell%^RESET%^%^ORANGE%^o%^BOLD%^%^ORANGE%^w %^BLACK%^bell-shaped %^RESET%^"
         "%^ORANGE%^bulb %^BOLD%^%^BLACK%^with %^RESET%^%^ORANGE%^t%^BOLD%^%^ORANGE%^i"
         "%^BLACK%^g%^RESET%^%^ORANGE%^e%^BOLD%^%^ORANGE%^r%^BLACK%^-s%^RESET%^"
         "%^ORANGE%^t%^BOLD%^%^ORANGE%^r%^BLACK%^i%^RESET%^%^ORANGE%^p%^BOLD%^"
         "%^ORANGE%^e%^BLACK%^s. All are %^MAGENTA%^exotic%^BLACK%^, gorgeous "
         "and %^WHITE%^luminescent%^BLACK%^.%^RESET%^",
      "floor" : "%^BOLD%^%^BLACK%^The floor is black marble buffed to a m%^WHITE%^"
         "i%^RESET%^r%^BOLD%^%^BLACK%^r%^WHITE%^o%^BLACK%^r-like %^WHITE%^sheen%^BLACK%^.%^RESET%^",
      ({"tapestries","tapestry"}) : "%^RESET%^%^RED%^At the center of the hall, "
         "two %^BOLD%^%^RED%^tapestries %^RESET%^%^RED%^hang against the walls across "
         "from one another. Both bear symbols set against a field of cr%^BOLD%^"
         "%^RED%^i%^RESET%^%^RED%^ms%^BOLD%^%^RED%^o%^RESET%^%^RED%^n. One depicts "
         "a %^BOLD%^%^BLACK%^black dragon %^RESET%^%^RED%^rising from a mass of "
         "writhing %^BOLD%^%^BLACK%^sh%^RESET%^a%^BOLD%^%^BLACK%^d%^RESET%^o%^BOLD%^"
         "%^BLACK%^w %^RESET%^%^RED%^and the other a simple but elegant %^BOLD%^"
         "%^BLACK%^black mask%^RESET%^%^RED%^.%^RESET%^"
   ]));
   set_exits(([
      "west" : ROOMS"dining_hall",
      "north" : ROOMS"guest_room_1",
      "south" : ROOMS"guest_room_2",
      "east" : ROOMS"maw"
   ]));
   set_door("ebony door","/d/player_houses/aunuit/guest_room_1","north",0);
   set_door_description("ebony door","%^CRST%^%^RESET%^%^C244%^This ominous %^C240%^ebony door %^C244%^bears intricate c%^C246%^a%^C248%^r%^C250%^v%^C248%^i%^C246%^n%^C244%^g%^RESET%^%^C246%^s of a %^RESET%^%^C231%^v%^C189%^a%^C231%^s%^C195%^t %^C231%^w%^C230%^e%^RESET%^%^C231%^b%^C244%^, populated by hundreds of tiny %^C051%^a%^C087%^z%^C123%^u%^C159%^r%^C123%^e%^RESET%^%^C244%^-%^C051%^g%^C087%^e%^C123%^m%^C159%^s%^C123%^t%^C087%^o%^C051%^n%^C087%^e %^C123%^s%^C159%^p%^C195%^i%^C159%^d%^C123%^e%^C087%^r%^C051%^s%^RESET%^%^C244%^. At the apex of the %^C231%^w%^C189%^e%^C231%^b%^C159%^b%^C231%^i%^C230%^n%^C231%^g%^RESET%^%^C244%^, a massive %^C240%^spider %^C244%^sits, its eight %^RESET%^%^C088%^r%^C124%^u%^C160%^b%^C088%^y e%^RESET%^%^C124%^y%^C160%^e%^C088%^s %^RESET%^%^C244%^staring down at you as it devours a tiny humanoid figure. The door has a small, spider-shaped %^C240%^iron knob%^RESET%^%^C244%^.%^CRST%^");
   set_door("ivory door","/d/player_houses/aunuit/guest_room_2","south",0);
   set_door_description("ivory door","%^CRST%^%^RESET%^%^C144%^This unsettling %^C015%^i%^C231%^v%^C230%^o%^C231%^r%^RESET%^%^C015%^y d%^C231%^o%^C230%^o%^RESET%^%^C015%^r %^C144%^bears life-like carvings of %^C231%^d%^C255%^o%^C255%^l%^C231%^l%^RESET%^%^C144%^-like children, playing around a large %^C241%^manor%^RESET%^%^C144%^. Where their eyes should be instead are empty %^C240%^black holes %^RESET%^%^C144%^and their lips are curled into impossibly wide %^C088%^r%^C124%^i%^C160%^c%^C124%^t%^C088%^u%^C124%^s %^RESET%^%^C160%^g%^C124%^r%^C160%^i%^C124%^n%^C088%^s%^RESET%^%^C144%^. A small, %^C015%^c%^C255%^r%^C250%^a%^C244%^c%^C250%^k%^C255%^e%^C015%^d p%^RESET%^%^C255%^o%^C250%^r%^C244%^c%^C250%^e%^C255%^l%^RESET%^%^C015%^a%^C255%^i%^C250%^n %^RESET%^%^C244%^d%^C250%^o%^C255%^l%^C015%^l %^C255%^h%^C250%^e%^C244%^a%^C250%^d %^RESET%^%^C144%^serves as the knob for this disturbing door.%^CRST%^");
   set_property("teleport proof", TPWARD_LEGENDARY);
   set_property("scry proof", SCRYWARD_LEGENDARY);
}