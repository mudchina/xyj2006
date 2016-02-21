#include <weapon.h>

inherit WHIP;

void create()
{
        set_name("软龙筋", ({"dragon whip", "whip"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {

set("long","一条长约六尺，青红龙筋缠成的长鞭。\n");
                set("unit", "条");
                set("value", 5000);
                set("wield_msg",
"只听「啪」的一声响，$N的手中闪出一条青红色的长鞭．\n");
                set("unwield_msg", "$N把手中$n缠回腰间．\n");
				set("no_sell",1);
				set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n");
				set("no_give","总管发的装备，可不能乱送人哟！\n");
				set("no_get","想拿总管一叶知秋发的装备？做梦吧!\n");
        }
        init_whip(50);
        setup();
}

