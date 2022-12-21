// Chernobog (12/19/22)
// Odachi of the Four Perils

#include <std.h>
#include "../defs.h"
#define HIT_INTERVAL 4

inherit "/d/common/obj/weapon/nodachi";

int counter, charges, special, opening, followup;
object last_target;

void create(){
    ::create();
    set_name("mottled steel odachi");
    set_id(({ "sword", "odachi" }));
    set_obvious_short("mottled steel odachi with a wrapped leather grip");
    set_short("Odachi of the Four Perils");
    set_long("This is a steel odachi. Maybe steel, maybe some kind of meteoric metal.");
    
    set_lore("%^RESET%^%^CYAN%^Some lore and stuff.%^RESET%^");
    set_property("lore difficulty", 30);
    
    set_hit((:this_object(),"hit_fun":));
    set_wield((:this_object(), "wield_fun":));
    set_unwield((:this_object(), "unwield_fun":));
    
    set_property("no curse", 1);
    set_property("no alter", 1);
    set_property("enchantment", 4);
    set_heart_beat(1);
    set_value(20000);
    
    counter = 0;
    special = 0;
    opening = 0;
    followup = 0;
    charges = 0;
}

void init(){
    ::init();
    add_action("slash_fun", "slash");
    add_action("followup_fun", "go");
}

void heart_beat(){
    object odachi, sheath, player, *targets;
    int sheathed;
    
    if(!objectp(odachi = this_object())) return;
    if(!objectp(sheath = environment(odachi))) return;
    
    if(sheath->is_sheath()) sheathed = 1;
    if(sheathed && userp(player = environment(sheath))){
        if(!random(25)){
            switch(random(2)){
                case 0:
                    tell_object(player, "You find your hand gravitating towards the odachi in its sheath.");
                    break;
                case 1:
                    tell_object(player, "Your fingers itch for the feel of the odachi...");
                    break;
            }
        }
    }
    if(!sheathed && userp(player = sheath)){
        if(query_wielded()){
            targets = all_living(environment(player));
            targets -= ({ player });
            if(sizeof(targets)){
                if(!random(25)){
                    switch(random(4)){
                        case 0:
                            tell_object(player, "Your mind wanders, and you daydream about the color of "+targets[random(sizeof(targets))]->query_cap_name()+" intestines....");
                            break;
                        case 1:
                            tell_object(player, "Did "+targets[random(sizeof(targets))]->query_cap_name()+" just sneer at you?");
                            break;
                        case 2:
                            tell_object(player, "You get the feeling that "+targets[random(sizeof(targets))]->query_cap_name()+" is conspiring against you. You've never trusted them, after all.");
                            break;
                        case 3:
                            tell_object(player, "You notice a vein in "+targets[random(sizeof(targets))]->query_cap_name()+"'s neck, and wonder how much blood would spill if you just cut it open...");
                            break;
                    }
                }
            }
            else{
                if(!random(25)){
                    switch(random(2)){
                        case 0:
                            break;
                        case 1:
                            break;
                    }
                }
            }
        }
        else{
            if(!random(25)){
                switch(random(2)){
                    case 0:
                        break;
                    case 1:
                        break;
                }
            }
        }
    }
    
    return;
}

int wield_fun(){
    object player, room;
    player = environment(this_object());
    room = environment(player);
    
    if(player->query_property("odachi of the four perils")){
        tell_object(player, "%^RESET%^%^CRST%^%^C100%^As you try to wield both swords, a strange resistance prevents you from doing so.%^CRST%^");
        return 0;
    }
    
    tell_object(player, "Eerie runes light up along the flat of the blade, eldritch wisps of light wavering just above the metal.");
    tell_room(room, "Eerie runes light up along the flat of "+player->query_cap_name()+"'s blade, eldritch wisps of light wavering just above the metal.", player);
    player->set_property("odachi of the four perils", 1);
    adapt_weapon();
    return 1;
}

int unwield_fun(){
    object player, room;
    player = environment(this_object());
    room = environment(player);
    
    player->remove_property("odachi of the four perils");
    tell_object(player, "The glowing runes fade away as you put the blade aside.");
    tell_room(room, "The glowing runes fade away as "+player->query_cap_name()+" puts the blade aside.", player);
    charges = 0;
    return 1;
}

