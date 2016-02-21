// bigaxe.c

#include <weapon.h>
#include <ansi.h>

inherit AXE;

void create()
{
	set_name(HIW"鬼斧"NOR, ({ "gui fu","fu","axe" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("material", "steel");
		set("long", WHT"上古十二神兵之一：鬼斧，听说是大禹治水时用过的。\n"NOR);
		set("value", 0);
                set("no_put",1);
                set("no_zm",1);
//                                set("no_give",1);
		set("wield_msg", "$N拿出一把$n，握在手中当作武器。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}
	init_axe(100+random(100), TWO_HANDED);
	setup();
}
