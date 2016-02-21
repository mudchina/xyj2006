// blade.c

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("青虹剑", ({"qinghong sword", "sword", "jian",
"qinghong"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一把镇妖降魔的宝剑。\n");
                set("unit", "把");
		set("wield_msg",
"$n「唰」地从剑鞘中弹出，落入$N的手中，剑尖还兀自闪个不停。\n");
		set("unwield_msg",
"$N将手中的$n插入腰间，脸色更加阴沉了！\n");
                set("value", 5000);
		set("weapon_prop/courage", 10);
		set("no_sell",1);
				set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n");
				set("no_give","总管发的装备，可不能乱送人哟！\n");
				set("no_get","想拿总管一叶知秋发的装备？做梦吧!\n");
        }
        init_sword(70);
        setup();
}
