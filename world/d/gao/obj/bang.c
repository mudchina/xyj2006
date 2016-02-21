// bang.c
#include <weapon.h>

inherit STICK;

void create()
{
        set_name("Ä¾°ô", ({"mu bang"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸ö");
		set("value", 100);
		set("material", "wood");
	     }
	init_stick(15);
	setup();
}
