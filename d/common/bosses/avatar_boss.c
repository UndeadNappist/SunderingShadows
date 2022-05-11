#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit WEAPONLESS;

void create()
{
    ::create();
    set_property("no death", 1);
    set_property("no fear", 1);
    set_property("no bows", 1);
    set_property("no knockdown", 1);
    set_property("no trip", 1);
    set_property("no tripped", 1);
    set_property("no steal", 1);
    set_property("no dominate", 1);
    set_property("no hold", 1);
    set_property("confusion_immunity", 1);
    set_property("hidden inventory", 1);
    set_property("cast and attack", 1);
    set_property("function and attack", 1);
}

void init()
{
    ::init();
}

void die()
{
    string *files, *selected;
    
    files = get_dir("/d/common/bosses/loot/*.c");
    files = filter_array(files, (: load_object("/d/common/bosses/loot/" + $1) :));
    
    selected = ({  });
    
    while(sizeof(selected) < 5)
    {
        int temp;
        
        temp = random(sizeof(files));
        selected += ({ files[temp] });
        files -= ({ files[temp] });        
        selected = distinct_array(selected);
    }
    
    foreach(string file in selected)
        new("/d/common/bosses/loot/" + file)->move(this_object());
        
    ::die();
}

