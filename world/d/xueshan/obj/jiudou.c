// 蚕豆 

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("酒浸过的蚕豆", ({"jiu dou", "dou"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "一颗用药酒浸过的蚕豆，据说毒蛇特别喜欢吃。\n");
                set("unit", "颗");
		set("value", 20000);
		set("food_remaining", 1);
		set("food_supply", 1);
	}
}
