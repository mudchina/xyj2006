// golden_armor.c

#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("Ìì±øÕ½¼×", ({ "heaven armor", "armor" }) );
	set_weight(25000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
		set("material", "gold");
		set("value", 4000);
		set("armor_prop/armor", 30);
	}
	setup();
}
