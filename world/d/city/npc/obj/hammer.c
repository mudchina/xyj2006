#include <weapon.h>

inherit HAMMER;


void create()
{
        set_name("八瓣梅花锤", ({ "meihua hammer", "hammer" }) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把分八瓣成梅花状的铜锤，上面刻了些符篆。\n");
                set("value", 5000);
		set("no_sell", 1);
                set("material", "iron");
                set("wield_msg", "$N拿出一把$n，试了试重量，然後握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
			set("no_sell",1);
				set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n");
				set("no_give","总管发的装备，可不能乱送人哟！\n");
				set("no_get","想拿总管一叶知秋发的装备？做梦吧!\n");
        }
        init_hammer(60);
        setup();
}

