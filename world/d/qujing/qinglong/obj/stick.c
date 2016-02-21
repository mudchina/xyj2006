
#include <weapon.h>

inherit STICK;

void create()
{
	set_name("大棍", ({"da gun", "gun", "stick"}) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("value", 2500);
		set("material", "iron");
		set("long", "这是一根沉重的大棍。\n");
		set("wield_msg", "$N拿起一根$n，嗖地一舞。\n");
	}
	init_stick(55);
	setup();
}
