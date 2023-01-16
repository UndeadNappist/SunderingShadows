#include <std.h>
#include <namegen.h>
#include <daemons.h>

inherit MONSTER;

void create()
{
    ::create();
    make_me();
    set_body_type("human");
    set_class("fighter");
    set_class("mage");
    set("aggressive", 2);
    set_property("swarm", 0);
    set_hd(10, 0);
    set_alignment(5);
    set_class("mage");
    set_mlevel("mage", 10);
    set_guild_level("mage", 10);
    set_guild_level("fighter", 10);
    set_property("cast and attack", 1);
    set_spells(({"prismatic spray",}));
    set_spell_chance(50);
    set_property("no_random_treasure", 1);
}

void make_me(){
    string name;
    name = GENNAM(4,random(4)+1,);
    set_race("human");
    set_gender(random(2) ? "male" : "female");
    set_name(name);
    set_short("%^RESET%^%^CRST%^"+({"%^C021%^","%^C090%^","%^C124%^%^","%^C208%^"})[random(4)]+name+"%^RESET%^%^CRST%^%^C100%^, %^C144%^Col%^C101%^lec%^C100%^tor of %^C144%^L%^C101%^o%^C100%^st %^C144%^R%^C101%^el%^C100%^ics%^CRST%^");
    set_id(({name, lower_case(name), "questor", "collector", "Collector"}));
    set_long("%^RESET%^%^CRST%^%^C101%^"+name+" is a proprietor of lost artifacts in service to %^C255%^Kismet%^C101%^. Dressed in a simple white robe that lacks any style or elegance, "+this_object()->query_subjective()+" stands by quietly, keeping a careful watch over "+this_object()->query_possessive()+" surroundings.\n\n%^RESET%^%^C058%^You may wish to %^C255%^<read list>%^RESET%^%^C058%^ to see a sampling of the lost relics "+this_object()->query_objective()+" currently seeks, or you may %^C255%^<claim ITEMNAME>%^RESET%^%^C058%^ to be properly rewarded.\n%^CRST%^");
}

void thank(){
    string thanklist;
    thanklist = ({
        "I've waited a long time for this.",
        "Now this one... this one is special.",
        "Well done!",
        "It must have been quite an adventure finding this.",
        "Thank you!",
        "Thanks so much!",
        "This is wonderful. Truly exquisite!",
        "Ahh... priceless!",
        "Many thanks.",
        });
    tell_room(ETO,"%^RESET%^%^MAGENTA%^"+query_name()+" speaks with enthusiasm:%^RESET%^ "+thanklist[random(sizeof(thanklist))]);
}

void receive_given_item(object obj){
    tell_room(ETO,"%^RESET%^%^MAGENTA%^"+query_name()+" speaks in a kind voice:%^RESET%^ Try <claim>ing this instead.");
    force_me("drop "+obj->query_id()[0]);
}

/*void die(object ob){
    WORLD_EVENTS_D->kill_event("A rare opportunity");
    WORLD_EVENTS_D->inject_event((["A rare opportunity" : (["start message": "For the next two hours all experience gained will award an additional 10%!","event type" : "exp bonus", "length" : 120, "notification" : "10% Bonus Exp","event name" : "A rare opportunity", "modifier" : 10,"announce" : 1, "announce to" : "world" ]),]));
    ::die(ob);
}*/

