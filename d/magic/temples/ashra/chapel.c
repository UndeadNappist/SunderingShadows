/*
  Chapel of the Primordial Darkness
  
  Temple of Ashra
  Descriptions by Balur/Faceless
  
  -- Tlaloc --
*/

#include <std.h>

inherit "/std/templemisc";

void create()
{
    ::create();
    set_property("indoors",1); 
    set_property("light",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("Chapel of the Primordial Dark"); 
    set_short("%^BOLD%^%^BLACK%^Chapel of the %^RESET%^%^MAGENTA%^Primordial Dark");
    set_long("%^BOLD%^%^BLACK%^Awash in %^RESET%^%^MAGENTA%^violet hues %^BOLD%^%^BLACK%^that barely manage to %^MAGENTA%^illuminate %^BLACK%^its vastness, this magnificent chapel seems as if immersed in a sea of ebbing and flowing darkness. Great columns of black marble circle this room, vanishing into the murk overhead. The floor descends into the deeper dark in flowing waves, each level adorned with %^RESET%^%^MAGENTA%^plush pillows %^BOLD%^%^BLACK%^and %^RESET%^%^MAGENTA%^cushions %^BOLD%^%^BLACK%^before finally reaching the central landing at the lowest point in the Chapel. A gently sloping path of %^RESET%^%^MAGENTA%^deep violet carpet %^BOLD%^%^BLACK%^provides the only passage from the door to the lower landing and grants easy access to each level of the sitting area which was obviously designed with hedonistic comfort in mind. %^MAGENTA%^Purple marble %^BLACK%^rings the main floor of the room drawing attention to the jagged chunk of unworked %^RESET%^o%^BOLD%^%^BLACK%^bs%^WHITE%^i%^BLACK%^d%^RESET%^i%^BOLD%^%^BLACK%^an that serves as the altar resting at its center. Before the altar is a podium with a dark leatherbound tome laying open upon it to allow the faithful to look upon the will of %^RESET%^%^MAGENTA%^A%^BOLD%^%^BLACK%^s%^RESET%^%^MAGENTA%^h%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^. A %^RESET%^%^MAGENTA%^gargantuan statue %^BOLD%^%^BLACK%^depicting the %^RESET%^%^MAGENTA%^P%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^mordi%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^l in all her glory dominates the northern wall, looming over four smaller st%^WHITE%^a%^BLACK%^tu%^WHITE%^e%^BLACK%^s of her %^RESET%^subordinate deities%^BOLD%^%^BLACK%^. Hidden between two columns on the east wall is a small %^WHITE%^silver archway%^BLACK%^. Against the west wall is a long desk occupied by several darkly garbed acolytes. Behind the desk, a dark plaque etched with flowing %^WHITE%^silver script %^BLACK%^describes the services that can be provided here%^RESET%^");
    set_smell("default","%^MAGENTA%^The heady, sweet aroma of an exotic incense is in the air.%^RESET%^");
    set_listen("default","%^MAGENTA%^You hear the whispers of the acolytes and the faithful all around you.%^RESET%^");
    set_items(([
        ({"columns","column"}) : "%^BOLD%^%^BLACK%^Black marble shot through v%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^ins of %^RESET%^%^MAGENTA%^violet%^BOLD%^%^BLACK%^, these thick columns ascend into the waiting darkness overhead.%^RESET%^",
        ({"gargantuan statue","ashra","statue 1"}) : "%^BOLD%^%^BLACK%^Rising from a roiling inferno of black flame, this %^RESET%^%^MAGENTA%^primordial e%^BOLD%^%^BLACK%^ff%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^g%^RESET%^%^MAGENTA%^y %^BOLD%^%^BLACK%^at once %^RED%^terrifies %^BLACK%^with its %^RED%^monstrous %^BLACK%^nature and %^RESET%^%^MAGENTA%^attracts %^BOLD%^%^BLACK%^with its %^MAGENTA%^o%^RESET%^%^MAGENTA%^th%^BOLD%^e%^RESET%^%^MAGENTA%^rworl%^BOLD%^d%^RESET%^%^MAGENTA%^ly %^BOLD%^a%^RESET%^%^MAGENTA%^ll%^BOLD%^u%^RESET%^%^MAGENTA%^re%^BOLD%^%^BLACK%^. The coils of Her s%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^p%^BOLD%^%^BLACK%^ent%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^ne body weave through the sculpted %^RESET%^%^MAGENTA%^b%^BOLD%^a%^RESET%^%^MAGENTA%^l%^BOLD%^%^BLACK%^e %^RESET%^%^MAGENTA%^f%^BOLD%^i%^RESET%^%^MAGENTA%^r%^BOLD%^%^BLACK%^e, their gleaming midnight scales taking a %^RESET%^%^MAGENTA%^p%^BOLD%^u%^RESET%^%^MAGENTA%^r%^BOLD%^%^BLACK%^p%^RESET%^%^MAGENTA%^l%^BOLD%^i%^RESET%^%^MAGENTA%^s%^BOLD%^%^BLACK%^h %^RESET%^%^MAGENTA%^hu%^BOLD%^%^BLACK%^e from certain angles. This powerfully sinuous length holds aloft an %^WHITE%^alabaster %^BLACK%^female torso, whose %^MAGENTA%^s%^RESET%^%^MAGENTA%^e%^BOLD%^nsu%^RESET%^%^MAGENTA%^o%^BOLD%^us c%^RESET%^%^MAGENTA%^u%^BOLD%^rv%^RESET%^%^MAGENTA%^e%^BOLD%^s %^BLACK%^are draped in swathes of %^WHITE%^opulent cloth %^BLACK%^and an intricate %^ORANGE%^l%^RESET%^%^MAGENTA%^a%^YELLOW%^tt%^RESET%^%^MAGENTA%^i%^YELLOW%^ce of j%^RESET%^%^MAGENTA%^e%^YELLOW%^w%^RESET%^%^MAGENTA%^e%^YELLOW%^lry %^BLACK%^and %^ORANGE%^p%^RESET%^%^MAGENTA%^i%^YELLOW%^erc%^RESET%^%^MAGENTA%^i%^YELLOW%^ngs%^BLACK%^. From Her shoulders great black wings spread outward, and within them can be seen the %^CYAN%^twinkle %^BLACK%^of %^CYAN%^star light %^BLACK%^as though they contain the night sky itself. Ridged obsidian horns crown Her head, one pair swept back over the midnight tresses of hair that cascades down around Her body and the other pair curled like a ram. A hauntingly beautiful %^WHITE%^iv%^BLACK%^o%^WHITE%^ry m%^BLACK%^a%^WHITE%^sk %^BLACK%^hides the face of this %^MAGENTA%^divine %^BLACK%^being, its %^RESET%^%^MAGENTA%^full lips %^BOLD%^%^BLACK%^painted %^RESET%^%^MAGENTA%^purple %^BOLD%^%^BLACK%^and its eyes an endless sea of darkness. Marring the perfection of this mask are the many cracks throughout from which a black substance drips as if it is barely containing a deluge of darkness. Her arms are outstretched, inviting you into Her embrace...%^RESET%^",
        ({"nilith","statue 2"}) : "%^BOLD%^%^BLACK%^Standing among the lengthy serpentine coils and dark flames of the massive primordial is an unnaturally tall, dark skinned woman decorated in a %^ORANGE%^l%^RED%^a%^ORANGE%^tt%^RED%^i%^ORANGE%^c%^RED%^e %^BLACK%^of %^RED%^scarification %^BLACK%^and %^ORANGE%^g%^RESET%^%^ORANGE%^o%^BOLD%^ld p%^RESET%^%^ORANGE%^a%^BOLD%^int%^BLACK%^. Her hands and chest are %^WHITE%^d%^RESET%^e%^BOLD%^vo%^RESET%^i%^BOLD%^d %^BLACK%^of flesh, %^WHITE%^sk%^RESET%^e%^BOLD%^l%^RESET%^e%^BOLD%^tal f%^RESET%^i%^BOLD%^ngers %^BLACK%^clutching the handle of a %^RESET%^%^RED%^horrific %^ORANGE%^s%^BOLD%^%^WHITE%^c%^RESET%^%^ORANGE%^y%^BOLD%^%^WHITE%^th%^RESET%^%^ORANGE%^e %^BOLD%^%^BLACK%^that appears to have been crafted from the %^RESET%^%^ORANGE%^flesh %^BOLD%^%^BLACK%^and %^WHITE%^bone %^BLACK%^of suffering mortal creatures. Her rib cage is splayed open and carved to resemble a macabre maw and trapped within ghostly faces contorted in %^RESET%^%^RED%^a%^BOLD%^g%^RESET%^%^RED%^o%^BOLD%^ny%^BLACK%^.%^RESET%^",
        ({"lord shadow","statue 3"}) : "%^BOLD%^%^BLACK%^Standing among the lengthy serpentine coils and dark flames of the massive primordial is an intimidating figure of pure darkness. Clad in %^CYAN%^el%^BLACK%^a%^CYAN%^bor%^BLACK%^a%^CYAN%^te %^BLACK%^and %^CYAN%^ancient a%^BLACK%^rm%^CYAN%^o%^BLACK%^r this being stands proudly, features of pure obs%^WHITE%^i%^BLACK%^d%^WHITE%^i%^BLACK%^an %^RESET%^%^RED%^glaring %^BOLD%^%^BLACK%^imperiously from beneath a jagged crown of Ad%^RESET%^a%^BOLD%^%^BLACK%^m%^RESET%^a%^BOLD%^%^BLACK%^nt%^RESET%^i%^BOLD%^%^BLACK%^ne. Grasped between his claw like %^CYAN%^gauntlets %^BLACK%^is a %^RESET%^%^RED%^d%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^m%^BOLD%^%^BLACK%^o%^RESET%^%^RED%^nic gr%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^at sw%^BOLD%^%^BLACK%^o%^RESET%^%^RED%^rd %^BOLD%^%^BLACK%^whose tip is buried deep into the stone base at his feet, a v%^CYAN%^o%^BLACK%^rt%^CYAN%^e%^BLACK%^x of d%^CYAN%^a%^BLACK%^rk %^CYAN%^e%^BLACK%^n%^CYAN%^e%^BLACK%^rgy rising up around its blade.%^RESET%^",
        ({"khyron","statue 4"}) : "%^BOLD%^%^BLACK%^Standing among the lengthy serpentine coils and dark flames of the massive primordial is an %^RED%^o%^RESET%^%^RED%^th%^BOLD%^e%^RESET%^%^RED%^rw%^YELLOW%^o%^RESET%^%^RED%^rl%^BOLD%^d%^RESET%^%^RED%^ly b%^YELLOW%^e%^RED%^a%^RESET%^%^RED%^st %^BOLD%^%^BLACK%^ensconced in %^RED%^e%^RESET%^%^RED%^l%^YELLOW%^e%^RED%^m%^RESET%^%^RED%^e%^YELLOW%^n%^RESET%^%^RED%^ta%^BOLD%^l %^ORANGE%^e%^RESET%^%^RED%^n%^YELLOW%^e%^RED%^r%^RESET%^%^RED%^gy%^BOLD%^%^BLACK%^. A raging inferno forms a mane around a %^RED%^ferocious %^BLACK%^leonine face. Its muscular body is covered in cr%^ORANGE%^a%^BLACK%^c%^ORANGE%^k%^BLACK%^s from which an %^ORANGE%^or%^RESET%^%^ORANGE%^a%^BOLD%^%^RED%^n%^ORANGE%^ge g%^RED%^l%^RESET%^%^ORANGE%^o%^BOLD%^w %^BLACK%^can be seen, indicative of its %^ORANGE%^m%^RESET%^%^ORANGE%^o%^BOLD%^%^RED%^l%^ORANGE%^t%^RESET%^%^ORANGE%^e%^BOLD%^n c%^RESET%^%^ORANGE%^o%^BOLD%^%^RED%^r%^ORANGE%^e%^BLACK%^. Tines of %^ORANGE%^lightning %^BLACK%^fork between its three tails, each tipped with a %^GREEN%^s%^RESET%^%^GREEN%^e%^BOLD%^rp%^RESET%^%^GREEN%^e%^BOLD%^nt’s h%^RESET%^%^GREEN%^e%^BOLD%^ad%^BLACK%^, as well as from the tips of its claws and out of the furrowed stone beneath its cloven hooves. %^RESET%^",
        ({"faceless","the faceless one","statue 5"}) : "%^BOLD%^%^BLACK%^Sitting casually upon the lengthy serpentine coils of the massive primordial is a relatively small, clo%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^ked and hood%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^d f%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^g%^RESET%^%^RED%^u%^BOLD%^%^BLACK%^re. D%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^rk le%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^ther %^RESET%^%^RED%^a%^BOLD%^%^BLACK%^rm%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^r hugs tightly to a lean, %^RESET%^%^RED%^athletic %^BOLD%^%^BLACK%^body whose size and shape is completely %^RESET%^%^RED%^androgynous%^BOLD%^%^BLACK%^. Straps on the arms and legs bristle with throwing weapons and the hilts of a pair of ornate, j%^RED%^e%^BLACK%^t h%^RED%^a%^BLACK%^ndl%^RED%^e%^BLACK%^d %^RED%^daggers %^BLACK%^peek from beneath the cloak at their sides. When you attempt to look upon their face you find a %^RED%^g%^RESET%^%^RED%^o%^BOLD%^ry m%^RESET%^%^RED%^a%^BOLD%^sk dr%^RESET%^%^RED%^i%^BOLD%^pp%^RESET%^%^RED%^i%^BOLD%^ng bl%^RESET%^%^RED%^o%^BOLD%^od%^BLACK%^, sewn together from the faces of various beings. The lips of this patchwork face are twisted into a cruel grin and the %^RED%^cr%^RESET%^%^RED%^i%^BOLD%^ms%^RESET%^%^RED%^o%^BOLD%^n %^RESET%^%^RED%^e%^BOLD%^y%^RESET%^%^RED%^e%^BOLD%^s %^BLACK%^are full of %^RESET%^%^RED%^m%^BOLD%^a%^RESET%^%^RED%^lev%^BOLD%^o%^RESET%^%^RED%^l%^BOLD%^e%^RESET%^%^RED%^nc%^BOLD%^e%^BLACK%^. %^RESET%^",
        ({"shadow","shade","darkness"}) : "%^BOLD%^%^BLACK%^All around you, the air is filled with a pervasive gloom that whirls and flows like a sea of darkness. Dark shapes swim through this sea just beyond your vision revealed only barely by the %^MAGENTA%^soft glow%^BLACK%^ of the %^MAGENTA%^windows.%^RESET%^",
        ({"altar",""}) : "%^BOLD%^%^BLACK%^A boulder of unworked and jagged obsid%^WHITE%^i%^BLACK%^an rests in the center of the landing like the cold black heart of this temple. Its r%^RESET%^e%^BOLD%^%^BLACK%^flect%^WHITE%^i%^BLACK%^ve surface seems to capture the images in it, only slowly allowing them to fade. The air around the altar is charged with a %^RESET%^%^MAGENTA%^powerful %^BOLD%^energy %^BLACK%^that tingles across your skin as you approach it, and its smooth surface is %^RESET%^%^RED%^warm %^BOLD%^%^BLACK%^to the touch.%^RESET%^",
        ({"archway","This %^BOLD%^silver archway%^RESET%^ has a painstakingly detailed %^BOLD%^%^BLACK%^raven%^RESET%^ molded at its head. The %^BOLD%^%^BLACK%^ravens %^RESET%^wings are outstretched and tiny %^BOLD%^%^MAGENTA%^amethysts %^RESET%^dot its wing tips and form its %^MAGENTA%^eyes%^RESET%^."}) : "",
        ({"cushions","pillows"}) : "%^BOLD%^%^BLACK%^Plush velvet cushions adorn each level of the sitting area, each displaying a matching web-like design of %^RESET%^%^MAGENTA%^deep violet%^BOLD%^%^BLACK%^.%^RESET%^",
        ({"desk"}) : "%^BOLD%^%^BLACK%^A long curving desk dominates the west wall, its surface freshly polished to a m%^RESET%^i%^BOLD%^%^BLACK%^rr%^RESET%^o%^BOLD%^%^BLACK%^r %^WHITE%^sheen%^BOLD%^%^BLACK%^. Behind it sit several %^RESET%^%^MAGENTA%^acolytes %^BOLD%^%^BLACK%^tending to the racks of %^RESET%^holy water%^BOLD%^%^BLACK%^, %^BOLD%^%^MAGENTA%^symbols%^BLACK%^ and %^ORANGE%^donations%^BLACK%^ which they slip into a %^RESET%^%^MAGENTA%^purple trimmed%^BOLD%^%^BLACK%^ black box. The dark plaque hanging over the racks displays the services that can be provided in %^WHITE%^fl%^RESET%^o%^BOLD%^w%^RESET%^i%^BOLD%^ng s%^RESET%^i%^BOLD%^lver scr%^RESET%^i%^BOLD%^pt.%^RESET%^",
        ({"podium"}) : "%^BOLD%^%^BLACK%^This sturdy podium is engraved with the images of the Dark Unity; %^CYAN%^Lord Shadow%^BLACK%^, %^RESET%^%^RED%^The Faceless One%^BOLD%^%^BLACK%^, %^WHITE%^Nilith%^BLACK%^, %^RED%^Khyron %^BLACK%^and %^RESET%^%^MAGENTA%^A%^BOLD%^%^BLACK%^s%^RESET%^%^MAGENTA%^h%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^a %^BOLD%^%^BLACK%^herself. Resting open upon the podium is a dark tome, the libram of the eternal night, open to the passage of %^RESET%^%^MAGENTA%^A%^BOLD%^%^BLACK%^s%^RESET%^%^MAGENTA%^h%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^’s charge upon her faithful.%^RESET%^",
    ]));
    set_exits(([
        "south " : "salon",
        "east" : "roost",
    ]));
    set_door("chapel door","salon","south",0);
    set_door_description("%^BOLD%^%^BLACK%^Large wooden double doors painted pitch black stand here. The doors are engraved with a sp%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^l p%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^tt%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^rn of %^RESET%^%^MAGENTA%^wr%^BOLD%^%^BLACK%^i%^RESET%^%^MAGENTA%^thing t%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^nt%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^cles %^BOLD%^%^BLACK%^emanating from a central %^RESET%^%^MAGENTA%^circle%^BOLD%^%^BLACK%^. They look very thick, and you can hear nothing from beyond them.%^RESET%^");
}