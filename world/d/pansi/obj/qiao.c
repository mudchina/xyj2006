// qiao.c 剑鞘
// jie 2001-2-4

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("剑鞘", ({ "jian qiao", "qiao" }));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一个剑鞘，高手可以用它当剑使。\n");
		set("material", "iron");
		set("wield_msg", "$N将剑鞘拿起来握在手中。\n");
		set("unwield_msg", "$N将手中的$n重新挂在腰上。\n");
	}
	init_sword(5);
	setup();
}