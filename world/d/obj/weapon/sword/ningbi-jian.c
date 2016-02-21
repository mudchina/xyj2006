// sgzl

#include <weapon.h>

//inherit SWORD;
inherit "/d/xueshan/obj/anqi-jian.c";

void create()
{
        set_name("凝碧剑", ({"ningbi sword", "sword"}));
        set_weight(14000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把淡蓝色的细剑，剑身几乎透明，剑锋处闪着点点寒光，似乎喂了剧毒。\n");
                set("orilong","一把淡蓝色的细剑，剑身几乎透明，剑锋处闪着点点寒光，似乎喂了剧毒。\n");
                set("value", 30000);
                set("material", "crimsonsteel");
                set("wield_msg", "$N冷笑一声，从背后拔出了$n。\n");
                set("unwield_msg", "$N将手中的$n插回鞘中，嘴角多了一丝笑意。\n");
                set("weapon_prop/int", 1);
                set("anqi/max", 20);
                set("anqi/now", 0);

        }
        init_sword(60);
        setup();
}

