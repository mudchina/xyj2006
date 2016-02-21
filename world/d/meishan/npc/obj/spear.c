#include <weapon.h>

inherit SPEAR;

void create()
{
        set_name("三尖两刃枪", ({"sanliang spear", "spear"}));
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "三尖两刃枪乃是二郎神君的独门兵器，锋利无比。\n");
                set("value", 50000);
                set("material", "iron");
                set("wield_msg", "$N拿出一把$n握在手中，眼前闪过一道寒光．\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_spear(80);
        setup();
}

