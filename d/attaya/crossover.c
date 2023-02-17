
#include <std.h>
#define MESSAGE ({"%^BOLD%^%^BLACK%^Thick smoke drops like a veil over you!",\
    "It stings your eyes!",\
    "%^RED%^The heat is tremendous.",\
    "%^BOLD%^The phantom vessel passes through an exceptionally thick cloud of smoke.",\
    "%^BOLD%^%^RED%^Suddenly the smoke clears for an instant and you behold a sight unlike anything that you have ever seen!",\
    "Before you stretches a churning molten world where everything around you is moving.  The lava swirls and churns everywhere and belches black smoke into the air.",\
    "%^BOLD%^%^RED%^A tremendous column of flame shoots upwards from nearby and you dodge a rain of flaming debris",\
    "%^RESET%^Riptide peers back at you for an instant, perhaps to see that you are still there.",\
    "%^BOLD%^%^BLACK%^The vessel sails once again into a thick cloud of smoke, and once again the world around you is shrouded.",\
    "%^RED%^Fire leaps at you from the darkness of the smoke.",\
    "%^RESET%^You feel the vessel lunge forward!",\
    "%^CYAN%^Riptide screams and grasps his chest!",\
    "%^BOLD%^%^RED%^You duck just in time as a tremendous cloud of flame passes through the vessel",\
    "%^RESET%^You begin to long for fresh air!",\
    "%^BOLD%^%^RED%^Once again the vessel clears the smoke and you see several tornadoes of fire dancing in the distance over the turbulent sea of molten lava.",\
    "One of the tornadoes passes the vessel, almost close enough to reach out into it.",\
    "%^RESET%^The landmass before you begins to take shape.",\
    "A dock emerges from the smoke and fire.",\
    "As you draw closer, a tremendous cliff becomes visible and reaches into the sky to unseen heights.",\
    "%^BOLD%^You have arrived...",\
    })

inherit ROOM;

int flag;

void create(){
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("no attack", 1);
    set_property("no teleport", 1);
	set_short("%^RESET%^%^CRST%^%^C059%^T%^C124%^h%^C059%^e d%^C124%^o%^C160%^w%^C124%^n%^C059%^war%^C124%^d %^C160%^s%^C124%^l%^C059%^id%^C124%^e%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C124%^You are sailing across the %^C214%^R%^C208%^iv%^C202%^er of %^C208%^F%^C214%^l%^C208%^a%^C202%^m%^C208%^e %^RESET%^%^C124%^aboard a magical vessel. The heat is nearly unbearable. Tongues of flame leap high into the air, occasionally making glowing arches of fire as the river of molten metals displays its power.\n\n%^RESET%^%^CRST%^%^C027%^The phantom, %^C051%^R%^C045%^ip%^C039%^ti%^C033%^de%^RESET%^%^C027%^, stands motionless on the bow of the boat, his hands locked around a %^C214%^s%^C220%^p%^C226%^he%^C220%^r%^C214%^e of %^C214%^p%^C220%^ur%^C226%^e ene%^C220%^rg%^C214%^y %^RESET%^%^C027%^in front of him. He appears to control the vessel with mere thought.%^CRST%^\n");
    set_smell("default", "The incredible heat and overpowering tang of molten metals forces you to cover your nose.");
    set_listen("default", "Currents of flame crackle and pop around you.");
	set_exits(([]));
    set_items(([
        "river" : "%^RESET%^%^CRST%^%^C124%^Molten metals and lava swirl and rush around you beneath the phantom vessel.%^CRST%^",
        ({"boat", "vessel", "ship"}) : "%^RESET%^%^CRST%^%^C027%^The phantom vessel is a small sailing ship that you can see right through! It floats just above the river of magma!%^CRST%^",
        "sphere" : "%^RESET%^%^CRST%^%^C214%^The glowing sphere of energy is that point where Riptide commands the vessel!%^CRST%^",
        ]));
}

void reset(){
    ::reset();
    if(!present("riptide")) new("/d/attaya/mon/riptide2")->move(this_object());
}
	
void init(){
    if(this_player()->query_true_invis()){
        this_player()->move_player("/d/attaya/cliffdock");
        return;
    }
	write("%^BOLD%^%^YELLOW%^"+MESSAGE[0]);
	call_out("fire", 1, this_player(), 1);
}
	
void fire(object ob, int flag){
	if(ob->id("riptide")){ return; }
	if(flag < sizeof(MESSAGE)){
		tell_object(ob, "%^BOLD%^%^RED%^"+MESSAGE[flag]+"\n\n");
		flag++;
		call_out("fire", 8, ob, flag);
	}
	else ob->move_player("/d/attaya/cliffdock");
}
	
