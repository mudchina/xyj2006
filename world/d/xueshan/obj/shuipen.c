
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("水盆", ({"shui pen", "pen"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个可以用来装水的小盆。\n");
		set("unit", "个");
		set("value", 100);
		set("max_liquid", 30);
	}

	set("liquid", ([
		"type": "water",
		"name": "雪水",
		"remaining": 20,
	]));
}
