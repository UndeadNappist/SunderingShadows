//  /std/move.c
//  from the Nightmare mudlib
//  handles the moving and removing of objects
//  created by Descarte of Borg 18 february 1993

#include <move.h>
#include <std.h>

#define SMALL 7
#define MEDIUM 12
#define LARGE 17

#define VOID "/d/shadowgate/void"

private int encumbrance;
nosave private int no_clean;
private int size;
nosave private object last_location;

void strip_temp_values();

void set_size(int x) { size = x;}

int query_size() {
    if ( (size > 0) || (size == SIZE_UNIVERSAL) ) {
        return size;
    }
    if ((this_object()->is_weapon() || this_object()->is_armour())) {
       return SIZE_NORMAL; // If size is unset for weapons and armour, assume it's NORMAL sized.  Many armor and weapons don't have size set as part of course...
    } else {

        if (query_weight() < SMALL) {
            return 1;
        }
        if (query_weight() < MEDIUM) {
            return 2;
        }
        if (query_weight() < LARGE) {
            return 3;
        }
        return 4;
    }
}

int move(mixed dest)
{
    object me, environment, ob, prev;
    string str, msg;

    if ((!(me = this_object())) || !objectp(me))
        return MOVE_DESTRUCTED;

    environment = environment(me);

    if (stringp(dest))
    {
        ob = find_object_or_load(dest);
        if(!objectp(ob))
        {
            if(objectp(me))
            {
                msg = identify(me) + " attempted to move to invalid object.";
                if(objectp(environment)) { msg += " environment was "+identify(environment); }
            }
            else msg = "Invalid object attempted to move into invalid object.";
            return;
        }
    } else
        ob = dest;
    if (!ob)
        return MOVE_NOT_ALLOWED;
    if (!ob->receive_objects(me))
        return MOVE_NOT_ALLOWED;
    if (objectp(environment(me))) {
        if (!environment->loose_object(me)) return MOVE_NOT_ALLOWED;
    }
    if (living(me) && (living(ob) || ob->query("not living")) && !( (int)ob->move_ok() ))
        return MOVE_NOT_ALLOWED;
    if (!ob->add_encumbrance(query_weight()))
        return MOVE_NO_ROOM;
    if (environment(me))
    {
        if(me->is_player()) { environment(me)->add_encumbrance(-1*(int)me->query_player_weight()); }
        else { environment(me)->add_encumbrance(-1*query_weight()); }
    }
    set_last_location(environment(me));
    prev = environment;
    if(!objectp(me)) return MOVE_DESTRUCTED;
    if(!objectp(ob)) return MOVE_DESTRUCTED;
    move_object(ob);
    if(!objectp(me)) return MOVE_DESTRUCTED;
    ob->gain_item(me);

    if (ob->is_room() && me->is_player()) {
        ob->set_had_players();
    }

    if (objectp(prev)) {
        prev->loose_item(me);
    }

    if (objectp(me) && (interactive(me) || me->query_property("croom_track"))) {
        if (objectp(prev) && (!prev->query_property("croom_dirty"))) {
            prev->set_property("croom_dirty", 1);
        }

        if (!ob->query_property("croom_dirty")) {
            ob->set_property("croom_dirty", 1);
        }
    }
    return MOVE_OK;
}

int remove(){
    object env;
    object *inv;
    int i;

    if (!this_object() || !objectp(this_object())) return 0;
    
    env = environment(this_object());
    if (env) {
        env->add_encumbrance(-1*query_weight());
        i= sizeof(inv = all_inventory(this_object()));
        while (i--) inv[i]->move(env);
    }
	if(objectp(env))
	{
		if(living(env))
		{
			env->ApplyObjectBonuses(TO, env, "remove", "move");
		}
	}

    this_object()->set_property("combat_remove",1);
    this_object()->unequip();
    //!userp(this_object()) && this_object()->remove_property("added short");
    
    //This is to catch any lingering (temporary) added shorts
    strip_temp_values();
    
    if(catch(destruct(this_object())))
        return 0;
    
    return 1;
}

void strip_temp_values()
{
    object me;

    if (!objectp(me = this_object()))
        return;

    if(me->is_weapon())
    {
        me->remove_property("temp_hit_bonus");
        me->remove_property_value("added short",({ "%^RESET%^%^CYAN%^ %^BOLD%^{%^RESET%^%^CYAN%^vibrating%^BOLD%^}%^RESET%^" }));
        me->remove_property_value("added short", ({ "%^CYAN%^BOLD%^ {empowered}%^RESET%^" }) );
        me->remove_property_value("added short",({ "%^RESET%^%^CYAN%^ %^BOLD%^{%^RESET%^%^CYAN%^ablaze%^BOLD%^}%^RESET%^" }));
        me->remove_property_value("added short", ({ "%^CYAN%^BOLD%^ [bane]%^RESET%^" }) );
        me->remove_property_value("added short", ({ "%^BLACK%^BOLD%^ [%^GREEN%^eldritch%^BLACK%^]%^RESET%^" }) );
        me->remove_property_value("added short", ({ "%^MAGENTA%^ {vampiric}%^RESET%^" }) );
    }
}

int clean_up(){
    object ob, env;
    object *inv;
    int i;

    if (no_clean)
        return 0;

    ob = this_object();
    env = environment(ob);

    if (objectp(ob))
    {
        if ( ob->is_player() )
            return 0;



        if (objectp(env))
        {

            if (env->query_property("storage room"))
                return 1;

            if (env->query_no_clean())
                return 1;

            if (env->is_bag())
                return 1;

            if (living(env) || userp(env))
                return 1;
        }
        else
        /* No environment! Get rid of it and everything in it! */
        {
            if (i = sizeof(inv=all_inventory(TO)))
               while (i--) {
                 if (interactive(inv[i]))
                   return 1;
               }
            if (i = sizeof(inv=all_inventory(TO)))
                while (i--) {
                    inv[i]->move(VOID);
                    if(inv[i])
                        inv[i]->remove();
                    if (inv[i])
                        destruct(inv[i]);
                }

            if (ob)
                ob->remove();
            if (ob)
	            destruct(ob);
            return 1;
        }




        i = sizeof(inv = deep_inventory(ob));
        if (i >= 0)
            while (i--)
                if (interactive(inv[i]))
                    return 1;

        if (i = sizeof(inv=deep_inventory(TO)))
            while (i--) {
                inv[i]->move(VOID);
                inv[i]->remove();
                if (inv[i])
	                destruct(inv[i]);
            }

        ob->move(VOID);
        if (ob)
            ob->remove();
        if (ob)
            destruct(ob);
        return 1;
    } // objectp(ob)
    else {
        return 1; // If it's not a valid object, just return.
    }
    //  return 2;
    // Got no clue on this.
}

void set_last_location(object ob)
{
    last_location = ob;
}

object query_last_location()
{
    return last_location;
}

void set_weight(int x)
{
    encumbrance = x;
}

int query_weight()
{
    return encumbrance;
}

int query_no_clean()
{
    return no_clean;
}

void set_no_clean(int x)
{
    no_clean = x;
}

object query_my_environment() { return environment(this_object()) ;}
