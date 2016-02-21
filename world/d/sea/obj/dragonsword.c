#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("龙泉剑", ({ "dragon sword", "jian", "sword" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 5000);
                set("material", "steel");
                set("long","一把光茫四射的宝剑，隐有龙影流动。\n");
                set("wield_msg", "$N抽出一把剑身细长的剑，握在手中。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
        }
        init_sword(50);
        setup();
}

