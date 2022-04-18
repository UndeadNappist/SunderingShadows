#include <std.h>
#include "../tharis.h"

inherit ROOM;

void create(){
    ::create();
    set_terrain(OLD_MOUNTS);
    set_travel(DIRT_ROAD);
    set_property("indoors",0);
    set_property("light",1);
    set_name("A plaza in a city");
    set_short("%^RESET%^%^CRST%^%^C244%^The %^RESET%^%^C098%^E%^C099%^a%^C141%^s%^C140%^t%^C141%^e%^C099%^r%^C098%^n %^C099%^P%^C141%^l%^C140%^a%^C140%^z%^C099%^a%^RESET%^%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C244%^Drawing the eye before anything else here is the vast, looming bulk of the hovering %^C241%^Shadovar fortress%^C244%^, far in the sky above. It casts the entire city under a pall of %^C241%^unrelenting darkness%^C244%^. The m%^RESET%^%^C028%^o%^RESET%^%^C246%^t%^C247%^t%^C249%^l%^RESET%^%^C022%^e%^RESET%^%^C251%^d c%^RESET%^%^C022%^o%^RESET%^%^C249%^b%^C247%^b%^C246%^l%^C245%^e%^C246%^s%^C247%^t%^RESET%^%^C028%^o%^RESET%^%^C250%^n%^C244%^es in this part of the city appear freshly lain, arranged in a spiral pattern, at the center of which is a circular %^C241%^dais %^C244%^dominated by a smooth %^C241%^obsidian obelisk%^C244%^. A %^RESET%^%^C093%^p%^C099%^u%^C092%^l%^C098%^s%^C093%^i%^C099%^n%^C092%^g%^RESET%^%^C244%^, %^RESET%^C093%^violet light %^RESET%^%^C244%^emanates from within the pillar, its position directly corresponding with the current time of day. Six elegant %^C241%^stone statues%^C244%^ span the perimeter of the plaza, facing out from the middle as if observing the comings and goings in the area. %^C241%^Street lamps %^C244%^housing tiny %^RESET%^%^C135%^g%^C134%^l%^C133%^o%^C134%^w %^C135%^g%^C141%^l%^C147%^o%^C153%^b%^C147%^e%^C141%^s%^RESET%^%^C244%^ bathe the area in a %^RESET%^%^C135%^d%^C141%^u%^C147%^s%^C153%^k%^C147%^y %^C141%^l%^C135%^u%^C141%^m%^C147%^i%^C153%^n%^C147%^e%^C141%^s%^C147%^c%^C153%^e%^C141%^n%^C135%^c%^C141%^e, %^RESET%^%^C244%^allowing the normal-sighted people of the city to move around with relative ease without hindering the Nyctophiles. %^RESET%^%^C129%^C%^C135%^o%^C141%^l%^C128%^o%^C134%^r%^C140%^f%^C127%^u%^C133%^l%^RESET%^%^C244%^ and constructed from the finest materials, the buildings that surround the plaza speak to a prosperous, advanced city. Bordering the roundabout are raised %^C250%^m%^C248%^a%^C244%^r%^C248%^b%^C250%^le s%^C244%^i%^C248%^d%^C241%^e%^C248%^w%^C244%^a%^C250%^lks%^C244%^, allowing safe travel for pedestrians on foot. Directly south, the wide street begins a gradual descent, %^RESET%^%^C058%^supply carts %^RESET%^%^C244%^and sleek, horseless %^C241%^carriages %^C244%^heading toward and emerging from the maw %^C244%^of a massive subterranean tunnel. Newcomers from the %^RESET%^%^C099%^carriage house %^C244%^just to the west spill out into the grand plaza, scurrying about like so many %^C241%^ants %^C244%^to their various destinations. From here, unique architecture looms on the %^RESET%^%^C098%^h%^C097%^o%^C096%^r%^C095%^i%^C096%^z%^C097%^o%^C098%^n %^RESET%^%^C244%^of the northeast and southeast quadrants of the city, while to the east lies the %^C248%^industrial section%^C244%^, and to the west a foreboding compound.%^CRST%^\n");
    set_smell("default","%^RESET%^%^CRST%^%^C141%^The air carries the thousand scents of a busy city.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C099%^You hear the bustle of the citizens going about their day.%^CRST%^");
    set_items(([
        ({"obelisk", "pillar"}) : "%^RESET%^%^CRST%^%^C244%^This %^C241%^obelisk %^C244%^towers above the plaza, scraping the sky like an ominous spear. Its surface is s%^C243%^m%^C245%^o%^C247%^o%^C243%^t%^C244%^h and %^RESET%^%^C045%^r%^C051%^e%^C087%^f%^C123%^l%^C159%^e%^C123%^c%^C087%^t%^C051%^i%^C045%^v%^C039%^e%^RESET%^%^C244%^, and it appears to have been crafted from %^RESET%^%^C241%^obsidian%^C244%^. A %^RESET%^%^C093%^p%^C099%^u%^C092%^l%^C098%^s%^C093%^i%^C099%^n%^C092%^g%^RESET%^%^C244%^, %^RESET%^C093%^violet light %^RESET%^%^C244%^emanates from within the depths of the %^C241%^dark stone%^C244%^, its location on the obelisk directly correlating with the time; at the turn of the %^C227%^d%^C229%^a%^C226%^y%^C244%^, the %^RESET%^%^C093%^l%^C092%^i%^C091%^g%^C092%^h%^C093%^t %^RESET%^%^C244%^appears at the base of the pillar and slowly ascends until it meets the top just before the stroke of %^RESET%^%^C019%^m%^C020%^i%^C021%^d%^C019%^n%^C020%^i%^C021%^g%^C020%^h%^C019%^t%^RESET%^%^C244%^.%^CRST%^",
        "statues" : "%^RESET%^%^CRST%^%^C244%^These statues were crafted by an incredibly talented artisan, all life-like and wrought in fine detail. They appear to be carved from pure %^C241%^obsidian%^C244%^, but for a few unique details that help differentiate them from one another.%^CRST%^",
        "statue 1" : "%^RESET%^%^CRST%^%^C241%^This statue depicts a humanoid figure shrouded in writhing shadow. You can barely make out the shape of a %^C248%^majestic crown %^C244%^upon the brow of a well-built man. He stands tall and regal, a flowing cape of %^RESET%^%^C020%^pure midnight %^RESET%^%^C241%^cascading from his shoulders with tiny p%^C253%^i%^C244%^npr%^C250%^i%^C244%^cks of %^C231%^s%^C159%^p%^C195%^a%^C230%^r%^C159%^k%^C225%^l%^C231%^i%^C195%^n%^C159%^g %^C231%^light %^RESET%^%^C244%^just beneath its surface. He is poised for battle, a %^C241%^rod %^C244%^held aloft in one hand while the other reaches for the components pouch slung from his belt. A %^C245%^s%^C246%^i%^C247%^l%^C248%^v%^C249%^e%^C248%^r %^C247%^p%^C246%^l%^C245%^a%^C246%^q%^C247%^u%^C248%^e %^C244%^at the base of the statue reads, %^RESET%^%^C241%^\"%^C248%^Nero, first son of Lord Shadow%^RESET%^%^C241%^\"%^RESET%^%^C244%^.%^CRST%^",
        "statue 2" : "%^RESET%^%^CRST%^%^C244%^So much swirling %^C241%^darkness %^C244%^surrounds this figure that you can barely make out the shape of a %^C248%^majestic crown%^C244%^, nestled upon locks of wavy %^C241%^black hair %^C244%^that cascade down the lithe form of a female %^RESET%^%^C241%^shade%^C244%^. She is dressed in a flowing gown of pure night with tiny p%^C253%^i%^C244%^npr%^C250%^i%^C244%^cks of %^C231%^s%^C159%^p%^C195%^a%^C230%^r%^C159%^k%^C225%^l%^C231%^i%^C195%^n%^C159%^g %^C231%^light %^RESET%^%^C244%^just beneath its depths. Clutched in one of her delicate hands is a %^RESET%^%^C241%^wand %^RESET%^%^C244%^that she holds aloft and in the other, a roiling ball of %^C045%^e%^C051%^n%^C087%^e%^C087%^r%^C051%^g%^C045%^y%^RESET%^%^C244%^. A %^C245%^s%^C246%^i%^C247%^l%^C248%^v%^C249%^e%^C248%^r %^C247%^p%^C246%^l%^C245%^a%^C246%^q%^C247%^u%^C248%^e %^C244%^at the base of the statue reads, %^RESET%^%^C241%^\"%^C248%^Sophia, first daughter of Lord Shadow%^RESET%^%^C241%^\"%^RESET%^%^C244%^.%^CRST%^",
        "statue 3" : "%^RESET%^%^CRST%^%^C244%^A statuesque woman wearing an %^C241%^obsidian tiara %^C244%^with %^RESET%^%^C045%^a%^C051%^z%^C087%^u%^C123%^r%^C159%^e %^C123%^g%^C087%^e%^C051%^m%^C045%^s%^RESET%^%^C244%^ stands tall before you, clad in %^C241%^black ceremonial vestments %^C244%^with %^C244%^with %^RESET%^%^C045%^a%^C051%^z%^C087%^u%^C123%^r%^C159%^e %^C123%^t%^C087%^r%^C051%^i%^C045%^m%^C051%^m%^C087%^i%^C123%^n%^C087%^g%^C051%^s%^RESET%^%^C244%^. An amulet bearing the holy symbol of %^C241%^Lord Shadow %^C244%^is proudly displayed upon her chest. %^C241%^Shadows %^C244%^cling to her body and caress her face, %^RESET%^%^C020%^obscuring %^C244%^her true features. A %^C245%^s%^C246%^i%^C247%^l%^C248%^v%^C249%^e%^C248%^r %^C247%^p%^C246%^l%^C245%^a%^C246%^q%^C247%^u%^C248%^e %^C244%^at the base of the statue reads, %^RESET%^%^C020%^\"%^C025%^Sisenna, second daughter of Lord Shadow%^RESET%^%^C025%^\"%^RESET%^%^C244%^.%^CRST%^",
        "statue 4" : "%^RESET%^%^CRST%^%^C244%^A handsome%^C241%^ shade %^C244%^adorned in a custom-tailored three-piece suit stands before you, wrought in obsidian. Atop his brow is a crown of %^RESET%^%^C129%^v%^C135%^i%^C141%^o%^C135%^l%^C129%^e%^C135%^t %^C141%^f%^C135%^l%^C129%^a%^C135%^m%^C141%^e%^C135%^s %^RESET%^%^C244%^and every inch of his dignified being, from the tip of his fine shoes to the top of his %^C129%^crown%^RESET%^%^C244%^, gives the impression of power and wealth. A wide smile graces his handsome features, though it does not reach his eyes, which of course are an %^C241%^inky black %^C244%^but for a faint %^RESET%^%^C129%^v%^C135%^i%^C141%^o%^C135%^l%^C129%^e%^C135%^t %^C141%^l%^C135%^i%^C129%^g%^C135%^h%^C141%^t %^RESET%^%^C244%^just below the surface of the stone. A %^C245%^s%^C246%^i%^C247%^l%^C248%^v%^C249%^e%^C248%^r %^C247%^p%^C246%^l%^C245%^a%^C246%^q%^C247%^u%^C248%^e %^C244%^at the base of the statue reads, %^RESET%^%^C129%^\"%^C141%^Paullus, third son of Lord Shadow%^RESET%^%^C129%^\"%^RESET%^%^C244%^.%^CRST%^",
        "statue 5" : "%^RESET%^%^C244%^This %^C241%^obsidian %^C244%^statue depicts a younger %^C241%^shade %^C244%^wearing a %^C241%^black breastplate %^C244%^and an %^RESET%^%^C045%^a%^C051%^z%^C087%^u%^C123%^r%^C159%^e %^C123%^c%^C087%^r%^C051%^o%^C045%^w%^C051%^n %^RESET%^%^C244%^that keeps his lustrous curls out of his face. %^C241%^Darkness %^C244%^roils off his lean, muscular form, which appears poised for battle with two of his gauntleted fingers pressed to his temple whilst the other hand grips a fine gladius. A %^C245%^s%^C246%^i%^C247%^l%^C248%^v%^C249%^e%^C248%^r %^C247%^p%^C246%^l%^C245%^a%^C246%^q%^C247%^u%^C248%^e %^C244%^at the base of the statue reads, %^RESET%^%^C045%^\"%^C051%^Cato, fourth son of Lord Shadow%^RESET%^%^C045%^\"%^RESET%^%^C244%^.%^CRST%^",
        "statue 6" : "%^RESET%^%^CRST%^%^C244%^This female %^C241%^shade %^C244%^immortalized in stone is of immense beauty, by far the most precious gem of the lot. %^C241%^Shadowy wings %^C244%^extend from her slender back, lifting her so that her delicate feet hover just above the ground. She is swathed in a flowing gown of %^C241%^pure darkness %^C244%^with %^RESET%^%^C088%^r%^C124%^u%^C160%^b%^C196%^i%^C160%^e%^C088%^s %^RESET%^%^C244%^tw%^C124%^i%^C244%^nkl%^C196%^i%^RESET%^%^C244%^ng across its surface like %^C124%^red stars %^RESET%^%^C244%^in the %^C241%^night sky. Atop a flowing mane of %^C241%^raven hair%^C244%^ she wears a %^C241%^black crown%^C244%^, also adorned with %^RESET%^%^C088%^r%^C124%^u%^C160%^b%^C196%^i%^C160%^e%^C088%^s. A %^C245%^s%^C246%^i%^C247%^l%^C248%^v%^C249%^e%^C248%^r %^C247%^p%^C246%^l%^C245%^a%^C246%^q%^C247%^u%^C248%^e %^RESET%^%^C244%^at the base of the statue reads, %^RESET%^%^C088%^\"%^C124%^Glycia, third daughter of Lord Shadow%^RESET%^%^C088%^\"%^RESET%^%^C244%^.%^CRST%^",
        ({"street lamp", "glow globes"}) : "%^RESET%^%^CRST%^%^C244%^Tall %^C241%^iron lamp posts %^C244%^line the plaza at regular intervals. Tiny %^RESET%^%^C135%^g%^C134%^l%^C133%^o%^C134%^w %^C135%^g%^C141%^l%^C147%^o%^C153%^b%^C147%^e%^C141%^s%^RESET%^%^C244%^ housed are within their %^RESET%^%^C051%^g%^C087%^l%^C123%^a%^C159%^s%^RESET%^%^C051%^s %^RESET%^%^C244%^cages.%^CRST%^",
        "fortress" : "%^RESET%^%^CRST%^%^C244%^Above the city looms the ever-present %^C241%^Shadovar fortress%^C244%^, casting the entire area into a state of perpetual %^RESET%^%^C057%^t%^C056%^w%^C055%^i%^C063%^l%^C062%^i%^C063%^g%^C055%^h%^C057%^t%^RESET%^%^C244%^.%^CRST%^",
        ({"cobblestones", "street", "road", "ground"}) : "%^RESET%^%^CRST%^%^C244%^The road in the eastern plaza circles the obelisk at its center, creating a roundabout. The %^C249%^cobblestones %^C244%^appear freshly lain, mostly in m%^C246%^o%^C247%^t%^C249%^t%^C247%^l%^C246%^e%^C244%^d shades of %^C249%^gray%^C244%^. However, swaths of them have been painted with a %^RESET%^%^C022%^v%^C028%^e%^C029%^r%^C035%^d%^C041%^a%^C035%^n%^C029%^t %^C028%^g%^C022%^l%^C028%^a%^C029%^z%^C035%^e%^RESET%^%^C244%^, making them stand out amongst the rest.%^CRST%^",
        "architecture" : "%^RESET%^%^CRST%^%^C244%^From here you can see that some unique architecture has been erected in the northeast and southeast quadrants of the city. To the northeast, the buildings resemble towering black stalagmites %^C231%^s%^C183%^h%^C189%^i%^C194%^m%^C195%^m%^C225%^e%^C230%^r%^C159%^i%^C153%^n%^C231%^g %^RESET%^%^C244%^with %^RESET%^%^C046%^p%^C047%^h%^C048%^o%^C049%^s%^C050%^p%^C051%^h%^C087%^o%^C086%^r%^C085%^e%^C084%^s%^C083%^c%^C082%^e%^C119%^n%^C120%^t %^C121%^l%^C122%^i%^C123%^c%^RESET%^%^C040%^h%^C041%^e%^C042%^n%^RESET%^%^C244%^. Carved directly from the rock are elegant archways, lofty %^C242%^balconies%^C244%^, and %^C255%^w%^C250%^e%^C255%^b%^C244%^-like walkways connecting the structures. The buildings to the southeast are more traditional in make and %^C241%^gothic %^C244%^by design, featuring pointed archways, flying buttresses, and %^RESET%^%^C053%^s%^C054%^t%^C055%^a%^C056%^i%^C057%^n%^C089%^e%^C090%^d%^RESET%^%^C244%^-%^C091%^g%^C092%^l%^C093%^a%^C057%^s%^C063%^s %^RESET%^%^C244%^windows.%^CRST%^",
        "tunnel" : "%^RESET%^%^CRST%^%^C244%^Toward the south, the c%^RESET%^%^C022%^o%^RESET%^%^C249%^b%^C247%^b%^C246%^l%^C245%^e%^C246%^s%^C247%^t%^RESET%^%^C028%^o%^RESET%^%^C250%^n%^C244%^e %^C244%^street begins to descend toward the %^C241%^yawning maw %^C244%^of a giant tunnel, lit by sconces of dancing %^RESET%^%^C161%^f%^C162%^a%^C163%^e%^C164%^r%^C165%^i%^C201%^e %^C200%^f%^C199%^i%^C198%^r%^C197%^e%^RESET%^%^C244%^.%^CRST%^",
        ]));
    set_exits(([
        "east" : ROOMS"elf3",
        "west" : ROOMS"elf1",
        ]));
}

void init(){
    ::init();
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}
