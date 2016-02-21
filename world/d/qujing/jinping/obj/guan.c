
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("水罐", ({"shui guan", "guan"}));
	set_weight(900);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个红泥陶器水罐。\n");
		set("unit", "个");
		set("value", 100);
		set("max_liquid", 10);
	}

	// because a container can contain different liquid
	// we set it to contain water at the beginning
	set("liquid", ([
		"type": "water",
		"name": "清水",
		"remaining": 10,
		"drunk_supply": 10,
	]));
}
