// jinqiang.c

#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
        set_name(HIY "点金枪" NOR, ({ "jin qiang","qiang","jinqiang" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("value", 10000);
                set("material", "gold");
                set("long", "此枪以黄金为头铜为杆。\n");
                set("wield_msg", "$N抄起一杆$n，顺手抖了个枪花。\n");
        //      set("unwield_msg", "$N哼了一声，将$n插回后腰。\n");
        }
        init_spear(50);
        setup();
}

