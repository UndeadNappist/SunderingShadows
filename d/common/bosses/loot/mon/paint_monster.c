//Living Paint Monster - LoKi

#include <std.h>

inherit WEAPONLESS;

void paint_me();
void pick_paint_style();

string paint_style,noun;

void create()
{

    ::create();
    set_name("Living Paint");
    set_id(({ "paint monster", "living paint"}));
	paint_me();
	pick_paint_style();
    set_short(""+paint_style+ "%^C039%^ drawn "+
	"paint " +noun+ "%^C039%^!" );
    set_long("%^C039%^This beast is a "+paint_style+" %^C039%^drawn "+
	"monster made entirely out of magical paint that seems to "+
	"be alive%^CRST%^");
    set_race("living paint");
    set_class("fighter");
    set_class("mage");
    set_class("cleric");
    set_guild_level("fighter", 20);
    set_guild_level("mage", 20);
    set_guild_level("cleric", 20);
    set_mlevel("fighter", 20);
    set_mlevel("mage", 20);
    set_mlevel("cleric", 20);
    set_alignment(5);
    set_hd(50, 10);
    set_max_hp(500);
    set_hp(query_max_hp());
    set_overall_ac(-10);
    call_out("die", 300); //setting a 5 minute lifespan
}
	
	

void paint_me()
{
    switch (random(5)) {
	case 0: 
       set_body_type("human");
	   add_id(({"paint humanoid", "humanoid"}));
	   noun = "%^C182%^humanoid%^CRST%^";
	break;
	case 1:
	   set_body_type("equine");
	   add_id(({"paint horse", "horse"}));
	   noun = "%^C215%^horse%^CRST%^";
	break;
	case 2:
       set_body_type("fowl");
	   add_id(({"paint chicken", "chicken"}));
	   noun = "%^C192%^chicken%^CRST%^";
	break;
	case 3:
	   set_body_type("dragon");
	   add_id(({"paint dragon", "dragon"}));
	   noun = "%^C111%^dragon%^CRST%^";
	break;
	case 4:
        set_body_type("snake");
    	add_id(({"paint snake", "snake"}));
		noun = "%^C071%^snake%^CRST%^";
	break;
}
}
	
void pick_paint_style()
{
	object ob;
    switch (random(5)) {
	case 0: 
       paint_style = "clumsily";

	break;
	case 1:
	   paint_style = "jaggedly";

	break;
	case 2:
       paint_style = "carefully";
    set_monster_feats(({
        "damage resistance",
        "Improved damage resistance",
        "deflection",
        "parry",
        "shieldbash",
        "shieldwall",
        "rush",
        "smite",
    }));
	
    ob = new("/d/obj/armour/buckler");
    ob->move(TO);
    ob->set_obvious_short("%^C125%^painted shield%^CRST%^");
    ob->set_property("monsterweapon",1);
	
	break;
	
	case 3:
       paint_style = "laboriously";
       set_monster_feats(({
        "unarmed combat",
        "spinning kick",
        "dodge",
        "evasion",
    }));

    set_funcs(({ "kickit" }));
    set_func_chance(20);
	
	break;
	case 4:
       paint_style = "faithfully";
    set_monster_feats(({
        "spell penetration",
        "perfect caster",
        "spell power",
    }));

    set_spells(({ "prismatic spray",
                  "sound burst", }));

    set_spell_chance(22);
	break;
        }
}

int die(){
    object painting, room;
    painting = this_object();
    room = environment(painting);
    
    if(objectp(room)) tell_room(room, "%^RESET%^%^ORANGE%^The painting loses its power, splashing lifelessly against the ground.%^RESET%^");
    painting->remove();

    ::die();
    return 1;
}

