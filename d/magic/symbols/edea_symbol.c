#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

void create(){
    ::create();
    set_id(({"holy symbol", "symbol", "edea_holy_symbol", "mask"}));
    set_name("holy symbol");
    set_short("holy symbol");
    set_long("This is a holy symbol.");
}

void init(){
    ::init();
    set_name("a pristine ivory mask");
    set_short("%^C231%^A %^C183%^p%^C189%^r%^C225%^i%^C231%^s%^C229%^t%^C194%^i%^C195%^n%^C183%^e %^C230%^ivory mask%^CRST%^");
    set_long("%^C231%^This mask is carved from a %^C230%^pure ivory%^C231%^, giving it a %^C228%^luminous %^C231%^quality that catches the %^C226%^l%^C227%^i%^C228%^g%^C227%^h%^C226%^t %^C231%^and reflects it back in a %^C226%^radiant glow%^C231%^. The face the mask depicts has soft, %^C225%^feminine %^C231%^features, its eyes closed, portraying a serene, %^C165%^p%^C171%^e%^C177%^a%^C183%^c%^C219%^e%^C213%^f%^C207%^u%^C201%^l %^C231%^expression. A faint dusting of %^C136%^s%^C220%^h%^C226%^i%^C227%^m%^C226%^m%^C220%^e%^C136%^r%^C220%^i%^C226%^n%^C227%^g %^C226%^g%^C227%^o%^C228%^l%^C226%^d l%^C227%^e%^C228%^a%^C226%^f %^C231%^adorns the mask’s upswept cheeks. The symbol is strung on a %^C220%^g%^C226%^o%^C227%^l%^C228%^d%^C226%^e%^C220%^n c%^C226%^h%^C227%^a%^C226%^i%^C220%^n%^C231%^, allowing it to be worn easily about the neck.%^CRST%^");
}