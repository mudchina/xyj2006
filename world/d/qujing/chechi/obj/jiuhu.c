// by snowcat oct 24 1997

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("¾Æºø", ({"jiuhu", "hu"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»¸ö×°ÓÐ°×ÉÕ¾ÆµÄ¾Æºø¡£\n");
		set("unit", "¸ö");
		set("value", 250);
		set("max_liquid", 12);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "°×ÉÕ¾Æ",
		"remaining": 12,
		"drunk_apply": 20,
	]));
}
