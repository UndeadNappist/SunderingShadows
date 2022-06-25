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
    set_id( ({ "human", "defender", "warrior", "golden defender" }) );
    set_short("Krasus, the Great Golden Defender");
    set_long("");
    set_race("human");
    set_gender("male");
    set_hd(75, 9);
    set_class("paladin");
    set_mlevel("paladin", 65);
    set_class("immortal_defender");
    set_mlevel("immortal_defender", 10);
    set("base_class", "paladin");
    set_alignment(1);
    set_damage(16, 8);
    set_attacks_num(5);
    
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
}
    

