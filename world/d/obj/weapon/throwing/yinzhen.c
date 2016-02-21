// sgzl

#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("银针", ({"yin zhen","zhen"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",    "一把细小的绣花针，闪着点点寒芒。\n");
                set("unit", "把");
                set("base_unit", "根");
                set("base_weight", 5);
                set("value", 3);
        }
        set_amount(random(10)+1);
        init_throwing(10);
        setup();
}

