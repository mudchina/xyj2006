#include <weapon.h>

inherit STICK;

void create()
{
        set_name("竹扫帚", ({"broom"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 50);
                set("material", "wood");
                set("wield_msg", "$N把$n握在手中．\n");
        }
        init_stick(10);
        setup();
}

