//loosely based of of spear of insanity coded by grazzt

#include <std.h>
#include "../deep_echo.h"

inherit "/d/common/obj/weapon/spear_lg";

int uses;

void create(){
    ::create();
    set_name("spear");
    set_id(({"spear", "longspear", "beauty kills", "beauty"}));
    set_short("%^RESET%^%^CRST%^%^C243%^B%^C247%^e%^C255%^a%^C243%^u%^C247%^t%^C255%^y %^C243%^K%^C247%^i%^C255%^l%^C243%^l%^C247%^s%^CRST%^");
	set_obvious_short("%^RESET%^%^CRST%^%^C059%^a %^C243%^r%^C247%^i%^C255%^b%^C243%^b%^C247%^o%^C255%^n%^C243%^-%^C247%^c%^C255%^o%^C243%^v%^C247%^e%^C255%^r%^C243%^e%^C247%^d %^RESET%^%^C059%^spear%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C059%^This weapon seems more like a fashion statement than a tool used for battle. It has a %^C255%^%^sp%^C252%^a%^C255%^rkl%^C252%^i%^C255%^n%^C252%^g %^C243%^s%^C247%^i%^C250%^lv%^C247%^e%^C243%^r %^C250%^r%^C244%^o%^C247%^s%^C250%^e%^RESET%^%^C059%^ for a tip. The rose is made flawlessly as if by someone with skill beyond a master craftsman. The shaft is completely covered by %^C243%^black %^C059%^and %^C255%^white %^RESET%^%^C059%^ribbons. They %^C243%^s%^C247%^p%^C255%^i%^C243%^r%^C247%^a%^C255%^l %^RESET%^%^C059%^up and down the shaft with seemingly no end. It is impossible to tell what wood the shaft is made of from because the ribbons fit so perfectly.%^CRST%^");
    set_lore("%^RESET%^%^CYAN%^It is said that before the Silence, there was a group of Sunites that worshipped her with a single-minded fervor. They were so obsessed with physical beauty that they often killed the ugly or poor, believing that the world must be cleansed of such heresy. Eventually, the group began to age and could not stand the thought of growing old, becoming that which they hated. Through mysterious profane rituals gifted to these cultists by an unknown benefactor, they infused their souls into a collection of fantastic masterwork weapons to carry on their quest through adventurers they deemed worthy. This spear is one such piece.%^RESET%^");
    set_property("lore difficulty", 19);
    set_value(1000);
    set_hit((: this_object(), "extra_hit":));
    set_wield((: this_object(), "extra_wield":));
    set_unwield((: this_object(), "extra_unwield" :));
    set_property("enchantment", 3);
    set_heart_beat(1);
    uses = random(75) + 10;
}

void sensey(){  //point out ugly ppl in room
    object *ppl, wieldy, loc;
    int i,cha;
    if(!objectp(wieldy = environment(this_object()))) return;
    if(!objectp(loc = environment(wieldy))) return;
    ppl = all_living(loc);
    for(i = 0; i < sizeof (ppl); i++){
        cha = ppl[i]->query_stats("charisma");
        if( cha < 8) tell_object(wieldy, "%^RESET%^%^CRST%^%^C196%^"+ppl[i]->query_cap_name()+"%^RESET%^%^CRST%^%^C124%^ is so %^C160%^ugly%^C124%^, the world would be better without them...%^CRST%^");
    }
}

