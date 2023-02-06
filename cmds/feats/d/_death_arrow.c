#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

void create(){
    ::create();
    feat_type("instant");
    feat_category("ArcaneArcher");
    feat_name("death arrow");
    feat_syntax("death_arrow [TARGET]");
    feat_prereq("Arcane archer L7");
    feat_desc("The archer imbues a missile with the power of negative energy, and releasing it to snuff a foe. Such projectiles can kill the target instantly, or cause severe damage even if the target is warded against death effects. It is unerring, and will never miss its target.\n\nIf used without an argument, this feat will pick up a random attacker.");
    set_save("fort");
}

int allow_shifted(){ return 0; }

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if((int)ob->query_class_level("arcane_archer") < 7){
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_death_arrow(string str){
    object feat;
    if(!objectp(this_player())) return 0;
    feat = new(base_name(this_object()));
    feat->setup_feat(this_player(), str);
    return 1;
}

int check_can_use(){
    object *weapons;
    int x;
    if(!objectp(caster)) return 0;
    weapons = caster->query_wielded();
    if(!sizeof(weapons))
        return 0;
    if(!weapons[0]->is_lrweapon()){
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^^You can't imbue a projectile with deathly power without a ranged weapon!%^CRST%^");
        dest_effect();
        return;
    }
    return 1;
}

void execute_feat(){
    mapping tempmap;
    object *weapons;
    int x;
    ::execute_feat();
    if(!objectp(caster)){
        dest_effect();
        return;
    }
    if(caster->query_bound() || caster->query_tripped() || caster->query_paralyzed()){
        caster->send_paralyzed_message("info", caster);
        dest_effect();
        return;
    }
    if((int)caster->query_property("using instant feat")){
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^You are already in the middle of using a feat!%^CRST%^");
        dest_effect();
        return;
    }
    if(caster->query_casting()){
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^You are already in the middle of casting a spell.%^CRST%^");
        dest_effect();
        return;
    }
    if(target == caster){
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^There are better ways to kill yourself!%^CRST%^");
        dest_effect();
        return;
    }
    tempmap = caster->query_property("using death arrow");
    if(!objectp(target)){
        object* attackers = caster->query_attackers();
        if(mapp(tempmap)){
            attackers = filter_array(attackers, (: $2[$1] < time() :), tempmap);
        }
        if(!sizeof(attackers)){
            tell_object(caster, "%^RESET%^%^CRST%^%^C059%^There are no targets.%^CRST%^");
            dest_effect();
            return;
        }
        target = attackers[random(sizeof(attackers))];
    }
    if(!present(target, place)){
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^That is not here!%^CRST%^");
        dest_effect();
        return;
    }

    if(mapp(tempmap)){
        if(tempmap[target] > time()){
            tell_object(caster, "%^RESET%^%^CRST%^%^C059%^That target is still wary of such an attack!%^CRST%^");
            dest_effect();
            return;
        }
    }
    if(!check_can_use()){
        dest_effect();
        return;
    }
    caster->set_property("using instant feat", 1);
    spell_kill(target, caster);

    tell_object(caster, "%^RESET%^%^CRST%^%^C019%^You whisper a few %^C026%^s%^C027%^y%^C032%^l%^C027%^l%^C032%^a%^C027%^b%^C032%^l%^C027%^e%^C026%^s %^RESET%^%^C019%^in tongues of %^C118%^u%^C112%^nl%^C106%^i%^C118%^f%^C112%^e %^RESET%^%^C019%^and imbue your projectile with %^C118%^f%^C112%^el%^C106%^l %^C118%^p%^C112%^ow%^C106%^e%^C118%^r%^RESET%^%^C019%^!%^CRST%^");
    tell_room(place, "%^RESET%^%^CRST%^%^C019%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C019%^ whispers a few %^C118%^f%^C112%^el%^C106%^l %^C026%^s%^C027%^y%^C032%^l%^C027%^l%^C032%^a%^C027%^b%^C032%^l%^C027%^e%^C026%^s %^RESET%^%^C019%^over "+caster->query_possessive()+" projectile!%^CRST%^");
    return;
}

void execute_attack(){
    int damage, timerz, i;
    int bonusdc;
    object* keyz, shape, * weapons, myweapon, qob;
    mapping tempmap;

    if(!objectp(caster)){
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");
    ::execute_attack();
    if(!objectp(target)){
        dest_effect();
        return;
    }
    if(caster->query_unconscious()){
        dest_effect();
        return;
    }
    if(!objectp(target) || !present(target, place)){
        tell_object(caster, "%^RESET%^%^CRST%^%^C059%^Your target has eluded you!%^CRST%^");
        dest_effect();
        return;
    }
    if(!check_can_use()){
        dest_effect();
        return;
    }

    tempmap = caster->query_property("using death arrow");
    if(!mapp(tempmap)){
        tempmap = ([]);
    }
    if(tempmap[target]){
        map_delete(tempmap, target);
    }
    keyz = keys(tempmap);
    for(i = 0; i < sizeof(keyz); i++){
        if(!objectp(keyz[i])){
            map_delete(tempmap, keyz[i]);
        }
        continue;
    }
    timerz = time() + 120;
    delay_subject_msg(target, 120, "%^RESET%^%^CRST%^%^C255%^"+target->query_cap_name()+"%^RESET%^%^CRST%^%^C255%^ can be %^C051%^death arrowed%^C255%^ again.%^CRST%^");
    tempmap += ([ target:timerz ]);
    caster->remove_property("using death arrow");
    caster->set_property("using death arrow", tempmap);

    weapons = caster->query_wielded();
    if(sizeof(weapons)){
        myweapon = weapons[0];
    }

    tell_object(caster, "%^RESET%^%^CRST%^%^C019%^Your deadly missile pierces into "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C019%^, releasing %^C118%^f%^C112%^el%^C106%^l %^C118%^p%^C112%^ow%^C106%^e%^C118%^r%^RESET%^%^C019%^!%^CRST%^");
    tell_room(place, "%^RESET%^%^CRST%^%^C019%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C019%^'s %^C118%^f%^C112%^el%^C106%^l %^C118%^m%^C112%^is%^C106%^s%^C118%^i%^C112%^le%^RESET%^%^C019%^ pierces into "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C019%^!%^RESET%^", caster);

    bonusdc = BONUS_D->query_stat_bonus(caster, "dexterity");
    if((string)target->query_property("no death") || do_save(target, bonusdc)){
        tell_object(target, "%^RESET%^%^CRST%^%^C032%^The struggle for your soul is won, yet at a %^C059%^price%^C032%^.%^CRST%^");
        tell_room(place, "%^RESET%^%^CRST%^%^C032%^The soul survives, yet the "+target->query_cap_name()+"'s mortal coil %^C059%^suffers%^C032%^!%^CRST%^", target);
        target->cause_typed_damage(target, target->return_target_limb(), roll_dice(clevel, 8), myweapon->query_damage_type());
    }
    else{
        tell_room(place, "%^RESET%^%^CRST%^%^C243%^The soul is pushed beyond the %^C118%^v%^C112%^ei%^C106%^l%^C243%^ from its mortal coil!%^CRST%^", target);
        tell_room(place, "%^RESET%^%^CRST%^%^C059%^The lifeless husk of "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C059%^ drops to the ground!%^CRST%^", target);
        tell_object(target, "%^RESET%^%^CRST%^%^C059%^Your soul is ripped from your body!%^CRST%^\n");
        target->cause_typed_damage(target, target->return_target_limb(), target->query_max_hp() * 2, myweapon->query_damage_type());
    }

    spell_kill(target, caster);

    dest_effect();
    return;
}

void dest_effect(){
    ::dest_effect();
    remove_feat(this_object());
    return;
}

