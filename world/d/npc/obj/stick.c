// bintiegun.c

#include <weapon.h>
#include <ansi.h>
inherit STICK;

void create()
{
	set_name(RED"霹雳棍"NOR, ({ "pili gun","stick", "gun" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("value", 0);
                set("no_put",1);
                set("no_zm",1);
//                set("no_give",1);

		set("material", "steel");
		set("long", HIW"上古十二神兵之一：霹雳棍\n"NOR);
		set("wield_msg", "$N拿起一根$n，顺手舞了个棍花。\n");
		set("unwield_msg", "$N哼了一声，将$n插回后腰。\n");
	}
	init_stick(100+random(100));
	setup();
}
