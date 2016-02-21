//Cracked by Roath
// huojianqiang.c

#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
        set_name(HIR "火尖枪" NOR, ({ "huojianqiang", "spear" })
);
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("long", "一杆" HIR "火尖枪" NOR "，乃是红孩儿看家的宝贝。\n");
                set("value", 10000);
                set("material", "blacksteel");
                set("wield_msg","$N将火尖枪提在手中，周围的人顿觉一股热浪扑面而来。\n");
                set("unwield_msg", "$N将手中的$n系到背后，四周也清凉了许多。\n");
		set("weapon_prop/courage", 4);
        }
        init_spear(50);
        setup();
}

