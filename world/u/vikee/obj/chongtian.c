#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;

inherit SWORD;

void create()
{
        set_name(HIM "冲天一剑" NOR, ({"chongtian sword", "sword"}));
        set_weight(14000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把紫色的剑，上面的图案好象很难懂．\n");
		set("no_sell", 1);
		set("no_drop", 1);
		set("no_put", 1);
                set("value", 30000);
		set("replace_file", "/d/obj/weapon/sword/qingfeng");
                set("material", "crimsonsteel");
                set("wield_msg", "$N剑眉一挑，$n稳稳的落在手中．\n");
                set("unwield_msg", "$N神定气闲，将$n缓缓插入腰间．\n");
        set("weapon_prop/int", 2);

        }
        init_sword(750);
        set("is_monitored",1);
        setup();
}

