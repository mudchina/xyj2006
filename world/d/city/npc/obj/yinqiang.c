// hammer.c
#include <ansi.h>
#include <weapon.h>

inherit SPEAR;

void create()
{
        set_name(HIY "亮银枪" NOR, ({"yin qiang", "qiang", "spear"}));
        set_weight(14000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
"这是把沉重的长枪，枪尖是纯银打制，锋利无比．\n");
                set("value", 50000);
                set("material", "iron");
                set("wield_msg",
"$N拿出一把$n握在手中，眼前闪过一道寒光．\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_spear(90);
        setup();
}

