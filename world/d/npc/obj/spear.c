// changqiang.c

#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
	set_name(YEL"火魔枪"NOR, ({ "huomo qiang","qiang","spear" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "杆");
		set("value", 0);
                set("no_put",1);
                set("no_zm",1);
//                set("no_give",1);
		set("material", "wood");
		set("long", HIC"上古十二神兵之一：火魔枪\n"NOR);
		set("wield_msg", "$N抄起一杆$n，顺手抖了个枪花。\n");
	//	set("unwield_msg", "$N哼了一声，将$n插回后腰。\n");
	}
	init_spear(100+random(100));
	setup();
}
