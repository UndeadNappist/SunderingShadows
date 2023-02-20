//updated to fix bug when no enchantment is set with activation - Yves 2/26/18
#include <std.h>
inherit "/d/common/obj/armour/bracers";

int keeper;
object claw1,claw2;

void create(){
    ::create();
    set_name("shadowy bracers");
    set_short("%^RESET%^%^CRST%^%^C062%^T%^C061%^w%^C060%^i%^C059%^lig%^C060%^h%^C061%^t %^C060%^C%^C059%^u%^C060%^f%^C061%^f%^C062%^s%^CRST%^");
    set_obvious_short("%^RESET%^%^CRST%^%^C062%^s%^C061%^h%^C060%^a%^C059%^do%^C060%^w%^C061%^y b%^C060%^r%^C059%^ac%^C060%^e%^C061%^r%^C062%^s%^CRST%^");
    set_id(({ "bracer", "bracers", "shadowy bracers", "cuffs", "twilight cuffs" }));
    set_long("%^RESET%^%^CRST%^%^C021%^These matching pair of bracers seem almost surreal, made of nothing but %^C243%^w%^C244%^i%^C245%^s%^C246%^p%^C247%^s %^C246%^o%^C245%^f %^C244%^s%^C243%^h%^C244%^a%^C245%^d%^C246%^o%^C247%^w%^RESET%^%^C020%^. You can see right through the %^C062%^d%^C061%^u%^C060%^s%^C059%^ky h%^C060%^a%^C061%^z%^C062%^e %^RESET%^%^C020%^of their form, leaving it to the imagination how they were even crafted in the first place. The only way to tell where the bracers end and the air begins, is a fine shifting line of %^C142%^g%^C143%^ol%^C142%^d %^RESET%^%^C019%^around either edge, that %^C142%^gl%^C143%^it%^C142%^te%^C143%^rs %^C019%^and %^C142%^sp%^C143%^ar%^C142%^kl%^C143%^es %^RESET%^%^C019%^with a life of its own.%^CRST%^\n");
    
    set_lore("%^RESET%^%^CRST%^%^C060%^Such intriguing bracers as these are renowned as never having been crafted, but instead torn forcibly from the stuff of the plane of Shadows. They were said to be the possession of the near mythical creature Grimtooth, part drow and part wolfwere, an assassin of legendary renown. Feared universally across the realms, his time upon the surface left a swathe of dead elven bodies in his wake, until abruptly he vanished from all tales and knowledge. No one knows where he has disappeared to, or if someone actually managed to bring his unnatural life to a final closing. More importantly to you, perhaps, were the tales that he could %^C226%^will the bracers%^RESET%^%^C060%^ to activate with a thought, bringing forth lethal claws of shadow that could cut through any known substance.%^CRST%^\n");
    set_property("lore difficulty", 30);
    
    set_property("enchantment", 6);
    set_value(1025);
    
    set_wear((:TO,"check":));
    set_remove((:TO,"remove_fun":));
    set_struck((:TO,"struck_fun":));
    keeper = 0;
}

int is_metal(){ return 0; }

void init(){
    object player, holder;
    ::init();
    if(!objectp(player = this_player())) return;
    if(!objectp(holder = environment(this_object()))) return;
    if(player != holder) return;
    if(interactive(player) && !avatarp(player)) set_size(player->query_size());
    add_action("activate_fun", "will");
}

int check(){
    object player;
    ::check();
    if((player = environment(this_object()))->query_highest_level() < 30){
        tell_object(player, "%^RESET%^%^CRST%^%^C059%^You haven't the experience to use such a powerful item.%^CRST%^");
        return 0;
    }
    tell_object(player, "%^RESET%^%^CRST%^%^C019%^You slide the %^C062%^s%^C061%^h%^C060%^a%^C059%^do%^C060%^w%^C061%^y b%^C060%^r%^C059%^ac%^C060%^e%^C061%^r%^C062%^s %^RESET%^%^C019%^over your forearms, and they meld perfectly against your skin.%^CRST%^");
    tell_room(environment(player), "%^RESET%^%^CRST%^%^C019%^The %^C062%^s%^C061%^h%^C060%^a%^C059%^do%^C060%^w%^C061%^y b%^C060%^r%^C059%^ac%^C060%^e%^C061%^r%^C062%^s %^RESET%^%^C019%^meld perfectly against "+player->query_cap_name()+"%^RESET%^%^CRST%^%^C019%^'s forearms.%^CRST%^", player);
    return 1;
}

