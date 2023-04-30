#include <std.h>

inherit DAEMON;

void cmd_prompt(string str)
{
    string my_prompt;
    object player = this_player();

    if (!objectp(player))
        return;

    if(!str)
    {
        my_prompt = player->getenv("prompt");

        if (!stringp(my_prompt))
        {
            tell_object(player, "You don't seem to have a prompt... Call a wiz.");
            return;
        }

        my_prompt = replace_string(my_prompt, "%^", "%%%^^^");
        tell_object(player, "Your current prompt is:");
        tell_object(player, my_prompt);
        return 1;
    }
        
    if(str == "reset")
    {
        player->setenv("prompt","%^BOLD%^BLACK%^-%^RED%^>%^RESET%^");
        player->initialize();
        write("Prompt reset.");
        return 1;
    }
    if (sizeof(str) > 1024) {
        tell_object(player,"Your prompt is too long!");
        return 1;
    }

    player->setenv("prompt", str);
    player->initialize();
    write("Prompt changed.");
    return 1;
}
void help(){
    write("
%^CYAN%^NAME%^RESET%^

prompt - change your prompt appearance

%^CYAN%^SYNOPSIS%^RESET%^

prompt [LINE]

%^CYAN%^DESCRIPTION%^RESET%^

This allows you to change your current prompt settings.

When used with no arguments, this will display your current prompt.

When used with the 'reset' argument, the prompt will reset to a default of
    %^BOLD%^BLACK%^-%^RED%^>%^RESET%^
Otherwise the prompt will become whatever you type after the prompt
command.

Available codes:
  %^MAGENTA%^$L%^WHITE%^ language
  %^MAGENTA%^$e%^WHITE%^ exp to next level percent
  %^MAGENTA%^$W%^WHITE%^ wimpy percent
  %^MAGENTA%^$h%^WHITE%^ hp
  %^MAGENTA%^$H%^WHITE%^ maximum hp
  %^MAGENTA%^$i%^WHITE%^ hunger level
  %^MAGENTA%^$_HP%^WHITE%^ hunger percent
  %^MAGENTA%^$o%^WHITE%^ thirst level
  %^MAGENTA%^$_TP%^WHITE%^ thirst percent
  %^MAGENTA%^$s%^WHITE%^ stamina percent
  %^MAGENTA%^$S%^WHITE%^ stamina string
  %^MAGENTA%^$x%^WHITE%^ approximate encumbrance level
  %^MAGENTA%^$T%^WHITE%^ time of day (word)
  %^MAGENTA%^$t%^WHITE%^ time of day (clock)
  %^MAGENTA%^$_LL%^WHITE%^ light level
  %^MAGENTA%^$d%^WHITE%^ drunkeness

Additional codes:
  %^MAGENTA%^$_EW%^WHITE%^ eldritch warfare
  %^MAGENTA%^$_PF%^WHITE%^ psionic focus
  %^MAGENTA%^$_BI%^WHITE%^ bardic inspiration
  %^MAGENTA%^$_SC%^WHITE%^ spell combat
  %^MAGENTA%^$_SR%^WHITE%^ spell recall
  %^MAGENTA%^$_ES%^WHITE%^ eldritch shield
  %^MAGENTA%^$_UP%^WHITE%^ used undead pool
  %^MAGENTA%^$_MP%^WHITE%^ max undead pool
  %^MAGENTA%^$EL%^WHITE%^ elementalist
  %^MAGENTA%^$r%^WHITE%^ rage status
  %^MAGENTA%^$E%^WHITE%^ eldritch essence
  %^MAGENTA%^$k%^WHITE%^ available ki
  %^MAGENTA%^$K%^WHITE%^ maximum ki
  %^MAGENTA%^$a%^WHITE%^ available arcana
  %^MAGENTA%^$A%^WHITE%^ maximum arcana
  %^MAGENTA%^$z%^WHITE%^ available grace
  %^MAGENTA%^$Z%^WHITE%^ maximum grace
  %^MAGENTA%^$p%^WHITE%^ power points
  %^MAGENTA%^$P%^WHITE%^ maximum power points
  %^MAGENTA%^$u%^WHITE%^ soul burn
  %^MAGENTA%^$U%^WHITE%^ maximum soul burn
  %^MAGENTA%^$f%^WHITE%^ lower case shapeshifted form
  %^MAGENTA%^$B%^WHITE%^ blood hunger percent

Avatars+ only:
  %^MAGENTA%^$I%^WHITE%^ shows True Invis / Mortal Invis / Stealthed status%^RESET%^

Creators+ only:
  %^MAGENTA%^$D%^WHITE%^ shows current directory

%^CYAN%^EXAMPLE%^RESET%^

%^ORANGE%^<prompt Bane >>%^RESET%^
    would look like this
Bane >

%^ORANGE%^<prompt $h/$H >>%^RESET%^
    would look like
300/320 >

%^CYAN%^SEE ALSO%^RESET%^

set, speech, adjective, describe, history
");
}
