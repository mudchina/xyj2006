
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("大刀", ({"da dao", "dao", "blade"}) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 2500);
		set("material", "iron");
		set("long", "这是一把沉重的大刀。\n");
		set("wield_msg", "$N拿起一把$n，嗖地一舞。\n");
	}
	init_blade(55);
	setup();
}