void heart_beat(){
    int align, i, yy;
    object owner, env, obj, *inv;
	if(!objectp(owner = environment(this_object()))) return;
    if(!objectp(owner) && !living(owner)) return;
    env = environment(owner);
    if(!(this_object()->query_wielded())) return;
    else{
        if(obj = present("corpse",env)){
            tell_room(env,"%^RESET%^%^CRST%^%^C059%^"+owner->QCN+"%^RESET%^%^CRST%^%^C059%^'s spear lashes out at the corpse with %^C243%^r%^C247%^i%^C255%^b%^C243%^b%^C247%^o%^C255%^n%^C243%^s%^RESET%^%^C059%^, which wrap about the corpse completely.\n%^C245%^The corpse spasms as they tighten and shrink into nothing.%^CRST%^");
            if(owner->query_hp() < owner->query_max_hp()) owner->heal(random(10) + 10);
            uses = uses + random(2) + 1;
            obj->remove();
            return;
        }
    }

    if((int)owner->query_hp() < 50 && uses > 5){
        message("my_action","%^RESET%^%^CRST%^%^C092%^The spear shouts:%^RESET%^%^C255%^ You are bleeding all over me, stop it!%^CRST%^", owner);
        owner->heal(random(10) + 10);
        uses -= 5;
        return;
    }    
    else{
        yy = random(19)+1;
        if(!random(500)){
            switch(yy){
                case 1:
                    tell_object(owner, "%^RESET%^%^CRST%^%^C092%^The spear tells you:%^RESET%^%^C255%^ Look at what you are wearing, is it okay?%^CRST%^");
                    break;
                case 2:
                    tell_object(owner, "%^RESET%^%^CRST%^%^C092%^The spear tells you:%^RESET%^%^C255%^ Are you dressed properly for this?%^CRST%^");
                    break;
                case 3:
                    tell_object(owner, "%^RESET%^%^CRST%^%^C092%^The spear tells you:%^RESET%^%^C255%^ If we see something ugly, destroy it.%^CRST%^");
                    break;
                case 4:
                    tell_object(owner, "%^RESET%^%^CRST%^%^C092%^The spear tells you:%^RESET%^%^C255%^ You should always dress in black and white that way we can match.%^CRST%^");
                    break;
                case 5:
                    tell_object(owner, "%^RESET%^%^CRST%^%^C092%^The spear tells you:%^RESET%^%^C255%^ We must make this world beautiful through any means, understand?!%^CRST%^");
                    break;
                case 6:
                    tell_object(owner, "%^RESET%^%^CRST%^%^C092%^The spear tells you:%^RESET%^%^C255%^ We hate ugly people, they should just disappear!%^CRST%^");
                    break;
                case 7:
                    tell_object(owner, "%^RESET%^%^CRST%^%^C092%^The spear tells you:%^RESET%^%^C255%^ It is important to keep oneself clean... more importantly, to keep ME clean.%^CRST%^");
                    break;
                case 8:
                    tell_object(owner, "%^RESET%^%^CRST%^%^C092%^The spear tells you:%^RESET%^%^C255%^ By the power of Sune we will recreate this world!%^CRST%^");
                    break;
                case 9:
                    tell_object(owner, "%^RESET%^%^CRST%^%^C092%^^The spear tells you:%^RESET%^%^C255%^ If you forsake our mission, I'll kill you.%^CRST%^");
                    break;
                case 10:
                    if((int)owner->query_hp() < 50) tell_object(owner, "%^RESET%^%^CRST%^%^C092%^The spear tells you:%^RESET%^%^C255%^ You should take better care of yourself. There is nothing beautiful about being covered in scars.%^CRST%^");
                    else tell_object(owner,"%^RESET%^%^CRST%^%^C092%^The spear tells you:%^RESET%^%^C255%^ We make a good team, just do NOT forget our mission of love and beauty.%^CRST%^");
                    break;
                case 11:
                    tell_object(owner, "%^RESET%^%^CRST%^%^C092%^The spear tells you:%^RESET%^%^C255%^ If we miss, it is your fault, not mine.%^CRST%^");
                    break;
                case 12:
                    tell_object(owner, "%^RESET%^%^CRST%^%^C092%^The spear tells you:%^RESET%^%^C255%^ Our mission is holy, we must not stray.%^CRST%^");
                    break;
                case 13:
                    tell_object(owner, "%^RESET%^%^CRST%^%^C092%^The spear tells you:%^RESET%^%^C255%^ I think we should kill those of neutrality, the passion of both good and evil are a wonderful thing.%^CRST%^");
                    break;
                case 14:
                    tell_object(owner, "%^RESET%^%^CRST%^%^C059%^You feel the need to adjust your clothing.%^CRST%^");
                    break;
                case 15:
                    tell_object(owner, "%^RESET%^%^CRST%^%^C059%^Expensive dining sounds good right now.%^CRST%^");
                    break;
                case 16:
                    tell_object(owner, "%^RESET%^%^CRST%^%^C059%^Images of a ball with dancers fill your mind.%^CRST%^");
                    break;
                case 17:
                    tell_object(owner, "%^RESET%^%^CRST%^%^C092%^The spear tells you:%^RESET%^%^C255%^ Sometimes, love hurts.%^CRST%^");
                    break;
                case 18:
                    tell_object(owner, "%^RESET%^%^CRST%^%^C092%^The spear tells you:%^RESET%^%^C255%^ What is with your clothing, are you sure this is proper?%^CRST%^");
                    break;
                case 19:
                    tell_object(owner,"%^RESET%^%^CRST%^%^C092%^The spear tells you:%^RESET%^%^C255%^  The ugly things of this world are the enemy... we must eliminate them.%^CRST%^");
                    break;
            }
        }
        return;
    }
    
    if(!random(100)) sensey();
    return;
}

