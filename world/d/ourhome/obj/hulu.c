// hulu.c  葫芦

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("青葫芦", ({"hulu"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个装水的大葫芦。\n");
		set("unit", "个");
		set("value", 10);
		set("max_liquid", 50);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "water",
		"name": "清水",
		"remaining": 40,
		"drunk_apply": 20,
	]));
}
