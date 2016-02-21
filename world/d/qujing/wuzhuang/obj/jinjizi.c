//Cracked by Roath
#include <weapon.h>

inherit STICK;

void create()
{
        set_name("金击子", ({"jinji zi"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 5);
                set("no_get",1);
                set("material", "wood");
                set("wield_msg", "$N把$n举在手中．\n");
        }
        init_stick(10);
        setup();
}
