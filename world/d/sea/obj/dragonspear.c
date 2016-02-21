#include <weapon.h>

inherit SPEAR;

void create()
{
        set_name("龙骨枪", ({"dragon spear", "qiang", "spear"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一根长长的龙骨，尖芒锋锐。\n");
                set("value", 5000);
                set("material", "iron");
                set("wield_msg","$N拿出一把$n，握在手中．\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_spear(50);
        setup();
}

