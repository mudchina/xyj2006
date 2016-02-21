//Cracked by Roath
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("火焰刀", ({"huoyan dao", "dao", "blade"}) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value",10000);
		set("no_sell", 1);
                set("material", "iron");
                set("long", "这是一柄稍短一点的火焰刀。\n");
                set("wield_msg", "$N抽出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
        }
        init_blade(60);
        setup();
}

