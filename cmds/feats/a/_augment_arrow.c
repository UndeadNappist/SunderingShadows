/*
  _augment_arrow.c
  
  Infused ranged attacks with different types of additional effects.
  For Peerless Archer PRC.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>

#define VALID ({ "barbed", "crippling", "enervating", "blinding", "exploding" })
#define EXPLODE_BASE 6

inherit FEAT;

string type;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("PeerlessArcher");
    feat_name("augment_arrow");
    feat_prereq("Peerless Archer L7");
    feat_syntax("augment_arrow [TYPE]");
    feat_desc("With the feat, the Peerless Archer is able to fire an extra arrow at their target, each round, with a special type of arrow head. If the extra arrow hits the target, an extra effect will occur, as follows:

    %^CYAN%^BOLD%^Barbed     : %^RED%^Rend%^RESET%^
    %^CYAN%^BOLD%^Crippling  : %^WHITE%^Trip%^RESET%^
    %^CYAN%^BOLD%^Enervating : %^GREEN%^Fatigue%^RESET%^
    %^CYAN%^BOLD%^Blinding   : %^MAGENTA%^Blind%^RESET%^
    %^CYAN%^BOLD%^Exploding  : %^YELLOW%^Splash Fire and Piercing Damage.%^RESET%^

This is a toggle feat. Once it is active, you can deactivate it by typing <augment_arrow> once more");
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if (!objectp(ob))
    {
        return 0;
    }

    if ((int)ob->query_class_level("peerless_archer") < 7)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_augment_arrow(string str)
{
    object feat;
    if (!objectp(this_player()))
    {
        return 0;
    }
    feat = new(base_name(this_object()));
    feat->setup_feat(this_player(), str);
    return 1;
}

void execute_feat()
{
    object ob;
    
    ::execute_feat();
    
    if(ob = query_active_feat("augment arrow"))
    {
        tell_object(caster, "You put away your specialized arrows and begin utilizing normal arrows again.");
        ob->dest_effect();
        dest_effect();
        return;
    }
    
    if(!arg || !strlen(arg) || member_array(arg, VALID) < 0)
    {
        tell_object(caster, "%^CYAN%^You must select a valid augmentation type. Valid choices are : %^YELLOW%^" + implode(VALID, ", ") + ".%^RESET%^");
        dest_effect();
        return;
    }
    
    //These will become far more stylized descriptions
    switch(arg)
    {
        case "barbed":
        tell_object(caster, "You attach a barbed head to some of your arrows.");
        break;
        case "crippling":
        tell_object(caster, "You attach a crippling head to some of your arrows.");
        break;
        case "enervating":
        tell_object(caster, "You attach an enervating head to some of your arrows.");
        break;
        case "blinding":
        tell_object(caster, "You attach a blinding head to some of your arrows.");
        break;
        case "exploding":
        tell_object(caster, "You attach an exploding head to some of your arrows.");
        break;
    }
    
    type = arg;
    
    caster->set_property("active_feats", ({ this_object() }));
    return;
}

void execute_attack()
{
    int limit, affected, bonus, result, dam;
    string my_name, your_name, my_poss, your_poss, your_obj;
    object weapons;
    
    object attacker, *attackers;
    
    if(!strlen(type))
    {
        dest_effect();
        return;
    }
    
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    
    if (caster->query_ghost() || caster->query_unconscious())
    {
        reset_attack_cycle();
        return;
    }

    if(caster->query_bound() || caster->query_paralyzed())
    {
        reset_attack_cycle();
        return;
    }
    
    if(!attacker = caster->query_current_attacker())
    {
        reset_attack_cycle();
        return;
    }
    
    weapons = caster->query_wielded();
    
    if(!weapons || !pointerp(weapons) || !sizeof(weapons) || member_array("bow", !weapons[0]->query_id()) < 0)
    {
        tell_object(caster, "You need a bow to use augment arrow!");
        reset_attack_cycle();
        return;
    }
    
    bonus = BONUS_D->query_stat_bonus(caster, "dexterity");
    attackers = caster->query_attackers() - ({ attacker });
    affected = roll_dice(1, 6) + 1;
    limit = EXPLODE_BASE + bonus;
    affected = min( ({ limit, affected }) );
    bonus += (weapons[0]->query_wc() + weapons[0]->query_property("enchantment"));
    
    if(sizeof(attackers) > affected)
        attackers = attackers[0..affected];
    
    my_name = caster->query_cap_name();
    your_name = attacker->query_cap_name();
    my_poss = caster->query_possessive();
    your_poss = attacker->query_possessive();
    your_obj = attacker->query_objective();
    
    result = thaco(attacker);
    
    if(result <= 0)
    {
        tell_object(caster, "You fire a " + type + " arrow at " + your_name + ", but miss!");
        tell_room(place, my_name + " fires a " + type + " arrow at " + your_name + ", but misses!", caster);
        reset_attack_cycle();
        return;
    }
    
    dam = (roll_dice(1, 6) * (1 + flevel /  10)) + bonus;
    caster->cause_typed_damage(attacker,attacker->return_target_limb(),dam ,"piercing");
    
    if(!objectp(caster) || !objectp(attacker))
    {
        reset_attack_cycle();
        return;
    }
    
    switch(type)
    {
        case "barbed":
        tell_object(caster, "You fire a barbed arrow into " + your_name + ", causing massive bleeding!");
        tell_room(place, "generic barbed arrow message", caster);
        attacker->set_property("rend", 1 + flevel / 16);
        break;
        case "crippling":
        tell_object(caster, "You fire a crippling arrow into " + your_name + ", causing " + your_obj + " to trip!");
        tell_room(place, "generic crippling arrow message", caster);
        attacker->set_tripped(1);
        break;
        case "enervating":
        tell_object(caster, "You fire an enervating arrow into " + your_name + ", fatiguing " + your_obj + "!");
        tell_room(place, "generic crippling arrow message", caster);
        "/std/effect/status/fatigued"->apply_effect(target, 1);
        break;
        case "blinding":
        tell_object(caster, "You fire a blinding arrow into " + your_name + ", rendering " + your_obj + " sightless!");
        tell_room(place, "generic blinding arrow message", caster);
        attacker->set_temporary_blinded(flevel + bonus);
        break;
        case "exploding":
        tell_object(caster, "You fire an exploding arrow into " + your_name + ", exploding into a shower of sparks!");
        tell_room(place, "generic exploding arrow message", caster);
        foreach(object ob in attackers)
        {
            tell_room(place, ob->query_cap_name() + " is caught in the blast!");
            ob->cause_typed_damage(ob, ob->return_target_limb(), dam / 2, "fire");
            objectp(ob) && ob->cause_typed_damage(ob, ob->return_target_limb(), dam / 2, "piercing");
        }
        break;
    }
        
    
    reset_attack_cycle();
}

void reset_attack_cycle()
{
    if (objectp(place))
    {
        place->addObjectToCombatCycle(this_object(), 1);
    }
    else
    {
        dest_effect();
    }
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(this_object());
    return;
}
    