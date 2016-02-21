// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("祭刀", ({"ji dao", "dao", "blade"}) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 300);
		set("material", "iron");
		set("long", "这是一柄稍短一点的祭刀。\n");
		set("wield_msg", "$N抽出一把$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
	init_blade(20);
	setup();
}
