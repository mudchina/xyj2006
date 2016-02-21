// blade.c

#include <weapon.h>
inherit F_UNIQUE;

inherit WHIP;

void create()
{
        set_name("缚龙索", ({"fulong whip", "whip"}));
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {

set("long","一条长约六尺，青红龙筋缠成的长鞭，乃是地藏王菩萨的兵器，不畏刀枪之利，水火不侵．\n");
                set("unit", "条");
	set("replace_file", "/d/obj/weapon/whip/pibian");
                set("value", 12000);
		set("wield_msg", "只听「啪」的一声响，$N的手中闪出一条青红色的长鞭．\n");
		set("unwield_msg", "$N把手中$n缠回腰间．\n");
		set("weapon_prop/courage", 5);
        }
        init_whip(80);
        set("is_monitored",1);
        setup();
}

