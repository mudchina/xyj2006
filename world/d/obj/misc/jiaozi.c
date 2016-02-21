// Room: jiaoli.c
// AceP
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(RED "花轿" NOR, ({"jiaozi", "jiao"}));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一顶漂亮的花轿，大红的缎子布包着，四角扎着大红花，四根杆子都用彩带绕着。\n"
"撩起前面的盖帘就可以进去。当然，只有待嫁的新娘子才能坐这花轿。\n");
		set("unit", "顶");
		set("value", 3000);
		set("no_drop", "这样东西不能离开你。\n");
		set("no_get", "这样东西不能离开那儿。\n");
	}

	setup();
}
