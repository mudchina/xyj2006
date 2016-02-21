// huomoqiang.c

#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
        set_name(HIR "火魔枪" NOR, ({ "huomoqiang", "spear" })
);
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("long", "一杆" HIR "火魔枪" NOR "，乃是火魔的武器。\n");
                set("value", 10000);
                set("material", "blacksteel");
                set("wield_msg","$N将火魔枪提在手中，周围的人顿觉身处熊熊烈火之中馈n");
		set("weapon_prop/courage", 8);
        }
        init_spear(150);
        setup();
}

