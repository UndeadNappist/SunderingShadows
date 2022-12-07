// at present, on parity with wall of fire. Should be upgraded when that is.
#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

int i, hpcount;
string tempstr, element;
object endplace, outside, wall, wall2;

string *dir_listing(string tempfil);

void create() {
    ::create();
    set_spell_name("wall of perilous fire");
    set_spell_level(([ "warlock" : 3 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS wall of perilous fire [on <exit>]");
    set_description("This invocation is quite similar to the mage spell 'wall of fire', save that it is conjured purely of planar energy. It allows the caster to create a wall of brilliant blue flames around himself, protectively, or in front of an exit, so all who pass through that exit will be scorched by the flames. Half of the damage done is fire, but the rest results from supernatural power and cannot be resisted. The warlock who casts this spell must keep concentration on the wall to maintain its existence, and may type <remove wall> to quench the flames.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

string query_cast_string() 
{
    tell_object(caster,"%^RESET%^%^CRST%^%^C124%^You lift a hand to direct your %^C024%^in%^C023%^vo%^C030%^ca%^C024%^ti%^C023%^on %^RESET%^%^C124%^with a %^C160%^fingertip%^C124%^.%^CRST%^");
    if(objectp(place)) { tell_room(place,"%^RESET%^%^CRST%^%^C124%^"+caster->QCN+"%^RESET%^%^CRST%^%^C124%^ lifts a hand to direct "+caster->QP+" %^C024%^in%^C023%^vo%^C030%^ca%^C024%^ti%^C023%^on %^RESET%^%^C124%^with a %^C160%^fingertip%^C124%^.%^CRST%^",caster); }
    return "display";
}

void spell_effect(int prof) {
    string *outs, *ins, *limbs;
    object *exits, *inexits, *burned;
    int i, j, dmg;
    ::spell_effect();

    hpcount=caster->query_hp();
    if(arg && arg != "" && arg != " ") arg=lower_case(arg);

    if (member_array(arg,place->query_exits()) < 0) {
        tell_object(caster,"%^RESET%^%^CRST%^%^C124%^As your finger motions out an arc, a ring of %^C024%^ee%^C023%^ri%^C030%^e c%^C024%^ob%^C023%^al%^C030%^t f%^C024%^la%^C023%^me %^RESET%^%^C124%^rises up around you!%^CRST%^");
        tell_room(place,"%^RESET%^%^CRST%^%^C124%^As "+caster->QP+" finger motions out an arc, a ring of %^C024%^ee%^C023%^ri%^C030%^e c%^C024%^ob%^C023%^al%^C030%^t f%^C024%^la%^C023%^me %^RESET%^%^C124%^rises up around "+caster->QCN+"%^RESET%^%^CRST%^%^C124%^!%^CRST%^", caster);
        wall=new("/d/magic/obj/pfirewall.c");
        wall->set_property("spell",TO);
        wall->set_property("spelled", ({TO}) );
        wall->move(place);
        wall->surround(caster,TO);
        return;
    }
    wall=new("/d/magic/obj/pfirewall.c");
    wall->set_property("spell",TO);
    wall->set_property("spelled", ({TO}) );
    wall->block(caster,arg,TO);
    if (objectp(wall)) wall->move(place);
    else return;

    tell_object(caster,"%^RESET%^%^CRST%^%^C124%^As your finger motions out a line, a wall of %^C024%^ee%^C023%^ri%^C030%^e c%^C024%^ob%^C023%^al%^C030%^t f%^C024%^la%^C023%^me %^RESET%^%^C124%^rises up, blocking the "+arg+"!%^CRST%^");
    tell_room(place,"%^RESET%^%^CRST%^%^C124%^As "+caster->QCN+"%^RESET%^%^CRST%^%^C124%^'s finger motions out a line, a wall of %^C024%^ee%^C023%^ri%^C030%^e c%^C024%^ob%^C023%^al%^C030%^t f%^C024%^la%^C023%^me %^RESET%^%^C124%^rises up, blocking the "+arg+"!%^CRST%^",caster);
    outside = find_object_or_load(place->query_exit(arg));
    ins = outside->query_exits();
    for (i=0;i<sizeof(ins);i++) {
      if(base_name(place) == (string)outside->query_exit(ins[i]) || base_name(place)+".c" == (string)outside->query_exit(ins[i]) || base_name(place) == (string)outside->query_exit(ins[i])+".c") {
            wall2=new("/d/magic/obj/pfirewall.c");
            wall2->set_property("spell",TO);
            wall2->block(caster,ins[i],TO);
            wall2->move(outside);
            tell_room(outside,"%^RESET%^%^CRST%^%^C124%^A ring of %^C024%^ee%^C023%^ri%^C030%^e c%^C024%^ob%^C023%^al%^C030%^t f%^C024%^la%^C023%^me %^RESET%^%^C124%^rises up, blocking the "+ins[i]+"!\n%^RESET%^%^CRST%^%^C160%^%^Waves of heat roll off the wall of fire towards you!%^CRST%^%^");

            burned = all_inventory(outside);
            for (j=0;j<sizeof(all_inventory(outside));j++) {
                if ( living(burned[j]) ) {
                    tell_room(outside,"%^RESET%^%^CRST%^%^C160%^"+burned[j]->QCN+"%^RESET%^%^CRST%^%^C160%^ is burned by the wall's searing heat!%^CRST%^",burned[j]);
                    tell_object(burned[j],"%^RESET%^%^CRST%^%^C160%^The searing heat of the wall of flame burns you badly!%^CRST%^");
                    limbs = burned[j]->query_limbs();
                    if(burned[j]->query_property("undead")) dmg = 4+random(13);
                    else dmg = 2+random(7);
                    damage_targ(burned[j],limbs[random(sizeof(limbs))],dmg/2,"fire");
                    damage_targ(burned[j],limbs[random(sizeof(limbs))],dmg/2,"untyped");
                }
            }
            break;
      }
    }
    call_out("concentration",4);
    return;
}

void concentration() {
    int flag = 0;
    if ( caster->query_paralyzed() ||
         !objectp(wall) ||
         !objectp(wall2))
        flag = 1;
    if ((int)caster->query_hp() != hpcount) {
        if ((int)caster->query_hp() < hpcount - 30 ) {
            tell_room(environment(caster),"%^RESET%^%^CRST%^%^C124%^"+caster->QCN+"%^RESET%^%^CRST%^%^C124%^ looks as though "+caster->QS+" just lost "+caster->QP+" concentration!%^CRST%^",caster);
            tell_object(caster,"%^RESET%^%^CRST%^%^C124%^You lose your concentration on maintaining the wall of flames you invoked!%^CRST%^");
            flag = 1;
        } else
            hpcount = caster->query_hp();
    }
    if (flag)
        call_out("dest_effect",clevel*3);
    else
        call_out("concentration",4);
    return;
}

void dest_effect() {
    if (objectp(wall))
        wall->remove_wall();
    if (objectp(wall2))
        wall2->remove_wall();

    ::dest_effect();
    if(objectp(TO)) TO->remove();
    return;
}
