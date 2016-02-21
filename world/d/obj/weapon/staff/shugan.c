// shugan.c

#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("树干", ({ "shugan", "staff" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("material", "wood");
		set("long", "这是一根粗长的树枝。\n");
		set("weapon_prop/courage", -4);
	}
	init_staff(5);
	setup();
}
