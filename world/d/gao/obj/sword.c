// blade.c

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("铁剑", ({"sword"}));
	set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一把长剑．\n");
                set("unit", "把");
                set("value", 1000);
        }
        init_sword(20);
        setup();
}

