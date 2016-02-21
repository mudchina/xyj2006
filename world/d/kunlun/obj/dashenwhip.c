#include <weapon.h>
//  inherit F_UNIQUE;

inherit WHIP;
#include <ansi.h>
void create()
{
        set_name("打神鞭", ({"dashen whip", "whip"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","一条灰黑色的钢鞭，通体泛着一种莫名其妙的光芒。\n");
                set("unit", "副");
                set("value", 15000);
                set("wield_msg", "$N挥手一伸，一把打神鞭已到了手中\n");
                set("unwield_msg", "$N把手中$n放入衣中．\n");
                set("weapon_prop/courage", 20);
                }
        init_whip(100);
        setup();
}
