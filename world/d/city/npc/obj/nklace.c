// nklace.c 金项链

#include <armor.h>

inherit NECK;

void create()
{
	set_name("“金”项链", ({ "xiang lian", "necklace" }));

	set("weight", 500);
	set("long", "一串金灿灿的项链，是长安城的少女喜爱的饰物。\n"
		"但仔细看看总觉得这个金色有点不对劲。\n");
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "串");
		set("value", 500);
		set("material", "gold");
		set("armor_prop/armor", 1);
	}
	setup();
}	