int remove_fun(){
    object player = environment(this_object());
    
    if(!keeper){
        tell_object(player, "%^RESET%^%^CRST%^%^C019%^The %^C062%^d%^C061%^u%^C060%^s%^C059%^k%^C060%^y %^C061%^b%^C060%^r%^C059%^ac%^C060%^e%^C061%^r%^C062%^s %^RESET%^%^C019%^slide loose from your forearms.%^CRST%^");
        tell_room(environment(player), "%^RESET%^%^CRST%^%^C019%^The %^C062%^d%^C061%^u%^C060%^s%^C059%^k%^C060%^y %^C061%^b%^C060%^r%^C059%^ac%^C060%^e%^C061%^r%^C062%^s %^RESET%^%^C019%^slide loose from "+player->query_cap_name()+"%^RESET%^%^CRST%^%^C019%^'s forearms.%^CRST%^", player);
    }
    else{
        keeper = 0;
        tell_object(player, "%^RESET%^%^CRST%^%^C019%^The %^C062%^s%^C061%^h%^C060%^a%^C059%^do%^C060%^w%^C061%^y %^C060%^c%^C059%^l%^C060%^a%^C061%^w%^C062%^s %^RESET%^%^C019%^disappear again as you remove the bracers.%^CRST%^");
        tell_room(environment(player), "%^RESET%^%^CRST%^%^C019%^The %^C062%^s%^C061%^h%^C060%^a%^C059%^do%^C060%^w%^C061%^y %^C060%^c%^C059%^l%^C060%^a%^C061%^w%^C062%^s %^RESET%^%^C019%^disappear as "+player->query_cap_name()+"%^RESET%^%^CRST%^%^C019%^ removes the bracers.%^CRST%^", player);
        if(objectp(claw1)) claw1->__ActuallyUnwield();
    }
    return 1;
}

int activate_fun(string str){
    object bracers, player, room, ob, *names;
    int i, power;
    
    if(!str){
        notify_fail("Will what?\n");
        return 0;
    }
    if(str != "bracers" && str != "the bracers"){
        notify_fail("Nothing happens.\n");
        return 0;
    }
    if(!(bracers = this_object())->query_worn()){
        notify_fail("You feel you should be wearing them before you try that.\n");
        return 0;
    }
    if((player = environment(bracers))->query_lowest_level() < 30){
        notify_fail("Nothing happens.");
        return 0;
    }
    if(keeper > 0){
        notify_fail("You sense that they are already active.");
        return 0;
    }
    if(sizeof(player->query_wielded()) > 0){
        notify_fail("You feel the need to empty your hands first...");
        return 0;
    }
    
    tell_object(player, "%^RESET%^%^CRST%^%^C019%^You will the bracers to activate, and two %^C243%^c%^C245%^l%^C247%^a%^C245%^w%^C243%^s %^RESET%^%^C019%^of %^C062%^p%^C061%^u%^C060%^r%^C059%^e %^C060%^s%^C059%^ha%^C060%^d%^C061%^o%^C062%^w %^RESET%^%^C019%^spring forth over the top of your hands!%^CRST%^");
    tell_room(room, "%^RESET%^%^CRST%^%^C019%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C019%^ concentrates, and two %^C243%^c%^C245%^l%^C247%^a%^C245%^w%^C243%^s %^RESET%^%^C019%^of %^C062%^p%^C061%^u%^C060%^r%^C059%^e %^C060%^s%^C059%^ha%^C060%^d%^C061%^o%^C062%^w %^RESET%^%^C019%^spring forth over the top of "+player->query_possessive()+" hands!%^CRST%^", player);
    
    if((power = (player->query_level() - 3) / 5) > 10) power = 10;
    
    claw1 = new("/d/dagger/marsh/tower/obj/shadowclaws.c");
    claw1->move(player);
    claw1->remove_property("enchantment");
    claw1->set_property("enchantment", power);
    if(bracers->query_identified()){
        names = bracers->query_identified();
        for(i=0;i<sizeof(names);i++){
            claw1->add_identified(names[i]);
        }
    }
    player->force_me("wield shadowclaw");
    
    claw2 = new("/d/dagger/marsh/tower/obj/shadowclaws.c");
    claw2->move(player);
    claw2->remove_property("enchantment");
    claw2->set_property("enchantment", power);
    if(bracers->query_identified()){
        names = bracers->query_identified();
        for(i=0;i<sizeof(names);i++){
            claw2->add_identified(names[i]);
        }
    }
    player->force_me("wield shadowclaw");
    
    claw1->set_claw(claw2);
    claw2->set_claw(claw1);
    claw1->set_bracer(bracers);
    claw2->set_bracer(bracers);
    keeper = 1;
    return 1;
}

void do_reset(){ keeper = 0; }
int query_status(){ return keeper; }

int struck_fun(int damage, object what, object target){
    object player;
    
    if(!random(2)){
        player = environment(this_object());
        tell_object(player, "%^RESET%^%^CRST%^%^C019%^The %^C062%^s%^C061%^h%^C060%^a%^C059%^do%^C060%^w%^C061%^y b%^C060%^r%^C059%^ac%^C060%^e%^C061%^r%^C062%^s %^RESET%^%^C019%^seem to solidify, just enough to harmlessly deflect "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C019%^'s attack!%^CRST%^");
        tell_object(target, "%^RESET%^%^CRST%^%^C019%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C019%^'s %^C062%^s%^C061%^h%^C060%^a%^C059%^do%^C060%^w%^C061%^y b%^C060%^r%^C059%^ac%^C060%^e%^C061%^r%^C062%^s %^RESET%^%^C019%^seem to solidify, just enough to harmlessly deflect your attack!%^CRST%^");
        tell_room(environment(player), "%^RESET%^%^CRST%^%^C019%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C019%^'s %^C062%^s%^C061%^h%^C060%^a%^C059%^do%^C060%^w%^C061%^y b%^C060%^r%^C059%^ac%^C060%^e%^C061%^r%^C062%^s %^RESET%^%^C019%^seem to solidify, just enough to harmlessly deflect "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C019%^'s attack!%^CRST%^", ({player, target}));
        return 0;
    }
    return damage;
}

