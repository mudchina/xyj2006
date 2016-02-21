// jingubang.c

#include <ansi.h>
#include <weapon.h>

inherit STICK;

void create()
{
	set_name( HIY "金箍棒" NOR, ({ "jingubang", "bang" }) );
	set_weight(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("value", 500);
		set("material", "gold");
		set("long", "此棒两头以金为箍，中间乃一段乌铁。上铸一行小字：“如意金箍棒”。\n");
		set("wield_msg", "$N一伸手，连喝几声：大！大！大！掌中忽然多了一条$n。\n");
		set("unwield_msg", "$N一吹气，几声轻喝：小！小！小！$n在$N掌中转了几转，忽然不见了。\n");
	}
	init_stick(250);
	setup();
}
