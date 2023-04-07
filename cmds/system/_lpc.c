/*
  _lpc.c
  
  New version of the eval command.
  
  -- Tlaloc --
*/

#include <std.h>
#include <ansi.h>
#include <security.h>

inherit DAEMON;

int cost, micros;
mixed error;

//Handles the actual call and gathers metrics
public mixed call_lpc_file(string file)
{
    int cost1    = 0;
    int cost2    = 0;
    int ut1      = 0;
    int ut2      = 0;
    mixed result = 0;
    object ob    = 0;
    error        = 0;
    
    if(error = (mixed)catch(ob = load_object(file)))
        return error;
    
    if(error = catch(result = (mixed)call_other(ob, "eval")))
        return error;
    
    ut1          = perf_counter_ns();
    cost1        = eval_cost();
    //result       = (mixed)call_other(ob, "eval");
    ut2          = perf_counter_ns();
    cost2        = eval_cost();    
    cost         = cost1 - cost2;
    micros       = ut2 - ut1;
    
    return result;
}
   
int cmd_lpc(string args)
{
    string file, path, result, color;
    object test;
    
    if(!strlen(args))
        return notify_fail("Syntax : lpc <lpc commands>\n");
    
    seteuid(UID_ROOT);
    write_file("/log/adm/evals", ctime(time()) + ": " + capitalize(this_player()->query_name()) + " " + args + "\n");
    seteuid(geteuid());
    seteuid(getuid(previous_object()));
    
    if(args[0..5] == "return")
        args = args[6..];
    
    file = "" +
        "#include <std.h>\n" +
        "#include <daemons.h>\n" +
        "#include <runtime_config.h>\n" +
        "inherit OBJECT;\n" +
        "void create() { seteuid( getuid() ); }\n" +
        "mixed eval() { return " + args + "; }\n" +
        "";
    path = user_path(geteuid(this_player()));
    
    if (file_size(path) != -2)
        return notify_fail("You must have a valid home directory!\n");
    
    path += "CMD_EVAL_TMP_FILE.c";
    rm(path);
    if(test = find_object(path))
        destruct(test);
    
    write_file(path, file);
    
    result = call_lpc_file(path);
    
    if(error)
    {
        write("%^CYAN%^%^BOLD%^ERROR : %^YELLOW%^" + error + "%^RESET%^\n");
    }
    else
    {
        printf("%s[%s%d%s|%s%d%s] %s(%s)%s\n", HIW, HIC, cost, HIW, HIY, micros, HIW, GRN, args, ESC);
    
        if(intp(result))
            color = "%^BOLD%^%^RED%^";
        else if(stringp(result))
            color = "%^BOLD%^%^GREEN%^";
        else if(pointerp(result))
            color = "%^MAGENTA%^%^BOLD%^";
        else
            color = "%^BOLD%^%^BLUE%^";
    
        write("%^BOLD%^Result : %^RESET%^" + color + identify(result) + "%^RESET%^\n");
    }
    
    if(test = find_object(path))
        destruct(test);
    
    return 1;
}

int help()
{
    write("SYNTAX : lpc <evals>\n");
    write("Effect : calls a function containing <evals>\n");
    write("Will return [eval cost | eval time] with evals called. Below that will be listed the result.\n");
}

