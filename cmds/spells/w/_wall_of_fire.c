//      Wall of fire
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
    set_spell_name("wall of fire");
    set_spell_level(([ "mage" : 4, "monk" : 13, "oracle" : 4, "magus" : 4, "druid" : 5, "cleric" : 5 ]));
    set_mystery(({"battle"}));
    set_circle("wildfire");
    set_domains("fire");
    set_spell_sphere("invocation_evocation");
    set_monk_way("way of the elements");
    set_syntax("cast CLASS wall of fire [on <exit>]");
    set_description("The spell, wall of fire, is an impressive spell for the magi indeed. The wizard can cast the wall around himself, protectively, or in front of an exit, so all who pass through that exit will be scorched by the flames. To cast the wall around him/herself, the mage simply types <cast classname wall of fire>. Otherwise, the mage might type <cast classname wall of fire on north> to damage those passing through the exit. Be warned however, the mage who casts this spell must keep concentration on the wall to maintain its existence. The mage may type <remove wall> to quench the flames. A versatile arcanist can manipulate the base element of this spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_components(([
      "mage" : ([ "phosphorus":1, ]),
    ]));
    set_helpful_spell(1);
    traveling_spell(1); // For damage calculations only
}

string query_cast_string(){
    tell_object(caster, "%^RESET%^%^CRST%^%^C250%^You stretch your arms %^C254%^outward%^C250%^, hands spread open and %^C247%^c%^C244%^h%^C247%^a%^C244%^n%^C247%^t%^C244%^i%^C247%^n%^C244%^g %^C255%^mightily%^C250%^.%^CRST%^");
    tell_room(place, "%^RESET%^%^CRST%^%^C250%^"+caster->QCN+"%^RESET%^%^CRST%^%^C250%^ stretches "+caster->QP+" arms outward, hands spread open and %^C247%^c%^C244%^h%^C247%^a%^C244%^n%^C247%^t%^C244%^i%^C247%^n%^C244%^g %^C255%^mightily%^C250%^.%^CRST%^", caster);
    return "display";
}

