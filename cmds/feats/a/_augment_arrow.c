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

string type;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("PeerlessArcher");
    feat_name("augment_arrow");
    feat_prereq("Peerless Archer L7");
    feat_desc("");
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
    int limit, affected;
    string my_name, your_name, my_poss, your_poss;
    
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
    
    attackers = caster->query_attackers();
    affected = roll_dice(1, 6) + 1;
    limit = EXPLODE_BASE + BONUS_D->query_stat_bonus(caster, "dexterity");
    affected = min( ({ limit, affected }) );
    
    switch(type)
    {
        
    
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
    