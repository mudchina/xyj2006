// danlu.c

#include <ansi.h>;
inherit ITEM;

void create()
{
	set_name(HIY"铜丹炉"NOR, ({"danlu", "lu"}));
	set_weight(100000000000000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一座黄铜做的丹炉，烫得有点让人无法接近。\n");
		set("unit", "座");
                     set("no_get","你是大力士吧？这个也想拿起来？");
		set("value", 2000);
	}
}

