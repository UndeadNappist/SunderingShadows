#include <std.h>
#include <daemons.h>

inherit FEAT;

object companion;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("PaleLord");
    feat_name("undead cohort");
    feat_prereq("Pale Lord L4");
    feat_syntax("undead_cohort to summon or dismiss the bone golem");
    feat_desc("The second phase of transformation is the infusion of negative energy. To achieve this, the Pale Lord drains all of their own blood and replaces it with delicately woven spells that substitute its function. The blood itself is sacrificed in the ritual to summon the power needed to sustain such spells. This step of transformation gives the Pale Lord an innate understanding of undeath. They gain the ability to cast vampiric touch, animate dead, exhume corpses, create undead, and create greater undead spells as innate powers. Using this feat actively will summon a bone golem to their side. This feat does not work alongside animal companion, arcane bond, or similar feats.\n\nThe Bone Golem can be customized through several commands, which will allow you to change its description:\n\n  %^ORANGE%^<golem short %^ULINE%^DESCRIPTION%^RESET%^%^ORANGE%^> \t%^RESET%^Changes the short description of the golem.\n  %^ORANGE%^<golem long %^ULINE%^DESCRIPTION%^RESET%^%^ORANGE%^> \t%^RESET%^Changes the long description of the golem.\n  %^ORANGE%^<golem follow> \t\t%^RESET%^Commands the golem to follow you.\n  %^ORANGE%^<golem command %^ULINE%^ACTION%^RESET%^%^ORANGE%^> \t%^RESET%^Commands a golem to perform an action.%^RESET%^");
    //permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("pale_lord") < 4)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_undead_cohort(string str)
{
    object feat;
    
    if(!objectp(this_player()))
        return 0;
    
    feat = new(base_name(this_object()));
    feat->setup_feat(this_player(), str);
    
    return 1;
}

void execute_feat()
{
    object ob;
    
    int class_level,
        comp_hd,
        comp_ac;
    
    ::execute_feat();
    
    if(caster->query_property("using instant feat"))
    {
        tell_object(caster,"You are already in the middle of using a feat!");
        dest_effect();
        return;
    }

    
    if(sizeof(caster->query_attackers()))
    {
        tell_object(caster, "You can't summon your bone golem during combat!");
        return;
    }
    
    companion = caster->query_property("animal_companion");
    
    if(objectp(companion))
    {
        companion && tell_object(caster, "You dismiss your bone golem.");
        caster->remove_property("animal_companion");
        companion && companion->remove();
                
        return;
    }
    
    tell_object(caster, sprintf("You summon your bone golem to your side."));
    
    class_level = caster->query_guild_level(caster->query("base_class"));
    comp_hd = class_level + 2;
    comp_ac = class_level + 10;
    
    companion = new("/d/magic/mon/bone_golem");
    companion->set_race("undead");
    companion->set_name("golem");
    companion->set_id( ({ "golem", "bone golem", "greater summon", caster->query_name() + "'s ally" }) );
    //companion->set_short(sprintf("%s's bone golem.",capitalize(caster->query_name())));
    companion->set_level(class_level);
    companion->set_hd(comp_hd, 14);
    companion->set_attacks_num(2 + class_level / 10);
    companion->set_mlevel("fighter", comp_hd);
    companion->set_max_hp(50 + (25 * comp_hd));
    companion->set_hp(25 * comp_hd + 50);
    companion->set_alignment(caster->query_alignment());
    companion->set_owner(caster);
       
    caster->set_property("animal_companion", companion);
    caster->add_follower(companion);
    caster->add_protector(companion);

    companion->set_property("minion", caster);
    companion->move(environment(caster));
    companion->set_heart_beat(1);
    
    //Setting companion stats based on type per SRD
    companion->set_stats("strength", 16);
    companion->set_stats("dexterity", 12);
    companion->set_stats("constitution", 18);
    companion->set_stats("intelligence", 6);
    companion->set_stats("wisdom", 10);
    companion->set_stats("charisma", 6);
    companion->set_size(3);
    companion->set_property("spell damage resistance", class_level);
    companion->set_overall_ac(0 - comp_ac - 10);
    companion->set_monster_feats( ({ "resistance", "damage resistance", "evasion" }) );
       
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}


