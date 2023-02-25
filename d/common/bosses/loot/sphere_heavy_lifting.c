// Orb of Heavy Lifting
// Written by Spade on 17 Jan. 2023

#include <std.h>
#include <daemons.h>

inherit OBJECT;

int active, active_weight;

void create()
{
    ::create();
    active_weight = -1 * (21 + random(10));
    set_id(({ "sphere", "glass sphere", "opalescent sphere", "sphere of heavy lifting"}));
    set_name("sphere of heavy lifting");
    // Sphere of Heavy Lifting
    set_short("%^C246%^S%^C219%^p%^C224%^h%^C246%^e%^C229%^r%^C194%^e%^C246%^ of H%^C158%^e%^C159%^a%^C246%^vy L%^C153%^i%^C189%^f%^C246%^t%^C225%^i%^C224%^n%^C246%^g");
    // A small glass sphere
    set_obvious_short("%^C061%^A small %^C037%^gl%^C044%^a%^C051%^s%^C044%^s%^C061%^ sphere");
    // Beams of light yield to the whims of a crystal lattice, producing a distorted vision of that which lies behind it.
    set_long("%^C061%^Beams of %^C159%^light%^RESET%^%^C061%^ yield to the whims of a %^C045%^c%^C051%^r%^C087%^y%^C045%^s%^C051%^t%^C087%^a%^C045%^l l%^C051%^a%^C087%^t%^C045%^t%^C051%^i%^C087%^c%^C045%^e%^CRST%^%^RESET%^%^C061%^, producing a %^C051%^d%^C045%^i%^C075%^st%^C069%^o%^C099%^rt%^C093%^ed%^RESET%^%^C061%^ vision of that which lies behind it.%^CRST%^");
    set_lore("It is speculated that the Sphere of Heavy lifting is the final complete artifact that Ar'tu Redine, renowned mage-psion, was able to complete before his sudden disappearance. Despite several papers being published on the spatial magic that powers such artifacts, no mage has yet been able to produce a working replica, relegating the supply to those few prototypes he left in his wake.");
    set_property("lore difficulty", 35);
    set_weight(2);
    set_value(5000 * -active_weight);
    set_heart_beat(1);
}

int is_orb_of_lifting()
{
    return 1;
}

void deep_orb_check()
{
    object* inv, * deep_inv, * orbs = ({}), * sacks = ({}), this_orb = this_object(), environment = environment(this_orb);
    int i, j, damage;

    if (!objectp(this_orb))
        return;

    if (!objectp(environment))
        return;

    if (!living(environment))
        return;

    inv = all_inventory(environment);

    if (!sizeof(inv))
        return;

    for (i = 0; i < sizeof(inv); i++)
    {
        if (!objectp(inv[i]))
            continue;

        if (!inv[i]->is_container())
            continue;

        deep_inv = all_inventory(inv[i]);

        if (!sizeof(deep_inv))
            continue;

        for (j = 0; j < sizeof(deep_inv); j++)
        {
            if (!objectp(deep_inv[j]))
                continue;

            if (deep_inv[j]->is_orb_of_lifting())
            {
                orbs += ({ deep_inv[j] });
                this_orb->remove();
                deep_inv[j]->remove();
                sacks += ({ inv[i] });
                tell_object(environment, "%^RED%^Despite your best efforts to prevent it, the " + this_orb->query_short() + "s %^RED%^merge with one another and blink out of existence!");
                tell_room(environment(environment), "%^RED%^Despite " + environment->query_cap_name() + "'s best efforts, the " + this_orb->query_short() + "s %^RED%^merge with one another and blink out of existence!", environment);
            }
        }
    }
    return;
}

void heart_beat()
{
    object this_orb = this_object(), ob, environment = environment(this_object());

    if (!objectp(environment))
        return;

    if (living(environment))
    {
        if (!active)
        {
            active = 1;
            // A dense veil of grey mist coalesces within the sphere, broken only by prismatic outpours of brilliance.
            tell_room(environment(environment), "%^C061%^A dense veil of %^C242%^gr%^C240%^e%^C242%^y m%^C240%^i%^C242%^st%^RESET%^%^C061%^ coalesces within the sphere, broken only by %^C255%^pr%^C213%^i%^C218%^s%^C255%^ma%^C223%^t%^C228%^i%^C255%^c ou%^C192%^t%^C157%^p%^C255%^ou%^C123%^r%^C051%^s%^RESET%^%^C061%^ of brilliance.%^CRST%^");
            // A scintillating opalescent sphere
            set_obvious_short("%^C246%^A sci%^C219%^n%^C224%^t%^C223%^i%^C228%^l%^C246%^lating op%^C192%^a%^C156%^l%^C121%^e%^C246%^s%^C085%^c%^C086%^e%^C246%^nt sp%^C081%^h%^C117%^e%^C153%^r%^C246%^e");
            // A circuitous network of veins glisten in chromatic rebellion against the blanket of grey below. Their recalcitrance permits glimspes into a demiplane much more chaotic than the view would suggest.
            set_long("%^C246%^A circuitous network of veins glisten in %^C196%^c%^C202%^h%^C208%^r%^C214%^o%^C220%^m%^C226%^a%^C190%^t%^C154%^i%^C118%^c%^C082%^ d%^C046%^e%^C047%^f%^C048%^i%^C049%^a%^C050%^n%^C051%^c%^C045%^e%^RESET%^%^C246%^ against the stormy grey below. Their rebellion permits glimpses into a plane much more %^C039%^c%^C045%^h%^C051%^a%^C087%^o%^C051%^t%^C045%^i%^C039%^c%^RESET%^%^C246%^ than the view would suggest.%^CRST%^");
            set_weight(active_weight);
        }

        if (!((ob = present("sphere of heavy lifting", environment)) && ob != this_orb))
        {
            deep_orb_check();
            return;
        }

        tell_object(environment, "%^RED%^Despite your best efforts to prevent it, the " + this_orb->query_short() + "s%^RED%^ merge with one another and blink out of existence!");
        tell_room(environment(environment), "%^RED%^Despite " + environment->query_cap_name() + "'s best efforts, the " + this_orb->query_short() + "s%^RED%^ merge with one another and blink out of existence!", environment);
        ob->remove();
        this_orb->remove();
    }

    else if (active)
    {
        active = 0;
        // With the sphere's task concluded, it once again becomes a mundane looking ball of glass.
        tell_room(environment, "%^C061%^With the sphere's task concluded, it once again becomes a mundane looking %^C051%^ba%^C123%^l%^C195%^l%^C061%^ of %^C051%^g%^C123%^la%^C195%^ss%^C061%^.%^CRST%^");
        // A scintillating opalescent sphere
        set_obvious_short("%^C061%^A small %^C037%^gl%^C044%^a%^C051%^s%^C044%^s%^C061%^ sphere");
        // A circuitous network of veins glisten in chromatic defiance against the stormy grey below. Their rebellion permits glimpses into a plane much more chaotic than this.
        set_long("%^C061%^Beams of %^C159%^light%^RESET%^%^C061%^ yield to the whims of a %^C159%^c%^C123%^r%^C087%^y%^C159%^s%^C123%^t%^C087%^a%^C159%^l l%^C123%^a%^C087%^t%^C159%^t%^C123%^i%^C087%^c%^C159%^e%^RESET%^%^C061%^, producing a %^C051%^d%^C045%^i%^C075%^st%^C069%^o%^C099%^rt%^C093%^ed%^RESET%^%^C061%^ vision of that which lies behind it.%^CRST%^");
        set_weight(2);
    }
}
