// caoxie.c

#include <armor.h>

inherit BOOTS;

void create()
{
	set_name("²ÝÐ¬", ({ "cao xie", "xie", "shoes" }) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "wood");
		set("unit", "Ë«");
		set("value", 10);
		set("armor_prop/dodge", 0 );
	}
	setup();
}