int extra_hit(object target){
    int dam, cha, num;
    object ribbon, player, room;
    
    if(!objectp(target)) return 1;
	if(!objectp(player = environment(this_object()))) return 1;
	cha = player->query_stats("charisma");
    room = environment(player);
    
    if(uses < 0){
        tell_object(player, "%^RESET%^%^CRST%^%^C124%^The spear seems exhausted.%^CRST%^");
	    return 0;
    }
    
    if(random(3)) return 0;
    switch(random(4)){
        case 0:
            tell_object(player, "%^RESET%^%^CRST%^%^C090%^A single %^C243%^r%^C247%^i%^C255%^b%^C243%^b%^C247%^o%^C255%^n %^RESET%^%^C090%^unwinds from your spear and wraps itself around "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C090%^, %^C059%^knocking%^C090%^ "+target->query_objective()+" down.%^CRST%^");
            tell_object(target, "%^RESET%^%^CRST%^%^C090%^A single %^C243%^r%^C247%^i%^C255%^b%^C243%^b%^C247%^o%^C255%^n %^RESET%^%^C090%^unwinds from "+player->query_cap_name()+"%^RESET%^%^CRST%^%^C090%^'s spear and wraps itself around you, %^C059%^knocking%^C090%^ you down.%^CRST%^");
            tell_room(room, "%^RESET%^%^CRST%^%^C090%^A single %^C243%^r%^C247%^i%^C255%^b%^C243%^b%^C247%^o%^C255%^n %^RESET%^%^C090%^unwinds from "+player->query_cap_name()+"%^RESET%^%^CRST%^%^C090%^'s spear and wraps itself around "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C090%^, %^C059%^knocking%^C090%^ "+target->query_objective()+" down.%^CRST%^", ({player, target}));
            
            target->set_tripped(1, "%^RESET%^%^CRST%^%^C124%^You try to get up, but the world is spinning.%^RESET%^");
            target->cause_typed_damage(target, 0, roll_dice(1, 10), "bludgeoning");
            uses -= random(3) + 1;
            return 1;
        case 1..2:
            tell_object(player, "%^RESET%^%^CRST%^%^C096%^You %^C212%^gr%^C206%^ac%^C200%^ef%^C206%^ul%^C212%^ly %^C096%^lunge forward, %^C243%^r%^C247%^i%^C255%^b%^C243%^b%^C247%^o%^C255%^n%^C243%^s%^RESET%^%^C096%^ from your spear snaking out and %^C124%^impaling %^C096%^"+target->query_cap_name()+"%^RESET%^%^CRST%^%^C096%^!%^CRST%^");
            tell_object(target, "%^RESET%^%^CRST%^%^C096%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C096%^ %^C212%^gr%^C206%^ac%^C200%^ef%^C206%^ul%^C212%^ly %^C096%^lunges forward, %^C243%^r%^C247%^i%^C255%^b%^C243%^b%^C247%^o%^C255%^n%^C243%^s%^RESET%^%^C096%^ from "+player->query_possessive()+" spear snaking out and impaling you!%^CRST%^");
            tell_room(room, "%^RESET%^%^CRST%^%^C096%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C096%^ %^C212%^gr%^C206%^ac%^C200%^ef%^C206%^ul%^C212%^ly %^C096%^lunges forward, %^C243%^r%^C247%^i%^C255%^b%^C243%^b%^C247%^o%^C255%^n%^C243%^s%^RESET%^%^C096%^ from "+player->query_possessive()+" spear snaking out and impaling "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C096%^!%^CRST%^", ({player, target}));
            
            num = cha - 14; // extra dam for good cha
            dam = roll_dice(num, 8);
            return dam;
        case 3:
            if(!random(2)){
                tell_object(player, "%^RESET%^%^CRST%^%^C092%^The spear tells you: %^RESET%^%^C255%^Looks like you need my help.\n%^RESET%^%^CRST%^%^C098%^A swirl of %^C243%^r%^C247%^i%^C255%^b%^C243%^b%^C247%^o%^C255%^n%^C243%^s%^RESET%^%^C098%^ erupt from the spear, forming a dress that comes to life!%^CRST%^");
                tell_room(room, "%^RESET%^%^CRST%^%^C243%^R%^C247%^i%^C255%^b%^C243%^b%^C247%^o%^C255%^n%^C243%^s%^RESET%^%^C098%^ erupt from the tip of "+player->query_cap_name()+"%^RESET%^%^CRST%^%^C098%^'s spear, swirling about to form a dress that comes to life!%^CRST%^", player);
                
                ribbon = new(MOBS"ribbon");
                ribbon ->move(room);
                player->add_protector(ribbon);
                player->add_follower(ribbon);
                ribbon->force_me("kill "+target->query_name());
                
                uses -= 3;
            }
        return dam;
    }
}

int extra_wield(){ // no ugly wielders
    object player;
    int cha;
    
    if(!objectp(player = environment(this_object()))) return 0;
    cha = ETO->query_stats("charisma");
    if(cha > 15){
        tell_object(player, "%^RESET%^%^CRST%^%^C096%^As you wield the spear, you begin to think highly of yourself.%^CRST%^");
        tell_room(environment(player), "%^RESET%^%^CRST%^%^C096%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C096%^ wields a spear and gets a distant look in "+player->query_possessive()+" eyes.\n%^RESET%^%^CRST%^%^C90%^Strangely, "+player->query_subjective()+" appears more noble of bearing.%^CRST%^", player);
    }
    else{
        tell_object(player, "%^RESET%^%^CRST%^%^C196%^Your whole body seems to seize and a sense of disgust at your own ugliness washes over you.%^CRST%^");
        tell_room(environment(player), "%^RESET%^%^CRST%^%^C196%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C196%^ holds the spear but jerks violently as ribbons lash out from it, wrapping about tightly!%^CRST%^");
        TP->set_paralyzed(10, "%^RESET%^%^CRST%^%^C124%^Your head is pounding.%^CRST%^");
        TP->set_bound(50, "%^RESET%^%^CRST%^%^C243%^Ribbons bind you fast.%^CRST%^");
        return 0;
    }
    return 1;
}

int extra_unwield(){
    object player;
    player = environment(this_object());
    
    if(!objectp(player)) return 0;
    tell_object(player, "%^RESET%^%^CRST%^%^C092%^The spear tells you:%^RESET%^%^C255%^ Grrr, you better not forsake our mission. I'm still watching you.%^CRST%^");
    return 1;
}

