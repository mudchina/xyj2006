// blade.c

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("Âà´¸", ({"luochui", "hammer"}));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸ö");
        }
        init_hammer(1);
        setup();
}

