//_seeking_sword.c
//Minor updates by ~Circe~ 4/22/08 for readability, typos
#include <magic.h>
#include <std.h>
#include <spell.h>

inherit SPELL;

object *animated, *monsters, control;
string arg;
int amount;

void make_sword();

void create() {
    ::create();
    set_spell_name("seeking sword");
    set_spell_level(([ "paladin" : 4, "oracle" : 5 ]));
    set_spell_sphere("combat");
    set_mystery("godclaw");
    set_syntax("cast CLASS seeking sword");
    set_description("This spell will create a floating and controllable sword for you that you can use to attack your enemies. The sword will automatically follow and protect you. Should you lose it, simply go into the room with it and <command sword to follow>.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell()
{
	if(caster->query_property("seeking_sword"))
	{
        tell_object(caster, "%^RESET%^%^CRST%^%^C126%^You are incapable of controlling two swords.%^CRST%^");
        return 0;
    }
    return 1;
}

string query_cast_string(){
   tell_object(caster,"%^RESET%^%^CRST%^%^C103%^You begin to chant, lifting your hands before you.%^CRST%^");
   tell_room(place,"%^RESET%^%^CRST%^%^C103%^"+caster->QCN+"%^RESET%^%^CRST%^%^C103%^ begins to chant, lifting "+caster->QO+" hands.%^CRST%^",caster);
   return "display";
}

void spell_effect(int prof){
//    object *inven, *livings;
//No need for these - they aren't used. ~Circe~
	if(!objectp(environment(caster)))
	{
		dest_effect();
		return;
	}
	place = environment(caster);
        spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 4;
        set_end_time();
        call_out("dest_effect",spell_duration);
    make_sword();
}

void make_sword()
{
    object ob;

    tell_object(caster,"%^RESET%^%^CRST%^%^C101%^A %^C247%^h%^C245%^o%^C243%^veri%^C245%^n%^C247%^g s%^C245%^w%^C243%^o%^C245%^r%^C247%^d%^RESET%^%^C101%^ manifests before you.%^CRST%^");
    tell_room(place,"%^RESET%^%^CRST%^%^C101%^A %^C247%^h%^C245%^o%^C243%^veri%^C245%^n%^C247%^g s%^C245%^w%^C243%^o%^C245%^r%^C247%^d%^RESET%^%^C101%^ manifests before "+caster->QCN+"%^RESET%^%^CRST%^%^C101%^.%^CRST%^",caster);
    control = new("/d/magic/obj/swordremote");
    control->set_caster(caster);
    control->move(caster);
    control->set_property("spell",TO);
    control->set_property("spelled", ({TO}) );
    ob=new("/d/magic/obj/aobject.c");
    control->set_sword(ob);
    caster->add_follower(ob);
    ob->set_size(2);
    ob->set_long("%^RESET%^%^CRST%^%^C101%^The %^C096%^keen edges%^C101%^ of this %^C250%^he%^C247%^av%^C245%^y %^C243%^steel %^C245%^s%^C247%^wo%^C250%^rd%^RESET%^%^C101%^ are met by a powerful broad base attached to a sturdy hilt, its handle swathed in %^C243%^leather%^C101%^ with a decorative pommel at its top. The cross guard curves slightly at its tips and is otherwise unadorned.%^CRST%^");
    ob->set_short("%^RESET%^%^CRST%^%^C247%^a h%^C245%^ov%^C243%^e%^C243%^r%^C245%^in%^C247%^g s%^C245%^w%^C243%^o%^C245%^r%^C247%^d%^CRST%^");
    ob->set_name("seeking sword");
    ob->set_id(({"sword", "seeking sword"}));
    ob->add_id("summoned monster");
    ob->set_heart(1);
    ob->set_stats("intelligence",1);
    ob->add_limb("blade","blade",0,0,0);
    ob->add_limb("hilt","hilt",0,0,0);
    ob->set_attack_limbs(({"blade"}));
    ob->set_base_damage_type("slashing");
    ob->set_attacks_num((clevel/7)+1); //was clevel/7, but that didn't
//work since clerics get this earlier than level 7 ~Circe~ 4/22/08
    ob->set_damage(1,(clevel/2));
    ob->set_overall_ac(5-clevel);
    ob->set_hd(clevel);
    ob->set_hp(clevel*10);
    //ob->set_exp(100);
    ob->set_stats("strength",18+(clevel/6));
    ob->set_max_hp(ob->query_hp());
    ob->set_caster(caster);
    ob->set_property("spell",TO);
    ob->set_property("spell", ({TO}) );
    ob->set_property("spell_creature", TO);
    ob->set_property("effective_enchantment", ((int)CLEVEL / 7));
    ob->set_property("minion", caster);
    ob->move(environment(caster));
	caster->set_property("seeking_sword",ob);
    addSpellToCaster();
    return;
}

void dest_effect()
{
    object sword;

    if (objectp(caster)) {
        tell_room(environment(caster),"%^CRST%^%^RESET%^%^C101%^The %^C243%^s%^C245%^w%^C247%^o%^C245%^r%^C243%^d%^RESET%^%^C101%^ in front of "+caster->QCN+"%^CRST%^%^RESET%^%^C101%^ fades away.%^CRST%^",caster);
        tell_object(caster,"%^CRST%^%^RESET%^%^C101%^Your %^C243%^s%^C245%^w%^C247%^o%^C245%^r%^C243%^d%^RESET%^%^C101%^ fades away.%^CRST%^");
    }

    //sword = control->query_sword();
	if(objectp(control))
	{
		if (objectp(sword = control->query_sword()))
		{
			sword->remove();
			destruct(control);
		}
	}
	if(objectp(caster)) { caster->remove_property("seeking_sword"); }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
