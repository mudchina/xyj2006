
#include <weapon.h>

inherit AXE;

void create()
{
	set_name("钺斧", ({"yue fu", "fu", "axe"}) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 2500);
		set("material", "iron");
		set("long", "这是一把沉重的钺斧。\n");
		set("wield_msg", "$N拿起一把$n，嗖地一舞。\n");
	}
	init_axe(55);
	setup();
}
