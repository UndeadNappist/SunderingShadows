// Branwen (6/4/22)
// Yniam Waystation - Outside of Cacia's temple

#include <std.h>
#include "/d/dagger/yniam/defs.h"

inherit ROOM;

void create(){
    ::create();
    set_terrain(CITY);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);
    set_name("cacia's temple");
    set_short("%^C133%^A temple courtyard, Yniam%^CRST%^");
    set_long("%^CRST%^%^C060%^As you approach Cacia's temple, the pastoral beauty of the Yniam Plains gives way to an unsettling contrast. A circle of %^C240%^b%^C241%^l%^C242%^a%^C243%^c%^C242%^k %^C241%^s%^C240%^t%^C241%^o%^C242%^n%^C243%^e%^C242%^s%^C060%^ surrounds the open courtyard, each one polished to a reflective sheen that seems to absorb all light, casting a %^C240%^deep shadow%^C060%^ over the area. The stones are etched with %^C097%^in%^C098%^tr%^C099%^ic%^C105%^at%^C104%^e s%^C103%^ym%^C097%^bo%^C098%^ls%^C060%^, hinting at a language long forgotten, and adding to the sense of foreboding and mystery that surrounds the temple. The entrance to the temple is an %^C240%^im%^C241%^pr%^C242%^es%^C243%^si%^C242%^ve %^C241%^ar%^C240%^ch%^C241%^wa%^C242%^y%^C060%^, flanked by %^C240%^c%^C241%^o%^C242%^l%^C243%^u%^C242%^m%^C241%^n%^C240%^s%^C060%^ adorned with %^C061%^delicate details%^C060%^ and %^C061%^decorative motifs%^C060%^. The designs on the columns are expertly crafted, evoking the promise of %^C096%^sensual pleasure%^C060%^ and %^C096%^indulgence%^C060%^ that is synonymous with Cacia's teachings. Each design is more %^C097%^alluring%^C060%^ than the last, drawing you in with its seductive power and making it impossible to resist the temple's call.%^RESET%^\n\n%^RESET%^%^C059%^Little else flourishes here, and even the wind seems hesitant to expel its breath, the world stilled as if waiting for a ravenous predator to pass.\n%^CRST%^");
    set_smell("default", "%^C140%^The air is thick with the scent of %^C139%^e%^C175%^x%^C176%^o%^C140%^t%^C139%^i%^C175%^c %^C176%^s%^C140%^p%^C139%^i%^C175%^c%^C176%^es%^C140%^ and %^C139%^p%^C175%^e%^C140%^r%^C139%^f%^C175%^u%^C176%^m%^C140%^e%^C139%^s%^C140%^.%^CRST%^");
    set_listen("default", "%^C103%^The only sound you can hear is the distant, %^C104%^al%^C140%^lu%^C176%^ri%^C140%^ng %^C104%^m%^C140%^u%^C176%^s%^C140%^i%^C104%^c%^C103%^ that seems to emanate from within the temple itself.%^CRST%^");
    set_items(([
        "temple" : "%^C090%^The %^C089%^circular structure%^C090%^ is built from %^C240%^d%^C243%^a%^C240%^rk%^C090%^, %^C240%^po%^C241%^li%^C242%^sh%^C243%^ed %^C242%^st%^C241%^o%^C242%^ne%^C090%^, giving it an imposing and foreboding appearance. The walls are thick and sturdy, with few openings or windows to the outside world. The temple's roof is domed and covered in a %^C240%^dark%^C090%^, %^C243%^shimmering %^C240%^material%^C090%^, giving it a mysterious and otherworldly quality. The entrance to the temple is framed by a wide, %^C240%^ornate archway%^C090%^, supported by intricately carved %^C240%^columns%^C090%^ on either side. The archway itself is adorned with %^C092%^sensual designs%^C090%^ and %^C092%^motifs%^C090%^, depicting scenes of %^C097%^pleasure%^C090%^ and %^C097%^indulgence%^C090%^ that are sure to tempt even the most stoic of visitors.%^CRST%^",
        ({ "archway", "columns", "entrance", "designs", "motifs" }) : "%^C243%^The entrance to Cacia's temple is an imposing arched doorway, flanked on either side by columns expertly crafted from %^C240%^dark%^C243%^, %^C240%^lu%^C241%^st%^C242%^ro%^C241%^us %^C242%^st%^C241%^o%^C242%^ne%^C243%^. Each column is adorned with %^C245%^intricate patterns%^C243%^ and %^C245%^decorative motifs%^C243%^ that allude to the temple's %^C090%^hedonistic nature%^C243%^, promising %^C189%^sensual pleasure%^C243%^ and %^C189%^indulgence%^C243%^ to all who enter. The delicate details and decorative motifs tempt you with their suggestive designs, you can't help but feel a sense of fascination and intrigue, wondering what secrets and pleasures the temple holds within. The columns seem to beckon you closer, inviting you to indulge in the delights that await within the temple walls.%^CRST%^",
		({ "runes", "stones", "black stones", "symbols" }) : "%^C240%^Each stone is etched with %^C243%^intricate runes%^C240%^ that suggest an ancient language or script. The symbols on the stones are arranged in intricate patterns, with each one appearing to tell a story or convey a message. Some of the runes depict scenes of pleasure and indulgence, while others seem to depict warnings or admonishments. The longer you study the runes, the more you begin to feel a sense of unease and fascination, as if the stones themselves are alive and aware.%^CRST%^",
        ({ "yniam", "plains", "yniam plains" }) : "%^RESET%^%^CRST%^%^C156%^The land spreads out in %^C046%^ge%^C118%^nt%^C154%^le %^C046%^sl%^C118%^op%^C154%^es%^RESET%^%^C156%^, covered in tall grasses and a spattering of %^C065%^low brush%^C156%^.%^CRST%^",
        ]));
    set_exits(([
        "north" : ROOMS"outpost_hub",
        "temple" : "/d/magic/temples/cacia/cacia",
        ]));
}

