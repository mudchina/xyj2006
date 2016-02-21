// goldring.c 金戒指

#include <armor.h>

inherit FINGER;

void create()
{
	set_name("钻石戒指", ({ "ring", "jiezhi", "ring" }));
	set("weight", 400);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 9000);
		set("material", "gold");
		set("armor_prop/armor", 1);
	}
	setup();
}	
