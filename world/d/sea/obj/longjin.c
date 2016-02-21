// blade.c
#include <ansi.h>

#include <weapon.h>
inherit F_UNIQUE;

inherit WHIP;

void create()
{
        set_name(HIY"软龙筋"NOR, ({"ruan longjin", "longjin","whip"}));
        set_weight(10000);
        set("no_sell",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {

set("long",HIC"一条长约五六尺的软龙筋，质地坚固，柔韧有余，真是制成鞭子的最佳材料．\n"NOR);
                set("unit", "条");
	set("replace_file", "/d/obj/weapon/whip/pibian");
		set("wield_msg", HIC"只见$N从腰间抽出一条青色龙筋，呼呼作响，竟带龙吟．\n"NOR);
		set("unwield_msg", "$N把手中$n缠回腰间．\n");
		set("weapon_prop/courage", 5);
        }
        init_whip(200);
        set("is_monitored",1);
        setup();
}
int query_autoload() { return 1; }


