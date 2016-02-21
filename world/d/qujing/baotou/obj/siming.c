
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("四明铲", ({"siming chan", "chan", "staff"}) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 3500);
		set("material", "iron");
		set("long", "这是一柄长长的四明铲，粗粗的杖头有一铲。\n");
		set("wield_msg", "$N举起一柄长长的$n，顶端的铲头闪闪发亮。\n");
		set("unequip_msg", "$N缓缓放下手中的$n。\n");
	}
	init_staff(65);
	setup();
}
