// pig

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("猪头肉", ({"pig head", "pighead", "head"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一盘肥瘦相间的猪头肉，显然刚拱出炉。\n");
                set("unit", "盘");
                set("value", 50);
                set("food_remaining", 5);
                set("food_supply", 40);
		set("eat_msg","$N抓起一大块$n送进嘴里。\n");
        }
}

