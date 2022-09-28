// lowlevel conjuration school specialty spell. Nienne, 11/09.
#include <std.h>
#include <magic.h>
#include <daemons.h>
#include <priest.h>
inherit SPELL;

object* inven, * caught;
int worked, duration, mydam;
void do_tentacles();

void create()
{
    ::create();
    set_author("nienne");
    set_spell_name("black tentacles");
    set_spell_level(([ "mage" : 4, "warlock" : 3, "magus" : 4, "cleric" : 4 ]));
    set_domains("nightmare");
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS black tentacles");
    set_description("This spell summons up a mass of writhing black " +
                    "tentacles from the earth at your feet. These will " +
                    "ensnare anything nearby to slow their escape, and attempt to " +
                    "knock them from their feet.");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(3);
    // school specific mage spell
    set_components(([
                        "mage" : ([ "carbon" : 1, ]),
                        ]));
    set_feats_required(([ "warlock" : "tome of ancient secrets"]));
}

int preSpell()
{
    if ((int)CASTER->query_property("black tentacles")) {
        tell_object(CASTER, "%^RESET%^%^C241%^You are already maintaining such a spell!%^CRST%^");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
    tell_object(caster, "%^RESET%^%^C241%^You kneel down, %^RESET%^%^C039%^w%^C045%^h%^C051%^i%^C087%^s%^C123%^p%^C159%^e%^C087%^r%^C051%^i%^C045%^n%^C039%^g %^RESET%^%^C241%^your summons through the %^RESET%^%^C094%^e%^C130%^a%^C136%^r%^C130%^t%^C094%^h%^RESET%^%^C241%^.%^CRST%^");
    tell_room(place, "%^RESET%^%^C241%^Kneeling, " + caster->QCN + " %^RESET%^%^C051%^w%^C087%^h%^C123%^i%^C159%^s%^C195%^p%^C123%^e%^C087%^r%^C051%^s %^RESET%^%^C241%^a summoning through the %^RESET%^%^C094%^e%^C130%^a%^C136%^r%^C130%^t%^C094%^h%^RESET%^%^C241%^.%^RESET%^", caster);
    return "display";
}

void spell_effect(int prof)
{
    int i;

    caught = ({});
    inven = target_selector();
    inven -= ({ caster });

    if (!sizeof(inven)) {
        tell_object(caster, "%^RESET%^%^C241%^From just beneath the %^RESET%^%^C094%^e%^C130%^a%^C136%^r%^C130%^t%^C094%^h %^RESET%^%^C241%^at your feet, you feel the shiver of the %^RESET%^%^C240%^t%^C241%^e%^C242%^n%^C241%^t%^C240%^a%^C241%^c%^C242%^l%^C241%^e%^C240%^s %^RESET%^%^C241%^as they find no target to ensnare, and simply %^RESET%^%^C240%^f%^C244%^a%^C248%^d%^C252%^e %^RESET%^%^C241%^away.%^CRST%^");
        dest_effect();
        return;
    }
    worked = 1;
    CASTER->set_property("black tentacles", 1);
    mydam = 4 + (clevel / 2);

    tell_room(environment(caster), "%^RESET%^%^C240%^R%^C241%^u%^C242%^b%^C241%^b%^C240%^e%^C241%^r%^C242%^y %^RESET%^%^C241%^b%^C240%^l%^C241%^a%^C242%^c%^C241%^k %^RESET%^%^C240%^t%^C241%^e%^C242%^n%^C241%^t%^C240%^a%^C241%^c%^C242%^l%^C241%^e%^C240%^s %^RESET%^%^C241%^writhe up out of the %^RESET%^%^C094%^e%^C130%^a%^C136%^r%^C130%^t%^C094%^h%^RESET%^%^C241%^, coiling and grasping at anything within reach!%^CRST%^");

    for (i = 0; i < sizeof(inven); i++) {
        if (!objectp(inven[i])) {
            continue;
        }
        if (random((int)inven[i]->query_stats("strength") +
                   roll_dice(1, 20)) < random(clevel + 8)) {
            tell_object(inven[i], "%^RESET%^%^C241%^One manages to wrap about your leg and %^RESET%^%^C240%^e%^C241%^n%^C242%^s%^C243%^n%^C242%^a%^C241%^r%^C240%^e %^RESET%^%^C241%^you!%^CRST%^");

            tell_room(place, "%^RESET%^%^C241%^One manages to wrap about " +
                      inven[i]->QCN + "%^RESET%^%^C241%^'s leg and ensnare " +
                      inven[i]->QO + "%^RESET%^%^C241%^!%^CRST%^", inven[i]);

            inven[i]->set_property("added short",
                                   ({ "%^RESET%^%^C241%^ (entangled)%^CRST%^" }));
            caught += ({ inven[i] });
            continue;
        }
        if (random((int)inven[i]->query_stats("dexterity") +
                   1) < roll_dice(1, 25) && random(2)) {
            tell_object(inven[i], "%^RESET%^%^C241%^You stumble as one of the %^RESET%^%^C240%^t%^C241%^e%^C242%^n%^C241%^t%^C240%^a%^C241%^c%^C242%^l%^C241%^e%^C240%^s %^RESET%^%^C241%^almost knocks you from your feet!%^CRST%^");

            tell_room(place, "%^RESET%^%^C241%^" + inven[i]->QCN +
                      " %^RESET%^%^C241%^stumbles as a %^RESET%^%^C240%^t%^C241%^e%^C242%^n%^C241%^t%^C240%^a%^C241%^c%^C242%^l%^C241%^e %^RESET%^%^C241%^knocks " + inven[i]->QO + " %^RESET%^%^C241%^from " +
                      inven[i]->QP + " %^RESET%^%^C241%^feet!%^CRST%^", inven[i]);

            inven[i]->set_tripped(1, "%^RESET%^%^C241%^You're regaining your %^RESET%^%^C049%^b%^C050%^a%^C051%^l%^C123%^a%^C051%^n%^C050%^c%^C049%^e%^RESET%^%^C241%^!%^CRST%^", 1);
            continue;
        }
    }
    addSpellToCaster();
    spell_successful();
    duration = (clevel / 10 + 3) * ROUND_LENGTH;
    call_out("do_tentacles", ROUND_LENGTH);
}

void do_tentacles()
{
    object* removing;
    int i;
    //tell_object(caster, "PLACE = "+identify(PLACE));
    if (!present(caster, PLACE)) {
        dest_effect();
        return;
    }
    if (caster->query_unconscious()) {
        dest_effect();
        return;
    }
    if (!sizeof(inven)) {
        dest_effect();
        return;
    }
    if (worked >= duration) {
        dest_effect();
        return;
    }
    worked++;
    removing = ({});
    for (i = 0; i < sizeof(inven); i++) {
        if (!objectp(inven[i])) {
            continue;
        }
        if (!present(inven[i], PLACE)) {
            inven[i]->remove_property_value("added short",
                                            ({ "%^GREEN%^ (entangled)%^RESET%^%^CYAN%^" }));
            removing += ({ inven[i] });
        }
    }
    inven -= removing;
    caught -= removing;

    if (!sizeof(inven)) {
        dest_effect();
        return;
    }
    removing = ({});
    if (sizeof(caught)) {
        for (i = 0; sizeof(caught) > 0, i < sizeof(caught); i++) {
            if (!objectp(caught[i])) {
                continue;
            }
            if (random(caught[i]->query_stats("strength") + roll_dice(1, 20)) < random(clevel + 8)) {
                tell_object(caught[i], "%^CYAN%^The tentacle squeezes the life from you!");
                tell_room(place, "%^CYAN%^The tentacle squeezes around " + caught[i]->QCN + "!", caught[i]);
                damage_targ(caught[i], caught[i]->return_target_limb(), mydam, "bludgeoning");
            }else {
                tell_object(caught[i], "%^CYAN%^You rip free of the tentacle!");
                tell_room(place, "%^CYAN%^" + caught[i]->QCN +
                          " rips free of the tentacle!", caught[i]);
                caught[i]->remove_property_value("added short", ({ "%^GREEN%^ (entangled)%^RESET%^%^CYAN%^" }));
                removing += ({ caught[i] });
            }
        }
    }
    caught -= removing;
    for (i = 0; i < sizeof(inven); i++) {
        if (!objectp(inven[i])) {
            continue;
        }
        if (inven[i]->query_tripped()) {
            continue;
        }
        if (random((int)inven[i]->query_stats("dexterity") + 1) < roll_dice(1, 25) && random(2)) {
            tell_object(inven[i], "%^CYAN%^You stumble as one of the " +
                        "tentacles almost knocks you from your feet!");
            tell_room(place, "%^CYAN%^" + inven[i]->QCN +
                      " stumbles as a tentacle knocks " + inven[i]->QO + " from " +
                      inven[i]->QP + " feet!", inven[i]);
            inven[i]->set_tripped(1, "%^BOLD%^%^CYAN%^You're regaining your " +
                                  "balance!%^RESET%^", 1);
        }
    }
    call_out("do_tentacles", ROUND_LENGTH);
}

void dest_effect()
{
    int i;
    if (worked) {
        tell_room(place, "%^CYAN%^The writhing tentacles shiver " +
                  "and crumble into dust, fading before your eyes.%^RESET%^");
        for (i = 0; i < sizeof(inven); i++) {
            if (!objectp(inven[i])) {
                continue;
            }
            inven[i]->remove_property_value("added short",
                                            ({ "%^GREEN%^ (entangled)%^RESET%^%^CYAN%^" }));
        }
        if (objectp(CASTER)) {
            CASTER->set_property("black tentacles", -1);
        }
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
