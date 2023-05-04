// Chernobog (4/24/23)
// Temple of Cacia - Flesh
// Written by Branwen

#include <std.h>

inherit ROOM;

void create(){
    ::create();
    set_terrain(CITY);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("lust");
    set_short("%^C104%^The Temptation of Flesh, Cacia's Temple%^CRST%^");
    set_long("%^C104%^This chamber is a %^C091%^decadent sanctuary%^C104%^, the air heavy with exotic scents of %^C103%^alluring incense%^C104%^ and %^C103%^intoxicating perfumes%^C104%^. The %^C184%^w%^C178%^a%^C172%^r%^C178%^m %^C184%^g%^C178%^l%^C172%^o%^C178%^w%^C104%^ of %^C146%^countless candles%^C104%^ and %^C146%^oil lamps%^C104%^ casts a %^C111%^spellbinding aura%^C104%^ across the space, while %^C089%^o%^C090%^p%^C089%^u%^C088%^l%^C089%^e%^C090%^n%^C089%^t %^C088%^f%^C089%^a%^C090%^b%^C089%^r%^C088%^i%^C089%^c%^C090%^s%^C104%^ cascade from the walls, radiating an air of pure luxury. In the center of the room, a large %^C134%^circular platform%^C104%^ beckons, adorned with %^C090%^p%^C091%^l%^C092%^u%^C093%^sh %^C090%^c%^C091%^u%^C092%^s%^C093%^hions%^C104%^ and %^C093%^pill%^C092%^o%^C091%^w%^C090%^s%^C104%^, where devotees lounge entwined in each other's arms, lost in the throes of endless, %^C105%^indulgent exploration%^C104%^ of %^C105%^carnal delights%^C104%^. The walls are adorned with %^C140%^tantalizing alcoves%^C104%^ and %^C140%^niches%^C104%^, each revealing a %^C140%^treasure trove%^C104%^ of enticing %^C134%^implements%^C104%^, urging guests to surrender to their %^C091%^deepest%^C104%^ and most %^C091%^sensual desires%^C104%^.%^RESET%^\n");
    set_smell("default", "%^C090%^The air is thick with the scent of %^C096%^burning candles%^C090%^, %^C096%^exotic perfumes%^C090%^, and the %^C096%^musk of bodies%^C090%^.%^CRST%^");
    set_listen("default", "%^C126%^Soft, %^C132%^sensual music%^C126%^ plays in the background, the low, %^C133%^sultry tones%^C126%^ thrumming through your body.%^CRST%^");
    set_items(([
		({ "platform", "cushions", "pillows", "devotees" }) : "%^C134%^The large circular platform in the center of the room is a sumptuous feast for the senses. Its surface is covered in an array of %^C089%^plush cushions%^C134%^ and %^C089%^pillows%^C134%^, their soft textures inviting visitors to recline and luxuriate in comfort. Here, devotees of all persuasions can be found, entwined in an %^C139%^ecstatic dance%^C134%^ of %^C125%^desire%^C134%^ and %^C125%^pleasure%^C134%^. Their bodies entangled, they writhe and twist, each movement a %^C127%^prayer%^C134%^ to the unbridled passion that fills the room. Every gesture and touch is charged with %^C129%^electricity%^C134%^, sending shivers of pleasure down the spine and leaving visitors breathless and wanting more. It is a veritable playground of sensual delights, and one cannot help but be drawn in by its allure.%^CRST%^",
		({ "alcoves", "niches", "objects", "tools" }) : "%^C153%^As you examine the alcoves and niches that adorn the walls, you're greeted with a tempting assortment of %^C147%^objects%^C153%^ and %^C147%^tools%^C153%^, all designed to unlock the deepest pleasures of your senses. The smooth, polished curves of %^C101%^ornate wooden%^C153%^ and %^C250%^metal implements%^C153%^ beckon to be held, while the touch of %^C090%^leather%^C153%^, %^C089%^silk%^C153%^, and other %^C091%^sumptuous materials%^C153%^ against your skin ignites a %^C125%^primal desire%^C153%^ within you. You'll find %^C245%^floggers%^C153%^ and %^C245%^whips%^C153%^ to tease and tantalize, %^C248%^candles%^C153%^ and %^C248%^oils%^C153%^ to heighten your senses, and an array of %^C250%^restraints%^C153%^, %^C251%^ticklers%^C153%^, %^C252%^dildos%^C153%^, %^C253%^blindfolds%^C153%^, and %^C255%^gags%^C153%^ that promise to take you to the %^C090%^very edge%^C153%^ of ecstasy. These tools await you, %^C147%^daring%^C153%^ you to explore your most %^C135%^intimate desires%^C153%^ and unlock the %^C129%^boundless potential%^C153%^ of your pleasure.%^CRST%^",
		({ "walls", "fabrics" }) : "%^C089%^The walls of the room are adorned with luxurious fabrics in %^C090%^deep, %^C091%^rich hues%^C089%^, which cascade down in sensuous waves, lending an air of opulence to the space. The %^C090%^f%^C091%^a%^C092%^b%^C093%^r%^C092%^i%^C091%^c%^C090%^s%^C089%^ feel soft and silky to the touch, inviting you to run your fingers along their %^C090%^smooth surface%^C089%^.%^CRST%^",
		({ "candles", "oil lamps" }) : "%^C243%^The %^C250%^oil lamps%^C243%^ and %^C250%^candles%^C243%^ emit a soft, %^C193%^golden glow%^C243%^ and a myriad of alluring aromas. They are placed strategically around the space, providing additional lighting and creating a %^C110%^dreamlike ambiance%^C243%^.%^CRST%^",
        ]));
    set_exits(([
        "out" : "/d/magic/temples/cacia/cacia",
        ]));
}

