// originally a ranger command
// reverted to a feat with damage realigned roughly to tabletop as ranger-levels are now irrelevant
// Nienne, 04/10.
#include <std.h>
#include <daemons.h>
inherit FEAT;

int DELAY = 35;

void create(){
    ::create();
    feat_type("instant");
    feat_category("UnarmedCombat");
    feat_name("spinning kick");
    feat_prereq("Unarmed combat or Monk");
    feat_syntax("spinning_kick");
    feat_desc("Spinning Kick is an instant combat feat. It allows someone skilled in unarmed combat to launch of series of devastating attacks on all enemies within melee range. It requires at least one enemy to work and will use a small amount of stamina. This feat requires you to be unarmed to use.");
    set_target_required(0);
}

int allow_shifted(){ return 0; }

int prerequisites(object ob){
    if(!objectp(ob)){ return 0; }
    if(!FEATS_D->has_feat(ob,"unarmed combat") && !ob->is_class("monk")){
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_spinning_kick(string str){
    object feat;
    if(!objectp(this_player())) { return 0; }
    feat = new(base_name(this_object()));
    feat->setup_feat(this_player(),str);
    return 1;
}

void execute_feat(){
    int attack_count;
    object *weapons;

    if(caster->cooldown("spinning kick")){
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^You cannot use spinning kick again so soon!%^CRST%^");
        dest_effect();
        return 1;
	}
    if(caster->query_bound() || caster->query_tripped() || caster->query_paralyzed()){
        caster->send_paralyzed_message("info", caster);
        dest_effect();
        return;
    }
    ::execute_feat();
    if(!objectp(caster)){
        dest_effect();
        return;
    }
    if((int)caster->query_property("using instant feat")){
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^You are already in the middle of using a feat!%^CRST%^");
        dest_effect();
        return;
    }
    if(!sizeof(caster->query_attackers())){
        tell_object(caster, "%^RESET%^%^CRST%^%^C226%^You're not fighting anyone!%^CRST%^\n");
        dest_effect();
        return;
    }
    weapons = caster->query_wielded();
    if(sizeof(weapons)){
        tell_object(caster, "%^RESET%^%^CRST%^%^C226%^You must be unarmed to use this feat!%^CRST%^\n");
        dest_effect();
        return;
    }
    tell_object(caster, "%^RESET%^%^CRST%^%^C067%^You center yourself, preparing your body to launch a series of %^C062%^de%^C061%^va%^C060%^sta%^C061%^ti%^C062%^ng %^C067%^attacks...%^CRST%^\n");
    tell_room(environment(caster), "%^RESET%^%^CRST%^%^C067%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C067%^ seems to center "+caster->query_objective()+"self, preparing "+caster->query_possessive()+" body...%^CRST%^\n",caster);

    caster->use_stamina(roll_dice(1,6));
    caster->set_property("using instant feat",1);
    spell_kill(target,caster);
    return;
}

void execute_attack(){
    object *weapons,*attackers;
    int i,dam,num,enchant,hit, res;

    if(!objectp(caster)){
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");
    ::execute_attack();
    if(caster->query_bound() || caster->query_tripped() || caster->query_paralyzed()){
        caster->send_paralyzed_message("info", caster);
        dest_effect();
        return;
    }

    attackers = (object *)caster->query_attackers();
    weapons = caster->query_wielded();
    if(!sizeof(attackers)){
        tell_object(caster, "%^RESET%^%^CRST%^%^C226%^You're not fighting anyone!%^CRST%^\n");
        dest_effect();
        return;
    }
    if(sizeof(weapons)){
        tell_object(caster, "%^RESET%^%^CRST%^%^C226%^You must be unarmed to use this feat!%^CRST%^\n");
        return 1;
    }
    
    caster->add_cooldown("spinning kick", DELAY);

    attackers = shuffle(attackers);

    for(i=0;i<sizeof(attackers) && i < 8;i++){
        if(!objectp(attackers[i])) continue;
        enchant = 0;
        if(caster->is_class("monk")) enchant = (int)"/std/class/monk.c"->effective_enchantment(caster);
        dam = caster->query_unarmed_damage();
        dam += enchant;
        dam += caster->query_damage_bonus();
        dam += roll_dice((int)caster->query_level(), 5) + roll_dice(2, 8);

        if(!present(attackers[i],environment(caster))){
            tell_object(caster, "%^RESET%^%^CRST%^%^C124%^That target is no longer in range!%^CRST%^");
            continue;
        }
        if(!(res = thaco(attackers[i]))){
            tell_object(attackers[i], "%^RESET%^%^CRST%^%^C072%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C072%^ spins and jumps toward you, launching a series of kicks... but you manage to %^C084%^avoid %^C072%^them!%^CRST%^");
            continue;

        }
        if(attackers[i]->query_property("weapon resistance") || res == -1){
            if(!hit) hit = -1;
            if(stringp(caster->query("featMiss"))){
                tell_object(caster, caster->query("featMiss")+" " +query_feat_name()+"!");
                caster->delete("featMiss");
                continue;
            }
            if(enchant < attackers[i]->query_property("weapon resistance")){
                tell_object(attackers[i], "%^RESET%^%^CRST%^%^C072%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C072%^ hits you with an %^C084%^ineffective %^C072%^barrage of kicks!%^CRST%^");
                continue;
            }
        }
        display_messages(attackers[i],caster);
        caster->cause_typed_damage(attackers[i], attackers[i]->return_target_limb(), dam, "bludgeoning");
        hit = 1;
        continue;
    }
    if(!hit){
        tell_object(caster, "%^RESET%^%^CRST%^%^C055%^You fail to land a strike on anything and almost fall over in the process!%^CRST%^");
        tell_room(environment(caster), "%^RESET%^%^CRST%^%^C055%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C055%^ almost falls over and has to scramble to regain "+caster->query_possessive()+" balance!%^CRST%^", caster);
        if(!FEATS_D->usable_feat(caster, "improved spinning kick")){
            caster->set_paralyzed(roll_dice(1,6), "%^RESET%^%^CRST%^%^C124%^You are trying to regain your balance!%^CRST%^");
        }
    }
    else if(hit > 0){
        switch(random(5)){
            case 0:
                tell_object(caster, "%^RESET%^%^CRST%^%^C036%^You land a %^C042%^s%^C048%^e%^C036%^r%^C042%^i%^C048%^e%^C036%^s of %^C042%^k%^C048%^ick%^C042%^s%^RESET%^%^C036%^ on your foes!%^CRST%^");
                tell_room(environment(caster), "%^RESET%^%^CRST%^%^C036%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C036%^ lands a %^C042%^s%^C048%^e%^C036%^r%^C042%^i%^C048%^e%^C036%^s of %^C042%^k%^C048%^ick%^C042%^s%^RESET%^%^C036%^ on "+caster->query_possessive()+" foes!%^CRST%^", ({target, caster}));
                break;
            case 1:
                tell_object(caster, "%^RESET%^%^CRST%^%^C074%^You spin quickly striking your opponents with a %^C080%^s%^C086%^e%^C074%^r%^C080%^i%^C086%^e%^C074%^s of well placed %^C080%^k%^C086%^ick%^C080%^s%^RESET%^%^C074%^!%^CRST%^");
                tell_room(environment(caster), "%^RESET%^%^CRST%^%^C074%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C074%^ spins quickly striking "+caster->query_possessive()+" opponents with a %^C080%^s%^C086%^e%^C074%^r%^C080%^i%^C086%^e%^C074%^s of well placed %^C080%^k%^C086%^ick%^C080%^s%^RESET%^%^C074%^!%^CRST%^", ({target, caster}));
                break;
            case 2:
                tell_object(caster, "%^RESET%^%^CRST%^%^C036%^You spin about rapidly, picking up speed as you slam into your opponents with a %^C042%^s%^C048%^e%^C036%^r%^C042%^i%^C048%^e%^C036%^s of %^C042%^k%^C048%^ick%^C042%^s%^RESET%^%^C036%^!%^CRST%^");
                tell_room(environment(caster), "%^RESET%^%^CRST%^%^C036%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C036%^ seems to pick up speed as "+caster->query_subjective()+" spins about rapidly, and slams "+caster->query_possessive()+" opponents with a %^C042%^s%^C048%^e%^C036%^r%^C042%^i%^C048%^e%^C036%^s of %^C042%^k%^C048%^ick%^C042%^s%^RESET%^%^C036%^!%^CRST%^", ({target, caster}));
                break;
            case 3:
                tell_object(caster, "%^RESET%^%^CRST%^%^RESET%^%^CRST%^%^C125%^You move around your opponents with a %^C127%^f%^C133%^l%^C139%^u%^C133%^i%^C127%^d g%^C133%^r%^C139%^a%^C133%^c%^C127%^e%^RESET%^%^C125%^ launching a series of %^C127%^k%^C133%^i%^C139%^c%^C133%^k%^C127%^s%^RESET%^%^C125%^!%^CRST%^");
                tell_room(environment(caster), "%^RESET%^%^CRST%^%^C125%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C125%^ moves around "+caster->query_possessive()+" opponents with a %^C127%^f%^C133%^l%^C139%^u%^C133%^i%^C127%^d g%^C133%^r%^C139%^a%^C133%^c%^C127%^e%^RESET%^%^C125%^ as "+caster->query_subjective()+" launches a series of %^C127%^k%^C133%^i%^C139%^c%^C133%^k%^C127%^s%^RESET%^%^C125%^!%^CRST%^", ({target, caster}));
                break;
            case 4:
                tell_object(caster, "%^RESET%^%^CRST%^%^C074%^You focus intently on your enemies... launching one %^C080%^k%^C086%^ic%^C080%^k%^RESET%^%^C074%^ after %^C080%^a%^C086%^nothe%^C080%^r%^RESET%^%^C074%^!%^CRST%^");
                tell_room(environment(caster), "%^RESET%^%^CRST%^%^C074%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C074%^ suddenly turns and focuses intently on "+caster->query_possessive()+" enemies...  "+caster->query_subjective()+" launches one %^C080%^k%^C086%^ic%^C080%^k%^RESET%^%^C074%^ after %^C080%^a%^C086%^nothe%^C080%^r%^RESET%^%^C074%^!%^CRST%^", ({target, caster}));
                break;
        }
    }
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    remove_feat(TO);
    return;
}

void display_messages(object targ, object player){
    if(!objectp(targ)) return;
    if(!objectp(player)) return;

    switch(random(5)){
        case 0:
            tell_object(target, "%^RESET%^%^CRST%^%^C036%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C036%^ lands a %^C042%^s%^C048%^e%^C036%^r%^C042%^i%^C048%^e%^C036%^s of %^C042%^k%^C048%^ick%^C042%^s%^RESET%^%^C036%^ on you!%^CRST%^");
            break;
        case 1:
            tell_object(target, "%^RESET%^%^CRST%^%^C074%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C074%^ spins quickly striking you with a %^C080%^s%^C086%^e%^C074%^r%^C080%^i%^C086%^e%^C074%^s of well placed %^C080%^k%^C086%^ick%^C080%^s%^RESET%^%^C074%^!%^CRST%^");
            break;
        case 2:
            tell_object(target, "%^RESET%^%^CRST%^%^C036%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C036%^ spins about rapidly, picking up speed as "+player->query_subjective()+" slam into you with a %^C042%^s%^C048%^e%^C036%^r%^C042%^i%^C048%^e%^C036%^s of %^C042%^k%^C048%^ick%^C042%^s%^RESET%^%^C036%^!%^CRST%^");
            break;
        case 3:
            tell_object(target, "%^RESET%^%^CRST%^%^C125%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C125%^ moves around you with a %^C127%^f%^C133%^l%^C139%^u%^C133%^i%^C127%^d g%^C133%^r%^C139%^a%^C133%^c%^C127%^e%^RESET%^%^C125%^ as "+player->query_subjective()+" launches a series of %^C127%^k%^C133%^i%^C139%^c%^C133%^k%^C127%^s%^RESET%^%^C125%^!%^CRST%^");
            break;
        case 4:
            tell_object(target, "%^RESET%^%^CRST%^%^C074%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C074%^ focuses intently on you... "+player->query_subjective()+" almost seems to blur as "+player->query_subjective()+" launches one %^C080%^k%^C086%^ic%^C080%^k%^RESET%^%^C074%^ after %^C080%^a%^C086%^nothe%^C080%^r%^RESET%^%^C074%^!%^CRST%^");
            break;
    }
}

