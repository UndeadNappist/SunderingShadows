//Kreysneothosies Weapon Spell

#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create(){
    ::create();
    set_name("%^YELLOW%^R%^RESET%^%^ORANGE%^i%^BOLD%^g%^CYAN%^h%^ORANGE%^te%^CYAN%^o%^RESET%^%^ORANGE%^u%^BOLD%^s Vi%^RESET%^%^ORANGE%^n%^BOLD%^%^CYAN%^d%^ORANGE%^i%^RESET%^%^ORANGE%^c%^BOLD%^%^CYAN%^a%^ORANGE%^t%^RESET%^%^ORANGE%^i%^BOLD%^on%^RESET%^");
    set_short("%^YELLOW%^A %^RED%^w%^ORANGE%^ick%^RED%^e%^ORANGE%^d %^RESET%^%^ORANGE%^g%^BOLD%^o%^RESET%^%^ORANGE%^l%^BOLD%^d%^RESET%^%^ORANGE%^e%^BOLD%^n %^CYAN%^kh%^ORANGE%^o%^RESET%^%^ORANGE%^p%^BOLD%^e%^CYAN%^s%^ORANGE%^h%^RESET%^");
    set_id(({"khopesh", "sword", "weapon", "vindication", "righteous vindication", "Righteous Vindication"}));
    set_long("%^YELLOW%^Crafted from fever %^BLACK%^i%^RESET%^r%^BOLD%^%^BLACK%^o%^RESET%^n %^YELLOW%^the blade of this khopesh curves and is sharpened on both sides, making it a vicious weapon. The fever iron has been etched with images of %^RESET%^%^RED%^e%^ORANGE%^a%^BOLD%^g%^WHITE%^l%^RED%^e%^RESET%^%^ORANGE%^s %^BOLD%^interspersed with wheeling %^RESET%^%^ORANGE%^h%^RED%^awk%^ORANGE%^s, %^BOLD%^all of which have been filled with %^RESET%^%^RED%^m%^BOLD%^ol%^RESET%^%^RED%^t%^BOLD%^en %^ORANGE%^gold to make them glitter as the blade whirls through the air. The handle has been wrapped in %^BLACK%^black %^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^at%^BOLD%^%^BLACK%^h%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^r %^ORANGE%^and topped with a %^RED%^sca%^MAGENTA%^rl%^RED%^et%^RESET%^%^YELLOW%^ cord, the ends of which are left to dangle and support %^BLACK%^s%^WHITE%^pi%^BLACK%^k%^WHITE%^e%^BLACK%^d %^ORANGE%^spheres of fever iron that are used to rake the skin of an opponent.%^RESET%^");
    set_value(0);
    set_damage_type("slashing");
    set_hit((:this_object(),"hit_func":));
}

int hit_func(object targ){
    object player = environment(this_object());
    
    targ = player->query_current_attacker();
    if(!objectp(player)) return 1;
    if(!objectp(targ)) return 1;

    if(!random(10)){
        tell_object(player, "%^ORANGE%^The spheres of fever iron tear into %^RED%^"+targ->query_cap_name()+"%^ORANGE%^ as you whirl the khopesh against %^RED%^"+targ->query_possessive()+"%^ORANGE%^ skin!%^RESET%^");
        tell_object(targ, "%^ORANGE%^As %^CYAN%^"+player->query_cap_name()+" %^ORANGE%^slices into you with %^CYAN%^"+player->query_possessive()+" %^ORANGE%^khopesh, small spheres of fever iron tear into your flesh as well!%^RESET%^");
        tell_room(environment(player), "%^CYAN%^"+player->query_cap_name()+"%^ORANGE%^ slices %^CYAN%^"+player->query_possessive()+"%^ORANGE%^ khopesh deeply into%^RED%^ "+targ->query_cap_name()+"%^ORANGE%^, the movement causing small spheres of fever iron to gash %^RED%^"+targ->query_objective()+"%^ORANGE%^ as well!%^RESET%^", ({player, targ}));

        return random(4)+8;
    }
}

