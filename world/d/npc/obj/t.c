// blade.c

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	set_name(HIB"妖刀"NOR, ({"yao dao", "dao","blade"}) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 0);
              set("no_put",1);
              set("no_sell",1);
              set("no_zm",1);

		set("material", "iron");
		set("long", HIY"上古十二神兵之一：妖刀n"NOR);
		set("wield_msg", "$N抽出一把妖气冲天的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
	init_blade(150+random(100));
	setup();
}
