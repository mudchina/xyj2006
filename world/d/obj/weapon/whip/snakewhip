// blade.c
#include <ansi.h>
#include <weapon.h>
//  inherit F_UNIQUE;

inherit WHIP;

void create()
{
set_name(HIW "灵蛇鞭" NOR, ({"snake whip", "whip"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {

set("long","林月如和李逍遥共闯蛇穴，将蛇妖的皮做成的鞭子。\n");
                set("unit", "条");
	set("replace_file", "/d/obj/weapon/whip/pibian");
set("value", 15000);
 set("wield_msg", "$N左手一甩，一条蛇型皮鞭绕腰而出\n");
		set("unwield_msg", "$N把手中$n缠回腰间．\n");
		set("weapon_prop/courage", 5);
        }
        init_whip(60);
        set("is_monitored",1);
        setup();
}
mixed hit_ob(object me, object victim)
{
victim->apply_condition("snake_poison",(int)victim->query_condition("snake_poison")+random(3));
message_vision("$N身子一颤，脸色白了许多！\n", victim);
}
