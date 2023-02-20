// Chernobog (1/16/23)
// Schoolroom addition to Torm Library
// Written by Gwenwhyfar

#include <std.h>
inherit ROOM;

void create(){
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("light", 1);
    set_property("indoors", 1);
    set_property("no sticks", 1);
    set_name("The Torm School for Children");
    set_short("%^RESET%^%^CRST%^%^C021%^The Torm School for Children%^CRST%^");
	set_long("%^RESET%^%^CRST%^%^C172%^This classroom is a large %^C011%^a%^C012%^i%^C013%^r%^C015%^y%^C172%^ rectangular room. It has a high vaulted ceiling that is 12 foot in height and has a slanted %^C004%^sk%^C015%^yl%^C004%^ight%^C172%^ which provides %^C195%^light%^C172%^ to the room in %^C227%^daylight%^C172%^ hours. Hanging from the ceiling are several %^C241%^lanterns%^C172%^ for %^C241%^dark%^C172%^ %^C192%^days%^C172%^ and %^C004%^evenings%^C172%^. The walls are adorned by %^C241%^blackboards%^C172%^ chock-full of %^RESET%^%^C129%^writings%^C172%^ and %^C129%^drawings%^C172%^ that are obvious %^C129%^lessons%^C172%^ for different %^C129%^subjects%^C172%^. Beneath the %^C241%^blackboards%^C172%^ are %^C094%^low mahogany bookshelves%^C172%^ that are crammed full of %^C129%^educational books%^C172%^ and %^RESET%^%^C011%^t%^C012%^o%^C013%^y%^C014%^s%^C172%^.  The floor is carpeted by %^C021%^thick blue carpeting%^C172%^. At the head of the room is a teacher's %^C094%^desk%^C172%^ facing out toward the class and is a %^C094%^mahogany mission style pedestal desk with four filing cabinet drawers%^RESET%^%^C172%^.  The room has several rows of student %^C094%^desks%^C172%^ that are %^C094%^wooden seats with slanted writing spaces%^C172%^ affixed to %^C001%^d%^C002%^e%^C004%^c%^C005%^o%^C006%^r%^C009%^a%^C010%^t%^C011%^i%^C012%^v%^C011%^e%^C172%^ %^RESET%^%^C241%^wrought iron frames%^C172%^. Finally, in a far corner of the classroom, a %^C094%^mahogany upright teaching piano and matching bench%^C172%^ can be found.%^CRST%^\n");
    set_smell("default", "%^CRST%^%^RESET%^%^C172%^This room smells of books, parchment, and chalk.%^CRST%^");
    set_listen("default", "%^CRST%^%^RESET%^%^C172%^You hear the sound of a feminine voice teaching intermixed with the occasional voices and laughter of children.%^CRST%^");
    set_items(([
        "student desk": "%^RESET%^%^CRST%^%^C094%^This desk is a wooden seat with a slanted writing space affixed to a%^CRST%^ %^C093%^decorative%^CRST%^ %^C241%^wrought iron frame.%^CRST%^",
        "teachers desk": "%^RESET%^%^CRST%^%^C094%^This desk is a mahogany mission style pedestal desk with four filing cabinet drawers.%^CRST%^",
        "blackboards": "%^RESET%^%^CRST%^%^C241%^The blackboards line the walls and are comprised of thin black slate. Each blackboard has various %^C015%^writings and drawings%^C241%^ on them for different %^C015%^subjects%^C241%^.%^CRST%^",
        "floor": "%^RESET%^%^CRST%^%^C012%^The floor is covered by thick blue carpeting.%^CRST%^",
        "ceiling": "%^RESET%^%^CRST%^%^C172%^The ceiling is vaulted and quite high at 12 foot in height and has a slanted %^C020%^skylight%^C172%^ and hanging %^C008%^lanterns.%^CRST%^",
        "skylight": "%^RESET%^%^CRST%^%^C019%^This skylight is slanted and made of %^C015%^transparent glass%^C019%^. It provides the room with %^C226%^light%^C019%^ during %^C226%^daylight%^C019%^ hours. %^CRST%^",
        "walls": "%^RESET%^%^CRST%^%^C172%^The walls are adorned by %^C241%^blackboards%^C172%^ and %^C094%^low bookcases.%^CRST%^",
        "bookcases": "%^RESET%^%^CRST%^%^C094%^The low bookcases are mahogany and filled with %^C129%^various books%^C094%^ and %^C129%^educational toys%^C094%^.%^CRST%^",
        "piano": "%^RESET%^%^CRST%^%^C094%^This piano is an upright mahogany teaching piano with matching bench.%^CRST%^",
        ]));
    set_exits(([
        "library" : "/d/dagger/Torm/city/library1",
        "out" : "/d/dagger/Torm/city/c97",
        ]));
}

void reset(){
    ::reset();
    if(!present("assistant")) new("/d/dagger/Torm/mon/assistant")->move(this_object());
    if(!present("teacher")) new("/d/dagger/Torm/mon/teacher")->move(this_object());
}

