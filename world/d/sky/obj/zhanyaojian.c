// golden_sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("斩妖剑", ({ "zhanyao jian","jian", "sword" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把闪闪发着金光的长剑。\n");
		set("value", 8000);
		set("material", "gold");
		set("weapon_prop/courage", 10);
	}
	init_sword(70);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");

// The setup() is required.

	setup();
}
