#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit FEAT;


void create()
{
    ::create();
    feat_type("instant");
    feat_category("RadiantServant");
    feat_name("radiant aura");
    feat_syntax("radiant_aura");
    feat_prereq("Radiant Servant L4");
    feat_classes("base_class");
    feat_desc("You have become an unrelenting source of radiance amongst both friend and foe. When activated, this aura will periodically pulse with radiant energy, healing your allies and damaging your foes with 1d6 radiant damage per caster level (half on fortitude save). Enemies so struck must make a reflex save or be blinded by the scouring light for clevel / 20 + 1 rounds. This aura will damage undead minions of party members.");
    set_target_required(0);
    set_required_for(({"supreme healer"}));
}

int allow_shifted()
{
    return 1;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }

    if (ob->query_class_level("radiant_servant") < 4) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_radiant_aura(string str)
{
    object feat;
    if (!objectp(TP)) {
        return 0;
    }
    feat = new(base_name(TO));
    feat->setup_feat(TP, str);
    return 1;
}

void execute_feat()
{
    object obj;
    string diety;

    if (!objectp(caster))
        return;

    if (FEATS_D->is_active(caster, "radiant aura")) {
        obj = query_active_feat("radiant aura");
        obj->dest_effect();
        caster = 0;
        dest_effect();
        return;
    }
    ::execute_feat();

    if (stringp(diety = caster->query_diety()))
        tell_object(caster,"%^C032%^You close your eyes and open your mind, channeling %^C039%^e%^C045%^n%^C051%^er%^C045%^g%^C039%^y %^C032%^directly from " + capitalize(diety) + ".%^CRST%^");

    caster->set_property("active_feats",({this_object()}));

    return;
}


void execute_attack()
{
    object *party=({});
    object *attackers = ({  });
    int i, damage, healed, casting_stat;

    if(!objectp(caster) || caster->query_ghost())
    {
        dest_effect();
        return;
    }

    place = environment(caster);
    party = ob_party(caster,"all");
    party += caster->query_followers() - caster->query_attackers();
    party = distinct_array(party);

    if (!sizeof(party)) {
        party = ({ caster });
    }

    healed = 0;
    
    for (i = 0; i < sizeof(party); i++) {
        if (!objectp(caster) || caster->query_ghost()) {
            dest_effect();
            return;
        }
        if (caster->query_unconscious()) {
            continue;
        }
        if (!objectp(party[i])) {
            continue;
        }
        if (environment(party[i]) != environment(caster)) {
            continue;
        }
        if (party[i]->query_hp_percent() >= 100) {
            continue;
        }

        if (party[i]->query_property("negative energy affinity")) {
            continue;
        }

        damage = roll_dice(flevel, 4);

        party[i]->cause_typed_damage(party[i], party[i]->return_target_limb(), damage, "positive energy");
        if(party[i] != caster) {
            tell_object(party[i], "%^RESET%^%^CRST%^%^C032%^A wave of %^C039%^p%^C045%^o%^C051%^siti%^C045%^v%^C039%^e e%^C045%^n%^C051%^er%^C045%^g%^C039%^y %^RESET%^%^C032%^emanates outwards from "+caster->QCN+" and bathes %^C044%^you %^RESET%^%^C032%^in a %^C214%^h%^C220%^e%^C226%^ali%^C220%^n%^C214%^g r%^C220%^a%^C226%^dian%^C220%^c%^C214%^e%^RESET%^%^C032%^.%^CRST%^");
            healed = 1;
        }
    }
    if(healed) tell_object(caster, "%^RESET%^%^CRST%^%^C032%^A wave of %^C039%^p%^C045%^o%^C051%^siti%^C045%^v%^C039%^e e%^C045%^n%^C051%^er%^C045%^g%^C039%^y %^RESET%^%^C032%^emanates outwards from you and bathes your %^C044%^allies %^RESET%^%^C032%^in a %^C214%^h%^C220%^e%^C226%^ali%^C220%^n%^C214%^g r%^C220%^a%^C226%^dian%^C220%^c%^C214%^e%^RESET%^%^C032%^.%^CRST%^");
    
    attackers = caster->query_attackers();
    
    if(sizeof(attackers))
        tell_object(caster, "%^C032%^Your enemies are e%^C039%^n%^C045%^g%^C051%^u%^C045%^l%^C039%^f%^C032%^ed in %^C214%^r%^C220%^a%^C226%^d%^C220%^i%^C214%^ant%^C032%^, %^C214%^s%^C220%^c%^C226%^o%^C214%^uring l%^C220%^i%^C226%^g%^C214%^ht%^C032%^!%^CRST%^");
    
    foreach(object ob in attackers)
    {
        if(!ob || !objectp(ob))
            continue;
        
        if(place != environment(ob))
            continue;
        
        if(ob->query_unconscious())
            continue;
        
        if(!random(3))
            continue;
        
        casting_stat = max( ({ caster->query_stats("intelligence"), caster->query_stats("charisma"), caster->query_stats("wisdom") }) );
        casting_stat = (casting_stat - 10) / 2;
        
        userp(ob) && tell_object(ob, "%^C032%^You are e%^C039%^n%^C045%^g%^C051%^u%^C045%^l%^C039%^f%^C032%^ed in %^C214%^r%^C220%^a%^C226%^d%^C220%^i%^C214%^ant%^C032%^, %^C214%^s%^C220%^c%^C226%^o%^C214%^uring l%^C220%^i%^C226%^g%^C214%^ht%^C032%^!%^CRST%^");
        
        set_save("fort");
        
        if(!do_save(ob, casting_stat))
            ob->cause_typed_damage(ob, "chest", roll_dice(clevel, 6), "radiant");
        else
            ob->cause_typed_damage(ob, "chest", roll_dice(clevel, 6) / 2, "radiant");
        
        set_save("reflex");
        
        if(!do_save(ob, casting_stat) && !PLAYER_D->immunity_check("blindness"))
            ob->set_temporary_blinded(clevel / 20 + 1);
    }

    if (objectp(place)) {
        place->addObjectToCombatCycle(TO, 1);
    }else {
        dest_effect();
    }
    return;
}


void dest_effect()
{
    if(objectp(caster))
    {
        tell_object(caster,"%^B_BLUE%^Your radiant aura deactivates.%^RESET%^");
        caster->remove_property_value("active_feats",({TO}));
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}

