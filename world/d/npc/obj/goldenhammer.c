// gogogo
#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name(HIY"金锤"NOR, ({"golden hammer","hammer" }) );
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", 
"这是一把用纯金打造的锤，重的让人难以想象，听说它的重量能和金箍棒相媲美，不知道是谁用的兵器。\n");
                set("value", 1000000);
                set("no_sell", 1);
                set("no_drop", 1);
                set("material", "gold");
                set("wield_msg", "$N拿出$n，一个不留神掉了，赶紧又伸手捞了起来，好重呀。\n");
                set("unwield_msg", "$N放下手中的$n,终于松了一口气，还好没砸到自己脚上。\n");
        }
        init_hammer(200);
        setup();
}