void adapt_weapon(){
    object odachi;
    int strength;
    
    odachi = this_object();
    strength = odachi->query_property("enchantment") - 4;
    odachi->set_item_bonus("attack bonus", strength);
    odachi->set_item_bonus("damage bonus", strength);
    return;
}

int hit_fun(object target){
    object player, room, odachi;
    int dam, damage, strength;
    string playername, targetname;
    
    odachi = this_object();
    player = environment(odachi);
    room = environment(player);
    
    if(!living(player) || !living(target) || !room) return 0;
    
    if(!special && !random(20 - strength)){
        call_out("special_fun", 1, player);
        special = 1;
    }
    
    counter++;
    if(counter < HIT_INTERVAL) return 0;
    counter = 0;
    
    playername = player->query_cap_name();
    targetname = target->query_cap_name();
    strength = odachi->query_property("enchantment");
    damage = 0;
    
    switch(random(10)){
        case 0..5 :
            tell_object(player, "Your odachi bites deeply into "+targetname+", seeming to draw power from "+target->query_objective()+" before twisting free.");
            tell_object(target, ""+playername+"'s odachi bites deeply into you, seeming to draw power from you before twisting free.");
            tell_room(room, ""+playername+"'s odachi bites deeply into "+targetname+", seeming to draw power from "+target->query_objective()+" before twisting free.", ({player, target}));
            damage += roll_dice(strength, 5);
            charges += 1;
            break;
        case 6..7 :
            tell_object(player, "Your odachi tears into "+targetname+", rending and severing as the hovering runes brighten and shiver erratically!");
            tell_object(target, ""+playername+"'s odachi tears into you, rending and severing as the hovering runes brighten and shiver erratically!");
            tell_room(room, ""+playername+"'s odachi tears into "+targetname+", rending and severing as the hovering runes brighten and shiver erratically!", ({player, target}));
            damage += roll_dice(strength, 10);
            charges += 2;
            break;
        case 8..9 :
            tell_object(player, "As your odachi sinks into "+targetname+", its runes pulse like some eldritch heartbeat... and you feel rejuvenated!");
            tell_object(target, "As "+playername+"'s odachi sinks into you, its runes pulse like some eldritch heartbeat...");
            tell_room(room, "As "+playername+"'s odachi sinks into "+targetname+", its runes pulse like some eldritch heartbeat...", ({player, target}));
            dam = roll_dice(strength, 10);
            player->cause_typed_damage(player, "torso", -dam, "untyped");
            player->cause_typed_damage(player, "torso", -dam, "untyped");
            break;
    }
    
    if(charges > 4){
        call_out("burst_fun", 1, player, room, strength);
        charges -= 5;
    }
    
    return damage;
}

void burst_fun(object player, object room, strength){
    object *attackers;
    string playername;
    int i;
    
    attackers = player->query_attackers();
    attackers += ({ player });
    playername = player->query_cap_name();
    
    tell_object(player, "The runes hovering along your odachi skip and twist excitedly before exploding, sending a wave of dark energy slicing out towards your enemies!");
    tell_room(room, "The runes hovering along "+playername+"'s odachi skip and twist excitedly before exploding, sending a wave of dark energy slicing out towards "+player->query_possessive()+" enemies!", attackers);
    attackers -= ({ player });
    for(i = 0; i < sizeof(attackers); i++ ){
        if(!objectp(attackers[i])) continue;
        attackers[i]->cause_typed_damage(attackers[i], "torso", strength * 10, "void");
        tell_object(attackers[i], "The runes hovering along "+playername+"'s odachi skip and twist excitedly before exploding, sending a wave of dark energy slicing out towards you!");
        continue;
    }
    return;
}

void special_fun(object player){
    object room, *attackers;
    room = environment(player);
    attackers = player->query_attackers();
    
    if(!living(player) || !objectp(room)) return;
    if(!sizeof(attackers)) return;

    tell_object(player, "\nYou spin back into a low crouch, your odachi held behind you and readying it for a powerful -slash- as the floating runes flare brightly...");
    tell_room(room, ""+player->query_cap_name()+" brings "+player->query_possessive()+" odachi back into a low crouch as its floating runes flare brightly...", player);
    opening = 1;
    call_out("special_reset", 4, player);

    return;
}

