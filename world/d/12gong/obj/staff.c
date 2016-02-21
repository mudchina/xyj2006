#include <ansi.h>
#include <weapon.h>

//inherit F_UNIQUE;
inherit STAFF;

void create()
{
	set_name( HIR "胜利女神" NOR, ({ "shengli nvshen", "staff" }) );
    set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("no_sell",1);
                set("no_drop", 1);
                set("no_get", 1);
				set("no_give", 1);
                set("no_put", 1);
		set("long", HIY "此乃胜利女神所化成的。\n" NOR);
		set("value", 1000);
		set("material", "brass");
		set("wield_msg", HIY "\n$N拿出胜利女神握在手中，整个圣域都传来了黄金圣衣的共鸣声.\n\n" NOR);
		set("unwield_msg", HIY "\n$N放下手中的胜利女神，黄金圣衣也随即停止了共鸣.\n\n" NOR);
	}

    init_staff(200);
	setup();
}
