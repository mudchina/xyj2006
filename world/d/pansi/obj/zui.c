//Cracked by Roath
// zui.c 醉生梦死

inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>
void create()
{
	set_name(HIG"醉生梦死"NOR, ({"zui", "bottle"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "据说喝了它,可以让人忘记一切哀伤。\n");
		set("unit", "瓶");
		set("value", 5000);
		set("realzui",1);
		set("max_liquid", 500);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "water",
		"name": "清水",
		"remaining": 400,
		"drunk_apply": 400,
	]));
}
