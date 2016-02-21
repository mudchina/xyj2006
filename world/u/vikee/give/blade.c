#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("金刀", ({"jin dao", "dao"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把金光闪闪的圆头长刀，刀把上镶嵌有白玉。\n");
                set("value", 2500);
                set("material", "gold");
                set("wield_msg", "$N「唰」地一声抽出一把$n握在手中，金光闪闪！\n");
                set("unwield_msg", "$N将手中的$n插入金色刀鞘。\n");
        set("weapon_prop/courage", 15);
			set("no_sell",1);
				set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n");
				set("no_give","总管发的装备，可不能乱送人哟！\n");
				set("no_get","想拿总管一叶知秋发的装备？做梦吧!\n");

        }
        init_blade(50);
        setup();
}

