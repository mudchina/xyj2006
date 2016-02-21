#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name("烂银匕首", ({"silver dagger", "dagger" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把银光闪闪的匕首，看起来相当华贵。\n");
                set("value", 5000);
                set("material", "steel");
        }
        init_dagger(10, SECONDARY);
        set("wield_msg", "$N从怀中摸出一把$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n藏入怀中。\n");
        setup();
}

