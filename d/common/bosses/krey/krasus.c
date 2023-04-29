/*
  krasus.c
  
  Great golden dragon. Avatar boss of Krey.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>
#include <magic.h>

#define COREPARTY 4

inherit "/d/common/bosses/avatar_boss.c";

int buffed,
    ticker,
    enrage;
    
object room;

mapping checkpoints = ([
                        "shield"  : 0;
                        "spear"   : 0;
                        "barrage" : 0;
                        "dragon"  : 0;
                        "waves"   : 0;
                      ]);
                      
object barrage_room;

void create()
{
    set_name("krasus");
    set_id( ({ "dragonkin", "defender", "warrior", "golden defender" }) );
    set_short("Krasus, the Great Golden Defender");
    set_long("");
    set_race("human");
    set_gender("male");
    set_hd(75, 10);
    set_class("paladin");
    set_mlevel("paladin", 75);
    set_class("immortal_defender");
    set_mlevel("immortal_defender", 10);
    set_class("cleric");
    set_mlevel("cleric", 75);
    set_class("oracle");
    set_mlevel("oracle", 75);
    set_mystery("dragon");
    set("base_class", "paladin");
    set("dragon_affinity", "gold");
    set_alignment(1);
    set_damage(20, 10);
    set_attacks_num(10);
    
    set_stats("strength", 30);
    set_stats("constitution", 30);
    set_stats("charisma", 30);
    set_stats("wisdom", 10);
    set_stats("dexterity", 14);
    set_stats("intelligence", 10);    
    set_skill("perception", 50);
    set_mob_magic_resistance("high");
    set_overall_ac(-80);
    set_sight_bonus(10);
    set_max_hp(125000);
    set_hp(125000);
    
    set_monster_feats( ({ "damage resistance", "improved damage resistance", "weapon focus", "rush", "shield focus", "shieldbash", "resistance", "improved resistance", "increased resistance", "expertise", "parry", "shieldwall", "counter", "weapon bond", "armor bond", "penetrating strike", "layonhands", "smite", "dreadful carnage", "cornugon smash", "shatter defenses", "intimidating prowess", "dazzling display", "improved shieldbash", "improved rush" }) );
    
    set_spell_chance(25);
    
    set_spells( ({ "shield of dawn", "stone body", "angelic aspect", "archon aura", "prayer", "seeking sword" }) );
    
    if(!clonep())
        return;
    
    obj = new("/d/magic/obj/shields/kreysneothosies");
    obj->set_property("enchantment", 10);
    obj->move(this_object());
    obj->set_property("monster weapon", 1);
    force_me("wear shield");

    obj = new("/d/magic/obj/weapons/kreysneothosies");
    obj->set_property("enchantment", 10);
    obj->move(this_object());
    obj->set_property("monster weapon", 1);
    force_me("wield weapon");
}

void init()
{
    object player;
    
    ::init();
    
    player = this_player();
    player && room = environment(this_object());
    
    if(!player || !room)
        return;
    
    if (wizardp(player) || player->query_true_invis()) {
        return;
    }
    
    if(!buffed)
    {
        command("shieldwall max");
        command("enhance add axiomatic");
        command("enhance add holy");
        command("enhance weapon");
        command("enhance add light fortification")
        command("enhance armor");
        command("defenders_presence");
        new("/cmds/spells/2/_shield_of_dawn.c")->use_spell(this_object(), 0, 70, 100, "paladin");
        new("/cmds/spells/a/_angelic_aspect.c")->use_spell(this_object(), 0, 70, 100, "paladin");
        new("/cmds/spells/a/_archon_aura.c")->use_spell(this_object(), 0, 70, 100, "paladin");
        new("/cmds/spells/s/_seeking_sword.c")->use_spell(this_object(), 0, 70, 100, "paladin");
        buffed = 1;
    }        
}

void heart_beat()
{
    object attackers, room;
    int percent;

    if (!objectp(this_object()))
    {
        return;
    }

    ::heart_beat();
    
    room = environment(this_object());
    
    if(!room)
        return;

    attackers = this_object()->query_attackers();
    
    if(sizeof(attackers))
        ticker++;
    else
        return;
    
    if(!enrage && ticker >= ENRAGE_TIMER)
    {
        enrage(room);
    }
    else if(enrage)
    {   
        if((query_hp() < query_max_hp()))
            add_hp(1000);
    }
    
    percent = (query_hp() * 100) / query_max_hp();
    
    switch(percent)
    {
        case 90..100:
        if(sizeof(attackers))
            shield(room);
        break;
        
        case 70..89:
        spear(room);
        break;
        
        case 40..69:
        barrage(room);
        break;
        
        case 20..39:
        dragon(room);
        break;
            
        default:
        waves(room);
        break;
    }
}

object pick_random_target(string type)
{
    object* attackers;
    if (!objectp(TO)) {
        return 0;
    }

    attackers = this_object()->query_attackers();
    
    if(type == "user")
        attackers = filter_array(attackers, (: userp($1) :));

    if (!sizeof(attackers)) {
        return 0;
    }
    return attackers[random(sizeof(attackers))];
}

//SHIELD PHASE
void shield(object room)
{
    object target;
    
    if(!objectp(room))
        return;
    
    if(!checkpoints["shield"])
    {
        tell_room(room, "MESSAGE START SHIELD PHASE");
        set_spell_chance(0);
        checkpoints["shield"] = 1;
    }
    
    target = pick_random_target("user");
    
    if(!objectp(target))
        return;
    
    switch(random(4))
    {
        case 0:
        command("smite " + target->query_name());
        break;
        case 1:
        command("shieldbash " + target->query_name());
        break;
        case 2:
        command("rush " target->query_name());
        break;
        case 3:
        command("shield_charge");
        break;
    }
}

//SPEAR PHASE
void spear(object room)
{
    object target, weapon;
    
    if(!objectp(room))
        return;
    
    if(!checkpoints["spear"])
    {
        tell_room(room, "YOU FACE THE INDOMITABLE MIGHT OF THE GREAT GOLDEN DRAGON EMPEROR HIMSELF!");
        
        if(objectp(weapon = new("/d/common/bosses/loot/regalith")))
        {
            tell_room(room, "A GREAT GOLDEN SPEAR APPEARS IN KRASUS'S HANDS, AND MIGHTY CLAWS APPEAR ON HIS HANDS");
            command("shieldwall min");
            command("unwield weapon");
            command("remove shield");
            weapon->move(this_object());
            weapon->set_property("monster weapon", 1);
            set_spell_chance(0);
            set_monster_feats( ({ "damage resistance", "improved damage resistance", "weapon focus", "rush", "resistance", "improved resistance", "increased resistance", "parry", "weapon bond", "armor bond", "penetrating strike", "layonhands", "smite", "dreadful carnage", "cornugon smash", "shatter defenses", "intimidating prowess", "dazzling display", "improved rush", "sweepingblow", "strength of arm", "light weapon", "impale" }) );
            command("powerattack max");
        }
        
        checkpoints["spear"] = 1;
    }
    
    target = pick_random_target("user");
    
    switch(random(4))
    {
        case 0:
        command("sweepingblow");
        break;
        case 1:
        command("impale " + target->query_name());
        break;
        case 2:
        command("smite " + target->query_name());
        break;
        case 3:
        command("rush " + target->query_name());
        break;
    }
}

//BARRAGE PHASE
void barrage()
{
    object *targets;
    
    if(!checkpoints["barrage"])
    {
        tell_room(room, "MESSAGE START BARRAGE PHASE");
        set_spell_chance(0);
        checkpoints["barrage"] = 1;
    }

    if(!sizeof(targets = this_object()->query_attackers()))
        return;
    
    tell_room(room, "BARRAGE MESSAGE");
    
    foreach(object ob in targets)
    {
        if(!SAVING_THROW_D->fort_save(ob, 85))
        {
            ob->set_property("rend", 2);
            tell_object(ob, "BLEEDING MESSAGE");
        }
        
        ob && ob->cause_typed_damage(ob, "torso", roll_dice(10, 10) + 200, "piercing");
    }
    
    target = pick_random_target("user");
    
    if(!objectp(target))
        return;

    switch(random(4))
    {
        case 0:
        command("sweepingblow");
        break;
        case 1:
        command("impale " + target->query_name());
        break;
        case 2:
        command("smite " + target->query_name());
        break;
        case 3:
        command("rush " + target->query_name());
        break;
    }
}

void dragon()
{
    if(!objectp(room))
        return;
    
    if(!checkpoints["dragon"])
    {
        tell_room(room, "MESSAGE START DRAGON PHASE");
        command("unwield weapon");
        set_race("dragonkin");
        set_short("DRAGONKIN SHORT DESC");
        set_long("DRAGONKIN LONG DESC");
        set_monster_feats( ({ "damage resistance", "improved damage resistance", "weapon focus", "rush", "resistance", "improved resistance", "increased resistance", "parry", "weapon bond", "armor bond", "penetrating strike", "layonhands", "smite", "dreadful carnage", "cornugon smash", "shatter defenses", "intimidating prowess" }) );
        set_spells( ({ "obsidian flow", "overwhelming presence", "fear", "powerword kill", "earthquake", "bolt of force" }) );
        set_spell_chance(50);
        command("dragon_aspect");
        checkpoints["dragon"] = 1;
    }
    
    switch(random(2))
    {
        case 0:
        command("smite " + target->query_name());
        break;
        case 1:
        command("rush " + target->query_name());
        break;
    }
}

void waves()
{
    if(!objectp(room))
        return;
    
    if(!checkpoints["waves"])
    {
        tell_room(room, "MESSAGE START WAVES PHASE");
        set_race("dragon");
        set_short("DRAGON SHORT DESC");
        set_long("DRAGON LONG DESC");
        set_spell_chance(100);
        checkpoints["waves"] = 1;
    }
}   

