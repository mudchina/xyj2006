// bajiaoshan.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("芭蕉扇", ({ "baojiao shan","shan" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 200);
		set("material", "wood");
		set("long", "一把芭蕉做成的扇子。\n");
		set("wield_msg", "$N拿出一把芭蕉扇扇了几扇。\n");
		set("unwield_msg", "$N扇了几扇，将$n插回腰间。\n");
	}
	init_blade(10);
	setup();
}
