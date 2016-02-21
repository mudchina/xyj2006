
//逆刃刀
//lestat for 拔刀术
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name("逆刃刀", ({"niren dao", "sword", "dao",
"nirendao"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","这看上去像是一把刀，奇怪的是刀刃竟然是反的。\n");
                set("unit", "把");
		set("wield_msg",
"$n「唰」地从剑鞘中弹出，落入$N的手中。\n");
		set("unwield_msg",
"$N将手中的$n插入腰间，脸色更加阴沉了！\n");
                set("value", 0);
           set("badao", 1);
		set("weapon_prop/courage", 10);
        }
        init_sword(1);
        setup();
}
