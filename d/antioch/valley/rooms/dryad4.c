#include <std.h>
#include "../valley.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(GRASSLANDS);
   set_travel(FOOT_PATH);
	set_property("outdoors",3);
	set_property("light",3);
	set_short("%^BOLD%^A %^RESET%^%^BLUE%^weeping%^BOLD%^ %^WHITE%^willow");
	set_long(
	"%^GREEN%^A very large %^BLUE%^weeping willow%^GREEN%^ is growing here. It reaches"+
	" high into the air so that you have to crane your neck"+
	" to see the top of it. The leaves are %^CYAN%^slender%^GREEN%^ and"+
	" %^BOLD%^%^BLUE%^plentiful%^RESET%^%^GREEN%^, falling down to create an umbrella under"+
	" the tree, keeping everything else out. The branches"+
	" that you can see through the leaves look quite thick"+
	" and the wood is a %^ORANGE%^deep brown%^GREEN%^. The wind blows against"+
	" the leaves and they sway with the breeze, unable to"+
	" resist even such a slight resistance.\n"
	);
	set("night long",
	"%^GREEN%^The %^BLUE%^weeping willow%^GREEN%^ almost seems to be dancing in the"+
	" wind. %^BOLD%^%^WHITE%^Moonlight%^RESET%^%^GREEN%^ reflects off of the leaves and gives"+
	" the tree the appearance of having a %^BOLD%^%^WHITE%^silver%^RESET%^%^GREEN%^ aura. The"+
	" wind blows the leaves this way and that, which is what"+
	" causes the appearance of dancing, but even knowing"+
	" that doesn't dispell the illusion. The leaves of the"+
        " willow are long and slender, they droop down and veil"+
	" the tree, almost like a lady's hair vieling her face"+
	" while she weeps. From the size of the tree it has"+
	" easily stood here for a century, quiet and proud. Several"
	" %^YELLOW%^fireflies%^RESET%^%^GREEN%^ are floating around in the leaves of the tree,"+
	" making it seem to %^WHITE%^%^BOLD%^glow%^RESET%^%^GREEN%^ from within.\n"
	);
	set_smell("default",
	"The wind blows the faint scent of wet sand to you."
	);
	set_listen("default",
	"If you listen closely, you can almost hear the weeping"+
	" of the willow."
	);
	set_items( ([
	({"willow","weeping willow","tree","willow tree"}) : "%^BLUE%^This is a very old,"+
	"tall willow that is still vibrant with life and will"+
	" probably remain here for centuries to come.",
	"leaves" : "%^BLUE%^%^BOLD%^These leaves are very thin and slender, easily"+
	" bending with the wind.",
	"branches" : "%^BOLD%^The branches that you can see are quite thick.",
	"trunk" : "%^ORANGE%^You can't see much of the trunk from here, but"+
	" it looks very thick around.",
	"fireflies" : "%^YELLOW%^The fireflies are buzzing around in the"+
	" leaves of the tree, giving off a gentle glow.",
	]) );
	set_exits( ([
	"north" : ROOMS+"g66",
	"south" : ROOMS+"g70",
	"west" : ROOMS+"g67",
	"east" : ROOMS+"g64",
	]) );
}

void init()
{
	::init();
	add_action("climb", "climb");
    add_action("sprinkle_fun", "sprinkle");
}

int climb(string str)
{
	if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed() || TP->query_tripped()) {
		TP->send_paralyzed_message("info",TP);
		return 1;
	}
	if(!str) {
		write("Climb what?");
		return 1;
	}
	if(str != "tree" && str != "willow") {
		write("The only thing to climb here is a tree.");
		return 1;
	}
	else {
		write("%^BOLD%^You walk beneath the branches of the"+
		" willow and begin to climb up the trunk.");
		say(
		"%^BOLD%^"+TP->query_cap_name()+" disappears beneath"+
		" the leaves of the willow tree.");
		this_player()->move_player(ROOMS+"willow");
		return 1;
	}
}

int sprinkle_fun(string str){
    object player, room, blood;
    int power;
    player = this_player();
    room = environment(player);
    power = max(({ player->query_level() / 10, 1 }));
    
    if(!str) return 0;
    if(str != "blood"){
        tell_object(player, "You could try to <sprinkle blood>.");
        return 0;
    }
    if(!objectp(blood = present("unicorn_bait", player))){
        tell_object(player, "You don't have the proper bait.");
        return 0;
    }
    
    tell_object(player, "%^RESET%^%^CRST%^%^C059%^As you open the vial and sprinkle the %^C196%^bl%^C124%^o%^C196%^o%^C124%^d %^RESET%^%^C059%^about the base of the %^C108%^willow%^C059%^, a breeze picks up and sends all the %^C130%^bra%^C136%^nc%^C130%^h%^C136%^e%^C130%^s %^RESET%^%^C059%^and %^C040%^le%^C046%^av%^C040%^e%^C046%^s %^RESET%^%^C059%^fluttering...%^CRST%^");
    tell_room(room, "%^RESET%^%^CRST%^%^C059%^As "+player->query_cap_name()+"%^RESET%^%^CRST%^%^C059%^ opens the vial and sprinkles the %^C196%^bl%^C124%^o%^C196%^o%^C124%^d %^RESET%^%^C059%^about the base of the %^C108%^willow%^C059%^, a breeze picks up and sends all the %^C130%^bra%^C136%^nc%^C130%^h%^C136%^e%^C130%^s %^RESET%^%^C059%^and %^C040%^le%^C046%^av%^C040%^e%^C046%^s %^RESET%^%^C059%^fluttering...%^CRST%^", player);
    blood->remove();
    call_out("summon_fun", 3, room, power);
    return 1;
}

void summon_fun(object room, int power){
    object unicorn;
    
    tell_room(room, "\n%^RESET%^%^CRST%^%^C255%^With a %^C196%^th%^C124%^un%^C196%^de%^C124%^ri%^C196%^ng %^RESET%^%^C255%^of %^C059%^hooves%^C255%^, a %^RESET%^%^C214%^u%^C220%^n%^C226%^ico%^C220%^r%^C214%^n %^RESET%^%^C255%^comes charging into view!%^CRST%^");
    unicorn = new("/d/dagger/islands/wailing_isle/mon/unicorn");
    unicorn->move(room);
    unicorn->set_powerlevel(power);
    return;
}

