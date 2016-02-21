// ptmj.c 葡萄美酒

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("月光杯", ({"ptmj", "yueguangbei", "bei"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "御用月光杯\n");
		set("unit", "个");
		set("value", 100);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "葡萄美酒",
		"remaining": 15,
		"drunk_apply": 5,
	]));
}