void spell_effect(int prof) {
    string *outs, *ins, *limbs, arg;
    object *exits, *inexits, *burned;
    int i, j;
    ::spell_effect();

    hpcount=caster->query_hp();
    if(arg && arg != "" && arg != " ") { arg=lower_case(arg); }

    element = (string)caster->query("elementalist");
    // force-type to fire if anything outside the normal five-element subset. Since the non-interactive doesn't have a switch to fix this, it's necessary.
    if(element != "acid" && element != "cold" && element != "electricity" && element != "sonic") element = "fire";

    if (member_array(arg,place->query_exits()) < 0) {
        switch(element) {
            case "acid":
                tell_object(caster,"%^RESET%^%^CRST%^%^C064%^A cloud of hissing %^C190%^vapor %^C064%^rises up around you.%^CRST%^");
                tell_room(place,"%^RESET%^%^CRST%^%^C064%^A cloud of hissing %^C190%^vapor %^C064%^rises up around "+caster->QCN+"%^RESET%^%^CRST%^%^C064%^!%^CRST%^", caster);
                wall=new("/d/magic/obj/vaporcloud.c");
                break;
            case "cold":
                tell_object(caster,"%^RESET%^%^CRST%^%^C036%^An aura of %^C051%^chilling air %^RESET%^%^C036%^rises up around you.%^CRST%^");
                tell_room(place,"%^RESET%^%^CRST%^%^C036%^An aura of %^C051%^chilling air %^RESET%^%^C036%^rises up around "+caster->QCN+"%^RESET%^%^CRST%^%^C036%^!%^CRST%^", caster);
                wall=new("/d/magic/obj/frostcloud.c");
                break;
            case "electricity":
                tell_object(caster,"%^RESET%^%^CRST%^%^C101%^The air around you seems to come to life, and arcs of %^C228%^el%^C230%^e%^C228%^ctr%^C230%^ic%^C228%^it%^C230%^y %^RESET%^%^C101%^crackle around you!%^CRST%^");
                tell_room(place,"%^RESET%^%^CRST%^%^C101%^The air around you seems to come to life, and arcs of %^C228%^el%^C230%^e%^C228%^ctr%^C230%^ic%^C228%^it%^C230%^y %^RESET%^%^C101%^crackle around "+caster->QCN+"%^RESET%^%^CRST%^%^C101%^!%^CRST%^", caster);
                wall=new("/d/magic/obj/staticfield.c");
                break;
            case "sonic":
                tell_object(caster,"%^RESET%^%^CRST%^%^C091%^The air around you takes on a %^C135%^dull hum%^C091%^.%^CRST%^");
                tell_room(place,"%^RESET%^%^CRST%^%^C091%^The air around "+caster->QCN+"%^RESET%^%^CRST%^%^C091%^ takes on a %^C135%^dull hum%^C091%^.%^CRST%^", caster);
                wall=new("/d/magic/obj/sonicshield.c");
                break;
            default:
                tell_object(caster,"%^RESET%^%^CRST%^%^C124%^A massive ring of %^C091%^vi%^C097%^o%^C091%^le%^C097%^t %^C091%^f%^C097%^i%^C091%^re %^C124%^rises up around you.%^CRST%^");
                tell_room(place,"%^RESET%^%^CRST%^%^C124%^A massive ring of %^C091%^vi%^C097%^o%^C091%^le%^C097%^t %^C091%^f%^C097%^i%^C091%^re %^C124%^rises up around "+caster->QCN+"%^RESET%^%^CRST%^%^C124%^!%^CRST%^", caster);
                wall=new("/d/magic/obj/firewall.c");
                break;
        }
        wall->set_property("spell",TO);
        wall->set_property("spelled", ({TO}) );
        wall->move(place);
        wall->surround(caster,TO);
        return;
    }
    switch(element) {
        case "acid": wall=new("/d/magic/obj/vaporcloud.c"); break;
        case "cold": wall=new("/d/magic/obj/frostcloud.c"); break;
        case "electricity": wall=new("/d/magic/obj/staticfield.c"); break;
        case "sonic": wall=new("/d/magic/obj/sonicshield.c"); break;
        default: wall=new("/d/magic/obj/firewall.c"); break;
    }
    wall->set_property("spell",TO);
    wall->set_property("spelled", ({TO}) );
    wall->block(caster,arg,TO);
    if (objectp(wall)) wall->move(place);
    else return;

    switch(element) {
        case "acid":
            tell_room(place,"%^RESET%^%^CRST%^%^C064%^A cloud of hissing %^C190%^vapor %^C064%^rises up, blocking the "+arg+"!%^CRST%^");
            break;
        case "cold":
            tell_room(place,"%^RESET%^%^CRST%^%^C036%^A cloud of %^C051%^chilling air %^C036%^rises up, blocking the "+arg+"!%^CRST%^");
            break;
        case "electricity":
            tell_room(place,"%^RESET%^%^CRST%^%^C101%^The air around you seems to come to life, and arcs of %^C228%^el%^C230%^e%^C228%^ctr%^C230%^ic%^C228%^it%^C230%^y %^RESET%^%^C101%^crackle before the "+arg+".%^CRST%^");
            break;
        case "sonic":
            tell_room(place,"%^RESET%^%^CRST%^%^C091%^The air near the "+arg+" takes on a %^C135%^dull hum%^C091%^!%^CRST%^");
            break;
        default:
            tell_room(place,"%^RESET%^%^CRST%^%^C124%^A wall of blazing %^C091%^vi%^C097%^o%^C091%^le%^C097%^t %^C091%^f%^C097%^l%^C091%^am%^C097%^e%^C091%^s %^RESET%^%^C124%^rises up, blocking the "+arg+"!%^CRST%^");
            break;
    }
    outside = find_object_or_load(place->query_exit(arg));
    ins = outside->query_exits();
    for (i=0;i<sizeof(ins);i++) {
        if(base_name(place) == (string)outside->query_exit(ins[i]) || base_name(place)+".c" == (string)outside->query_exit(ins[i]) || base_name(place) == (string)outside->query_exit(ins[i])+".c") {
            switch(element) {
                case "acid": wall2=new("/d/magic/obj/vaporcloud.c"); break;
                case "cold": wall2=new("/d/magic/obj/frostcloud.c"); break;
                case "electricity": wall2=new("/d/magic/obj/staticfield.c"); break;
                case "sonic": wall2=new("/d/magic/obj/sonicshield.c"); break;
                default: wall2=new("/d/magic/obj/firewall.c"); break;
            }
            wall2->set_property("spell",TO);
            wall2->block(caster,ins[i],TO);
            wall2->move(outside);
            switch(element) {
                case "acid":
                    tell_room(outside,"%^RESET%^%^CRST%^%^C064%^A cloud of hissing %^C190%^vapor %^RESET%^%^C064%^rises up, blocking the "+ins[i]+"!%^CRST%^\n%^RESET%^%^CRST%^%^C190%^Acid %^C064%^spits out of the cloud towards you!%^CRST%^");
                    break;
                case "cold":
                    tell_room(outside,"%^RESET%^%^CRST%^%^C036%^A cloud of %^C051%^chilling air %^C036%^rises up, blocking the "+ins[i]+"!%^CRST%^\n%^RESET%^%^CRST%^%^C051%^Shards of frost %^C036%^spit out of the cloud towards you!%^CRST%^");
                    break;
                case "electricity":
                    tell_room(outside,"%^RESET%^%^CRST%^%^C101%^A crackling field of %^C228%^el%^C230%^e%^C228%^ctr%^C230%^ic%^C228%^it%^C230%^y %^RESET%^%^C101%^appears in the air before the "+ins[i]+".%^CRST%^\n%^RESET%^%^CRST%^%^C101%^Arcs of %^C228%^st%^C230%^a%^C226%^t%^C230%^i%^C228%^c %^RESET%^%^C101%^leap out of the field towards you!%^CRST%^");
                    break;
                case "sonic":
                    tell_room(outside,"%^RESET%^%^CRST%^%^C091%^The air near the "+ins[i]+" takes on a %^C135%^dull hum%^C091%^!%^CRST%^\n%^RESET%^%^CRST%^%^C135%^Pulses of sound %^C091%^echo towards you!%^CRST%^");
                    break;
                default:
                    tell_room(outside,"%^RESET%^%^CRST%^%^C124%^A wall of blazing %^C091%^vi%^C097%^o%^C091%^le%^C097%^t %^C091%^f%^C097%^l%^C091%^am%^C097%^e%^C091%^s %^RESET%^%^C124%^rises up, blocking the "+ins[i]+"!%^CRST%^\n%^RESET%^%^CRST%^%^C091%^F%^C097%^l%^C091%^am%^C097%^e%^C091%^s %^RESET%^%^C124%^spit out of the wall towards you!%^CRST%^");
                    break;
            }
            burned = all_inventory(outside);
            for (j=0;j<sizeof(all_inventory(outside));j++) {
                if ( living(burned[j]) ) {
                    switch(element) {
                        case "acid":
                            tell_room(outside,"%^RESET%^%^CRST%^%^C064%^"+burned[j]->QCN+"%^RESET%^%^CRST%^%^C064%^ recoils from the hissing %^C190%^vapor%^C064%^!%^CRST%^",burned[j]);
                            tell_object(burned[j],"%^RESET%^%^CRST%^%^C064%^The %^C190%^vapor %^C064%^burns your skin!%^CRST%^");
                            break;
                        case "cold":
                            tell_room(outside,"%^RESET%^%^CRST%^%^C036%^"+burned[j]->QCN+"%^RESET%^%^CRST%^%^C036%^ recoils from the %^C051%^freezing air%^C036%^!%^CRST%^",burned[j]);
                            tell_object(burned[j],"%^RESET%^%^CRST%^%^C036%^The %^C051%^freezing air %^C036%^chills you!%^CRST%^");
                            break;
                        case "electricity":
                            tell_room(outside,"%^RESET%^%^CRST%^%^C101%^"+burned[j]->QCN+"%^RESET%^%^CRST%^%^C101%^ recoils from the %^C228%^cr%^C230%^a%^C228%^ckl%^C230%^i%^C228%^ng a%^C230%^i%^C228%^r%^RESET%^%^C101%^!%^CRST%^",burned[j]);
                            tell_object(burned[j],"%^RESET%^%^CRST%^%^C101%^The %^C228%^ch%^C230%^a%^C228%^rg%^C230%^e%^C228%^d a%^C230%^i%^C228%^r %^RESET%^%^C101%^crackles across your skin!%^CRST%^");
                            break;
                        case "sonic":
                            tell_room(outside,"%^RESET%^%^CRST%^%^C091%^"+burned[j]->QCN+"%^RESET%^%^CRST%^%^C091%^ recoils from the %^C135%^humming air%^C091%^!%^CRST%^",burned[j]);
                            tell_object(burned[j],"%^RESET%^%^CRST%^%^C091%^The %^C135%^humming air %^RESET%^%^C091%^reverberates through you!%^CRST%^");
                            break;
                        default:
                            tell_room(outside,"%^RESET%^%^CRST%^%^C124%^"+burned[j]->QCN+"%^RESET%^%^CRST%^%^C124%^ is struck by the searing-hot %^C091%^f%^C097%^l%^C091%^am%^C097%^e%^C124%^!%^CRST%^",burned[j]);
                            tell_object(burned[j],"%^RESET%^%^CRST%^%^C124%^The %^C091%^f%^C097%^l%^C091%^am%^C097%^e%^C091%^s %^RESET%^%^C124%^from the wall strike you forcefully, and your skin is coated in a sheet of fire!");
                            break;
                    }
                    limbs = burned[j]->query_limbs();
                    if(burned[j]->query_property("undead")) damage_targ(burned[j],limbs[random(sizeof(limbs))],(4+random(13)),element);
                    else damage_targ(burned[j],limbs[random(sizeof(limbs))],(2+random(7)),element);
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
            tell_room(environment(caster),"%^RESET%^%^CRST%^%^C100%^"+caster->QCN+"%^RESET%^%^CRST%^%^C100%^ looks as though "+caster->QS+" just lost "+caster->QP+" concentration!%^CRST%^",caster);
            tell_object(caster,"%^RESET%^%^CRST%^%^C100%^You lose your concentration on maintaining the wall of "+element+" you invoked!%^CRST%^");
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
