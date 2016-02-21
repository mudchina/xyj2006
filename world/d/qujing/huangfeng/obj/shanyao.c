// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/obj/shanyao.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("山药", ({"shan yao", "yao"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "野生的山药，看起来味道不错。\n");
                set("unit", "块");
		set("value", 80);
		set("food_remaining", 4);
		set("food_supply", 30);
	}
}
