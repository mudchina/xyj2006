// sgzl

#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("孔雀翎", ({"kongque ling","ling"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",    "几支孔雀身上的羽毛。\n");
                set("unit", "把");
                set("base_unit", "支");
                set("base_weight", 5);
                set("value", 3);
        }
        set_amount(random(5)+1);
        init_throwing(50);
        setup();
}

