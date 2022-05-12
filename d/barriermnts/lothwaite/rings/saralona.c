#include <std.h>
inherit ARMOUR;

string symbol1;
string symbol2;
string weapon1;
string weapon2;
string initial1;
string initial2;
string background;
void create(){
	::create();
	set_name("signet ring");
	set_id(({"ring","signet ring","signet"}));
	set_short("signet ring");
	symbol1 = "a %^BOLD%^%^RED%^fi%^YELLOW%^e%^RED%^ry phoenix %^RESET%^rising from the %^BOLD%^%^BLACK%^ashes%^RESET%^";
