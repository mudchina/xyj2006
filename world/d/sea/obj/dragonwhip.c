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
        }
        init_whip(50);
        setup();
}

