//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("七星剑", ({"qixing sword", "sword"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把带有七星的剑，看起来非常的华丽．\n");
                set("value", 10000);
                set("material", "crimsonsteel");
                set("wield_msg",
"$N「唰」地一声抽出一把$n握在手中．\n");
                set("unwield_msg",
"$N将手中的$n插入腰间，嘴角露出一丝笑意．\n");

        }
        init_sword(80);
        setup();
}