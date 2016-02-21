#include <weapon.h>

inherit HAMMER;
void create()
{
        set_name("捣药杵", ({ "yao chu", "chu" }) );
        set_weight(8500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把日常用来捣药的铁杵。\n");
                set("value", 1200);
                set("material", "iron");
                set("wield_msg", "$N拿出一把$n，试了试重量，然後握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_hammer(25);
        setup();
}

