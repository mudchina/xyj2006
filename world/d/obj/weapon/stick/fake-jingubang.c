//fake-jingubang.c
//the real jingubang may be used to improve stick level.
//this one is weapon only, less powerful,
//and simply put with ao-guang for highhands...weiqi:)

#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;
inherit STICK;

void create()
{
	set_name( HIY "金箍棒" NOR, ({ "jingu bang", "jingubang", "bang" }) );
	set_weight(100000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("Can_avoid_find", 1);
		set("no_sell", 1);
		set("no_give", 1);
//		set("no_get", 1);
		set("value", 5000);
		set("material", "gold");
        set("replace_file", "/d/obj/weapon/stick/bintiegun");
		set("long", "此棒两头以金为箍，中间乃一段乌铁。上铸一行小字：“如意金箍棒，东海敖广监制”。\n");
		set("wield_msg", "$N一伸手，连喝几声：大！大！大！掌中忽然多了一条$n。\n");
		set("unwield_msg", "$N一吹气，几声轻喝：小！小！小！$n在$N掌中转了几转，忽然不见了。\n");
	}
	init_stick(100);
	setup();
}
