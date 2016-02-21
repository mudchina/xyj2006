#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create()
{
	set_name( "伯爵表", ({ "piaget", "watch" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "瑞士名表 － 伯爵表，表的式样并不花哨，但却高贵得体。\n");
		set("value", 600);
		set("material", "wrists");
		set("armor_prop/armor", 5);
	}
	setup();
}


