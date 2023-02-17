#include <std.h>
inherit MONSTER;

create(){
    ::create();
    set_name("riptide");
    set_id(({ "riptide", "boatman" }));
    set_gender("male");
    set_short("%^RESET%^%^CRST%^%^C051%^R%^C045%^ip%^C039%^ti%^C033%^de %^C027%^the %^C051%^B%^C045%^oa%^C039%^tm%^C033%^an%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C021%^Ancient spirits slip aside to reveal Riptide, the mythical boatman of the River of Flame. It is his sole purpose to ferry travelers towards the distant shore, bound in service for reasons lost to the ages. Does he serve the %^C045%^Kinnesaruda%^C021%^, or is it %^C059%^revenge %^RESET%^%^C021%^that fuels him, allowing adventurers the chance to strike at the evil lurking there? It has been said that those that traverse the molten river seldom return.%^CRST%^");
    set_level( 30 );
    set_race("undead");
    set_body_type("humanoid");
    set_alignment( 7 );
    set_size( 2 );
    set_stats("intelligence", 25);
    set_stats("wisdom", 25);
    set_stats("strength", 24);
    set_stats("charisma", 25);
    set_stats("dexterity", 18);
    set_stats("constitution", 25);
    set_max_mp(500);
    set_spell_chance(99);
    set_spells(({
        "chill touch",
        "dispel magic",
        "magic missile",
        "freeze"
        }));
    set_mp(query_max_mp());
    set_hd(5, 1);
    set_max_hp(query_hp());
    set_exp(500);
    set_max_sp(query_hp());
    set_sp(query_max_sp());
    add_money("silver",random(1300));
    add_money("copper",random(20));
    set_emotes(5,({
        "%^RESET%^%^CRST%^%^C021%^Riptide offers a slow nod towards you...%^CRST%^",
        "%^RESET%^%^CRST%^%^C051%^Riptide whispers to you: %^RESET%^%^C027%^Simply %^C033%^motion %^C027%^to me and I shall assume the form of the mist and carry you to the Tower of the Black Dawn.%^CRST%^",
        "%^RESET%^%^CRST%^%^C051%^Riptide whispers to you: %^RESET%^%^C027%^Only death awaits you over there.%^CRST%^",
        "%^RESET%^%^CRST%^%^C021%^Riptide turns and peers out into the river of flames.%^CRST%^"
        }) ,0);
}

void init(){
    ::init();
    add_action("motion_riptide", "motion");
}

int motion_riptide(string str){
    object player = this_player();
    
    tell_object(player, "%^RESET%^%^CRST%^%^C021%^You motion to %^C051%^R%^C045%^ip%^C039%^ti%^C033%^de%^RESET%^%^C021%^ and a ghostly vessel materializes before you. The mist grows dense and you suddenly find yourself aboard as it begins its journey across the River of Flame.\n\n%^RESET%^%^C051%^R%^C045%^ip%^C039%^ti%^C033%^de%^RESET%^%^C021%^ turns to gaze at you eerily...%^CRST%^");
    tell_room(environment(player), "%^RESET%^%^CRST%^%^C021%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C021%^ motions to %^C051%^R%^C045%^ip%^C039%^ti%^C033%^de %^C027%^the %^C051%^B%^C045%^oa%^C039%^tm%^C033%^an%^RESET%^%^C021%^. The mist grows dense, clouding "+player->query_objective()+" from view... and appearing aboard a ghostly vessel that a materializes in the river, only to be consumed by the flames and vanish!%^CRST%^\n");
    this_player()->move_player("/d/attaya/crossover.c");
    return 1;
}

void catch_say(string str){
    if(!userp(this_player())) return;
    call_out("reply_fun", 1, str, this_player());
}

void reply_fun(string str, object player){
    if(!str) return;
    if(!objectp(player)) return;
    if((strsrch(str, "ello") != -1 ) || (strsrch(str, "Hi") != -1 ) || (strsrch(str, "reeting") != -1 ) || (strsrch(str, "eya") != -1 )){
        force_me("emoteat riptide %^RESET%^%^CRST%^%^C021%^$M inclines his head with a glacial movement.%^CRST%^");
        force_me("whisper "+player->query_name()+" %^RESET%^%^C027%^Simply %^C033%^motion %^C027%^to me and I shall assume the form of the mist and carry you to the Tower of the Black Dawn.%^CRST%^");
        return;
    }

    return;
}