void special_reset(object player){
    if(opening){
        object room = environment(player);
        
        tell_object(player, "The moment passes, and you relax your stance as the runes dim.\n");
        tell_room(room, ""+player->query_cap_name()+" seems to hesitate, relaxing their stance as the runes dim.\n", player);
        opening = 0;
    }
    if(followup){
        object room = environment(player);
        
        tell_object(player, "The moment passes, and you relax your stance as the runes dim.\n");
        tell_room(room, ""+player->query_cap_name()+" seems to hesitate, relaxing their stance as the runes dim.\n", player);
        followup = 0;
    }
    special = 0;
    return;
}

int slash_fun(){
    object odachi, player, room, target, *attackers;
    string playername, targetname;
    int strength;
    
    if(!query_wielded()) return 0;
    if(!objectp(odachi = this_object())) return 0;
    if(!objectp(player = environment(odachi))) return 0;
    if(!objectp(room = environment(player))) return 0;
    
    if(!opening){
        tell_object(player, "You're hardly in the proper stance for that right now.");
        return 1;
    }
    attackers = player->query_attackers();
    if(!sizeof(attackers)){
        tell_object(player, "All of your enemies are already dead.");
        special_reset(player);
        return 1;
    }
    
    target = attackers[random(sizeof(attackers))];
    if(!objectp(target)) return 1;
    strength = odachi->query_property("enchantment");
    playername = player->query_cap_name();
    targetname = target->query_cap_name();
    
    tell_object(player, "Dashing forward, you slice deeply into "+targetname+"!");
    tell_object(target, "Dashing forward, "+playername+" slices deeply into you!");
    tell_room(room, "Dashing forward, "+playername+" slices deeply into "+targetname+"!", ({player, target}));
    set_property("magic", 1);
    target->cause_typed_damage(target, "torso", roll_dice(strength * 2, 8), "slashing");
    target->cause_typed_damage(target, "torso", roll_dice(strength * 2, 8), "void");
    remove_property("magic");
    opening = 0;
    
    if(strength > 6){
        tell_object(player, "Stepping past "+targetname+", you bring your odachi back around for another attack... but do you go high or go low?");
        tell_object(target, "Stepping past you, "+playername+" brings "+player->query_possessive()+" odachi back around for another attack...");
        tell_room(room, "Stepping past "+targetname+", "+playername+" brings "+player->query_possessive()+" odachi back around for another attack...", ({player, target}));
        last_target = target;
        followup = 1;
    }
    
    return 1;
}

int followup_fun(string str){
    object odachi, player, room;
    string playername, targetname;
    int strength;
    
    if(!followup) return 0;
    if(!str) return 0;
    if(str != "high" && str != "low") return 0;
    
    odachi = this_object();
    player = environment(odachi);
    room = environment(player);
    
    if(!objectp(last_target)){
        tell_object(player, "That enemy is already dead.");
        return 1;
    }
    
    if(!followup){
        tell_object(player, "You're hardly in the proper stance for that right now.");
        return 1;
    }
    
    strength = odachi->query_property("enchantment");
    playername = player->query_cap_name();
    targetname = last_target->query_cap_name();
    
    if(str == "high"){
        tell_object(player, "You rake "+targetname+" across the eyes with a vicious swing, blinding "+last_target->query_objective()+"!");
        tell_object(last_target, ""+playername+" rakes you across the eyes with a vicious swing, blinding you!");
        tell_room(room, ""+playername+" rakes "+targetname+" across the eyes with a vicious swing, blinding them!", ({player, last_target}));
        last_target->set_temporary_blinded(strength - 6);
    }
    if(str == "low"){
        tell_object(player, "You sweep low, knocking "+targetname+" off "+last_target->query_possessive()+" feet!");
        tell_object(last_target, ""+playername+" sweeps low, knocking you off your feet!");
        tell_room(room, ""+playername+" sweeps low, knocking "+targetname+" off "+last_target->query_possessive()+" feet!", ({player, last_target}));
        last_target->set_tripped(strength - 6, "You're still struggling back to your feet!");
    }
    followup = 0;
    return 1;
}

