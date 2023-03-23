// Stackable item inherit
// By Spade, Dec. 2022

#include <std.h>

inherit OBJECT;

int no_notification;  // Determines weather or not the quantity notification is shown in the long description.

void init()
{
    ::init();

    if (!this_object())
        return;

    if (query("quantity") < 1)
        this_object()->remove();

    if (environment(this_object())->is_living())
    {
        add_action("combine_function", "combine");
        add_action("split_function", "split");
    }
}

void create()
{
    ::create();

    set_property("no alter", 1);
    set_value(query("base_value") * query("quantity"));
}

string query_long(string str)
{
   string hold = ::query_long(str);

   if (no_notification)
       return hold;

   hold += "\n\nThis stack contains " + query("quantity") + " objects. If you have another stack of the same type, you can <combine X with Y>. You may also split <split N from X>";

   return hold;
}

int combine_function(string str)
{
    string this_stack, that;
    object that_obj, player;

    if (!objectp(this_object()))
        return 0;

    if (!objectp(player = environment(this_object())))
        return 0;

    if (!str)
        return notify_fail("Combine what with what?\n");

    if (sscanf(str, "%s with %s", this_stack, that) != 2)
        return notify_fail("Combine what with what?\n");

    if (present(this_stack, player) != this_object())
        return notify_fail("Combine what with what?\n");

    if (!(that_obj = present(that, player)))
        return notify_fail("Combine what with what?\n");

    if (that_obj == this_object())
        return notify_fail("You can't combine something with itself!\n");

    if (query("stack_id") != that_obj->query("stack_id"))
        return notify_fail("You can only combine two groups of the same thing!\n");

    set("quantity", query("quantity") + that_obj->query("quantity"));

    that_obj->remove();

    set_value(query("base_value") * query("quantity"));

    return 1;
}

int split_function(string args)
{
    string stack_argument;
    object target_object, new_stack, player;
    int size_to_split;

    if (!objectp(this_object()))
        return 0;

    if (!objectp(player = environment(this_object())))
        return 0;

    if (!stringp(args))
        return notify_fail("Split how many from what?\n");

    if (sscanf(args, "%d from %s", size_to_split, stack_argument) != 2)
        return notify_fail("Split how many from what?\n");

    if (query("quantity") - size_to_split < 1)
        return notify_fail("The laws of conservation hold firm in the face of your folly.\n");

    if (present(stack_argument, player) != this_object())
         return notify_fail("Split how many from what?\n");

    if (!(target_object) = present(stack_argument, player))
          return notify_fail("Split how many from what?\n");

    set("quantity", query("quantity") - size_to_split);

    new_stack = new(base_name(this_object()));
    new_stack->set("quantity", size_to_split);
    new_stack->move(player);

    set_value(query("base_value") * query_quantity());

    return 1;
}
