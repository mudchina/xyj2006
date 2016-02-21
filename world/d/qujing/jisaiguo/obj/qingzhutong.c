#include <weapon.h>

inherit HAMMER;
inherit F_LIQUID;

void create()
{
        set_name("青竹筒", ({"qingzhu tong", "tong"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个用葫芦制成的水壶。\n");
                set("unit", "个");
                set("max_liquid", 10);
        }
	set("wield_msg", "$N抓起一根$n，握在手中当武器。\n");
        set("liquid", ([
                "type": "water",
                "name": "泡的已经没有味的茶水",
                "remaining": 10,
                "drunk_supply": 30,
        ]));
	init_hammer(1);
	setup();
}

