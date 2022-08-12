/*
  _dirty_trick.c
  
  A combat maneuver geared more towards tricky types.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>

#define COOLDOWN 60

inherit FEAT;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("CombatManeuvers");
    feat_name("dirty trick");
    feat_syntax("dirty_trick [TARGET]");
    feat_prereq("Expertise");
    feat_desc("Dirty Trick is a combat maneuver that allows you to perform a trick on the designated target. If you succeed a Combat Maneuver check, the target will randomly be either blinded, tripped, or sickened. This maneuver gains +2 to Combat Maneuver Bonus and you gain +2 Combat Maneuver Defense against opponents using this feat on you. This feat has a cooldown.");
    set_target_required(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (!FEATS_D->has_feat(ob, "expertise"))
    {
        dest_effect();
        return 0;
    }

    return ::prerequisites(ob);
}

int cmd_dirty_trick(string str)
{
    object feat;
    
    if (!objectp(this_player()))
        return 0;

    feat = new(base_name(this_object()));
    feat->setup_feat(this_player(), str);
    return 1;
}

void execute_feat()
{
    
    if ((int)caster->query_property("using instant feat"))
    {
        message("failure", "You are already in the middle of using a feat!", caster);
        dest_effect();
        return;
    }
    
    if(caster->cooldown("dirty trick"))
    {
        message("failure", "You're not ready to use dirty trick yet!", caster);
        dest_effect();
        return;
    }
    
    ::execute_feat();
    
    if(!present(target, place))
    {
        message("failure", "Your target is not here.", caster);
        dest_effect();
        return;
    }
    
    message("my spells", "%^C246%^You attempt to perform a dirty trick on " + target->query_cap_name() + ".%^CRST%^", caster);
    message("other spells", "%^C246%^" + caster->query_cap_name() + " attempts to perform a dirty trick on you.%^CRST%^", target);
    message("other spells", "%^C246%^" + caster->query_cap_name() + " attempts to perform a dirty trick on " + target->query_cap_name() + ".%^CRST%^", place, ({ caster, target }));
    
    caster->use_stamina(roll_dice(1, 6);
    caster->set_property("using instant feat", 1);
    spell_kill(target, caster);
    return;
}

void execute_attack()
{
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    
    caster->remove_property("using instant feat");
    
    if(!objectp(target) || !present(target, place))
    {
        tell_object(caster, "You target is no longer here.");
        dest_effect();
        return;
    }
}
