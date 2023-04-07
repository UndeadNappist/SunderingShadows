#include <std.h>
#include <daemons.h>

inherit OBJECT;

string fname, *sortrem;
object caster;
mapping remembered;

void init()
{
    ::init();
    tell_object(caster, "%^BOLD%^%^WHITE%^Do you want to memorize the destination?\nType %^GREEN%^yes%^WHITE%^ to memorize, anything else to ignore it.");
    input_to("mem_dest");
}

void setup_mem(string str, object tp)
{
    fname = str;
    caster = tp;
}

void mem_dest(string str)
{
    if(str != "yes")
    {
        tell_object(caster,"%^BOLD%^%^WHITE%^You decide to let the trace be.");
        TO->remove();
        return;
    }

    tell_object(caster,"%^BOLD%^%^WHITE%^What woud you like to remember the trace as?\nDefault name is %^ORANGE%^trace%^WHITE%^.");
    input_to("mem_dest2");
}

void mem_dest2(string str){
    string dname;
    int mem_size;

    if (!(regexp(str, "[A-Za-z0-9]+"))) {
        dname = "trace";
    } else {
        dname = str;
    }

    if (!remembered = caster->query_rem_rooms()) {
        remembered = ([]);
    }
    if (!sortrem = caster->query_rem_rooms_sort()) {
                sortrem = ({});
    }

    remembered[dname] = fname;
    sortrem = distinct_array(({ dname }) + sortrem);
    mem_size = (int)TP->query_base_stats("intelligence") + (FEATS_D->usable_feat(TP, "worldly traveler") * 5);
    if(sizeof(sortrem) > mem_size && !avatarp(TP))
            shorten(mem_size);
    caster->set_rem_rooms(remembered, sortrem);

    tell_object(caster,"%^BOLD%^%^WHITE%^You memorize " + fname->query_short() + "%^RESET%^%^BOLD%^ as %^ORANGE%^" + dname + "%^RESET%^.");

    this_object()->remove();
}

void shorten(int newsize){
    while(sizeof(sortrem) > newsize){
        map_delete(remembered, sortrem[sizeof(sortrem) - 1]);
        sortrem -= ({ sortrem[sizeof(sortrem) - 1] });
    }
    return;
}

