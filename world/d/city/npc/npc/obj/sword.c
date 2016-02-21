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
        }
        init_sword(70);
        setup();
}
