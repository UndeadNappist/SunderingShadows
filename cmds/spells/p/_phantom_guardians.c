//forced them to unprotect in dest effect to prevent further problems with
//weapons trainers thinking that they were still protecting you after they've
//been dispelled/destroyed.  12/9/04 -Tsera
// moved monster files to /d/magic/mon central location Ares/Styx 1/29/05
#include <std.h>
#include <magic.h>
inherit SPELL;

object *mons = ({});

void create() {
    ::create();
    set_spell_name("phantom guardians");
    set_spell_level(([ "mage" : 6, "magus" : 6 ]));
    set_spell_sphere("illusion");
    set_syntax("cast CLASS phantom guardians on <centaurs|bats|soldiers>");
    set_description("This spell creates casting level relative guardians who will guard the caster blindly.  You have the "
"choice of 3 types: one greater summon centaur, four standard summon soldiers or 5 + clevel / 5 lesser summon bats. These guardians will not be effected by area effect spells.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    summon_spell();
    set_helpful_spell(1);
}

string query_casting_string() {
    return "%^BOLD%^%^GREEN%^"+caster->QCN+" caresses a statue and focuses on a couple large emeralds while chanting.";
}

int preSpell() {
    if (present(caster->query_name()+"phantommonster",place)) {
        tell_object(caster,"You can't summon multiple sets of guardians.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    object ob;
    int i, num;
    tell_room(place,"%^GREEN%^"+caster->QCN+" chants loudly and throws the emeralds into the air.",caster);
    tell_object(caster,"%^GREEN%^You chant loudly and throw the emeralds into the air.");
    tell_room(place,"%^B_GREEN%^The emeralds start to glow and shape themselves.%^RESET%^");

    if(!arg||!stringp(arg)) { arg = "soldiers"; }

    switch (arg) {
    case "centaurs":
        tell_room(place,"%^B_GREEN%^The emeralds shape into a glowing translucent centaur.");
        ob = new("/d/magic/mon/pcentaur");
        ob->move(place);
        ob->set_owner(caster);
        ob->setup_minion(clevel, spell_level, "greater");
        //caster->add_protector(ob);
        //ob->force_me("protect "+caster->query_name());
        //ob->force_me("protect "+caster->query_name());
        //ob->set_damage_bonus(clevel/8);
        //ob->set_attack_bonus(clevel/3);
        //ob->set_max_hp((query_spell_level(spell_type)*2+clevel)*12+20);
        //ob->set_hp(ob->query_max_hp());
        //ob->set_attacks_num(3);
        //ob->set_exp(0);
        //caster->add_follower(ob);
        ob->set_property("spelled", ({TO}) );
        ob->set_property("spell_creature", TO);
        ob->set_property("spell", TO);
        //ob->set_property("minion", caster);
        //ob->add_id("summoned monster");
        ob->add_id(caster->query_name()+"phantommonster");
        mons += ({ob});
        break;
    case "bats":
        num = 5 + clevel / 5;
        tell_room(place,"%^B_GREEN%^The emeralds shape into "+num+" glowing translucent bats.");
        for (i=0;i<num;i++) {

            ob = new("/d/magic/mon/pbat");
            ob->set_owner(caster);
            ob->setup_minion(clevel, spell_level, "lesser");
            ob->move(place);
            caster->add_protector(ob);
            //ob->force_me("protect "+caster->query_name());
            //ob->force_me("protect "+caster->query_name());
            ob->set_property("spelled", ({TO}) );
            ob->set_property("spell_creature", TO);
            ob->set_property("spell", TO);
            ob->set_property("minion", caster);
            //ob->set_damage_bonus(clevel/5);
            //ob->set_attack_bonus(clevel/5);
            //ob->set_max_hp((query_spell_level(spell_type)*2+clevel)*10+20);
            //ob->set_hp(ob->query_max_hp());
            ob->set_attacks_num(1);
            ob->set_exp(0);
            //ob->add_id("summoned monster");
            ob->add_id(caster->query_name()+"phantommonster");
            caster->add_follower(ob);
            mons += ({ob});
        }
        break;
    default:
        num = 4;
        tell_room(place,"%^B_GREEN%^The emeralds shape into "+prof/25+" glowing translucent soldiers.");
        for (i=0;i<num;i++) {

            ob = new("/d/magic/mon/psoldier");
            ob->set_owner(caster);
            ob->setup_minion(clevel, spell_level, "standard");
            ob->move(place);
            //caster->add_protector(ob);
            //ob->force_me("protect "+caster->query_name());
            //ob->force_me("protect "+caster->query_name());
            ob->set_property("spelled", ({TO}) );
            ob->set_property("spell_creature", TO);
            ob->set_property("spell", TO);
            ob->set_property("minion", caster);
            //ob->set_damage_bonus(clevel/4);
            //ob->set_attack_bonus(clevel/4);
            //ob->set_max_hp((query_spell_level(spell_type)*2+clevel)*12+20);
            //ob->set_hp(ob->query_max_hp());
            ob->set_attacks_num(2);
            //ob->set_exp(0);
            //ob->add_id("summoned monster");
            ob->add_id(caster->query_name()+"phantommonster");
            mons += ({ob});
            caster->add_follower(ob);
        }
        break;
    }
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
    call_out("check", ROUND_LENGTH);
}

void check()
{
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    
    mons = filter_array(mons, (: objectp($1) :));
    
    if(!sizeof(mons))
    {
        dest_effect();
        return;
    }
    
    call_out("check", ROUND_LENGTH);
}

void dest_effect() {
    int i;
    for (i=0;i<sizeof(mons);i++) {
        if (objectp(mons[i]))
        {
            if(objectp(caster))
            {
                caster->remove_protector(mons[i]);
            }
            mons[i]->die();
        }
    }
    removeSpellFromCaster();
    ::dest_effect();
    if(objectp(TO))
    {
	   TO->move("/d/shadowgate/void");
         TO->remove();
    }
}

void reverse_spell(){
    int i;
    spell_effect(100);
    for (i=0;i<sizeof(mons);i++) {
        if (objectp(mons[i])) {
            mons[i]->force_me("scream in rage");
            mons[i]->add_attacker(caster);
        }
    }
   removeSpellFromCaster();
}
