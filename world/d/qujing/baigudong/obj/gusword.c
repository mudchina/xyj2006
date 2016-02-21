// thin_sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("灵骨剑", ({ "linggu sword", "jian", "sword" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 5000);
		set("material", "steel");
		set("long", "这把剑据说是用人血当祭品，锻炼而成。\n");
		set("wield_msg", "一道血光闪过，$N手中已多了把$n。\n");
	}
	init_sword(35);
	setup();
}
