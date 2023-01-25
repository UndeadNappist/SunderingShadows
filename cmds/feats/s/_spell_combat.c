#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    set_author("wedex");
    feat_type("instant");
    feat_category("Steel&Magic");
    feat_name("spell combat");
    feat_prereq("Magus L1");
    feat_syntax("spell_combat");
    feat_desc("A magus learns to cast spells and fight with his weapon at the same time. The magus must have one hand free, while wielding a light or one-handed melee weapon in the other hand. The spell potency has a penalty but it is lessened at 8th level and again at 14th level. This will only work with spells from the magus spell list.");
    set_required_for(({ "enruned shield", "enruned offhand", "enruned great weapon" }));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }
    if(!ob->is_class("magus"))
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_spell_combat(string str)
{
    object feat, * wielded;
    if(!objectp(TP)) { return 0; }
    if ((int)TP->is_wearing_type("shield") && !TP->query_property("enruned shield"))
    {
        tell_object(TP, "%^RESET%^%^CRST%^%^C059%^You can't be wearing a shield.%^CRST%^");
        return 1;
    }
    wielded = (object*)TP->query_wielded();
    
    if(!sizeof(wielded))
        return notify_fail("You need to be wielding at least one weapon to use spell combat.");
    
    /*
    if (!sizeof(wielded) || //no weapons
        //wielded[0]->is_lrweapon() || //is ranged
        (sizeof(wielded) == 2 && //using both hands and...
            ((wielded[0] != wielded[1] && !TP->query_property("enruned offhand")) || //weapons are different and no feat
                (wielded[0] == wielded[1] && !TP->query_property("enruned great weapon")) //same weapon and no feat
            )))
    {
        tell_object(TP, "%^RESET%^%^BOLD%^You must be wielding a single one-handed melee weapon.%^RESET%^");
        return 1;
    }
    */
    feat = new(base_name(TO));
    feat->setup_feat(TP, str);
    return 1;
}

void execute_feat()
{
    object obj;

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }

    if(FEATS_D->is_active(caster,"spell combat"))
    {
        obj = query_active_feat("spell combat");
        tell_object(caster, "%^RESET%^%^CRST%^%^C020%^You release your %^C026%^c%^C027%^o%^C032%^n%^C027%^c%^C026%^e%^C027%^n%^C032%^t%^C027%^r%^C026%^a%^C027%^t%^C032%^i%^C027%^o%^C026%^n%^RESET%^%^C020%^.%^CRST%^");
        obj->dest_effect();
        if (userp(caster))
        {
            caster->gmcp_update_character("resources", ([ "spell_combat": 0 ]));
        }
        return;
    }
    ::execute_feat();

    tell_object(caster, "%^RESET%^%^CRST%^%^C020%^You combine your %^C118%^m%^C112%^ag%^C106%^i%^C118%^c%^C112%^al %^C106%^a%^C118%^b%^C112%^il%^C106%^i%^C118%^t%^C112%^y %^RESET%^%^C020%^and %^C026%^m%^C027%^a%^C032%^r%^C027%^t%^C032%^i%^C027%^a%^C026%^l p%^C027%^r%^C032%^o%^C027%^w%^C032%^e%^C027%^s%^C026%^s%^RESET%^%^C020%^.%^CRST%^");
    caster->set_property("active_feats",({TO}));
    caster->set_property("magus cast", 1);
    if (userp(caster))
    {
        caster->gmcp_update_character("resources", ([ "spell_combat": 1 ]));
    }
    
    return;
}

void dest_effect()
{
    object me = this_object();

    if(objectp(caster))
    {
        caster->remove_property_value("active_feats",({TO}));
        caster->remove_property("magus cast");
        tell_object(caster, "%^RESET%^%^CRST%^%^C020%^Your %^C026%^c%^C027%^o%^C032%^n%^C027%^c%^C026%^e%^C027%^n%^C032%^t%^C027%^r%^C026%^a%^C027%^t%^C032%^i%^C027%^o%^C026%^n%^RESET%^%^C020%^ fades.%^CRST%^");
    }

    me->gmcp_update_character("resources", ([ "spell_combat": 0 ]));

    ::dest_effect();
    remove_feat(me);

    return;
}

