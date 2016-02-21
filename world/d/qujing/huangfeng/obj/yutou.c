// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/obj/yutou

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("芋头", ({"yu tou","yutou"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "一大块芋头。\n");
                set("unit", "块");
		set("value", 80);
		set("food_remaining", 4);
		set("food_supply", 30);
	}
}
