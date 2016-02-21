// blade.c

#include <weapon.h>
#include <ansi.h>
//  inherit F_UNIQUE;

inherit SPEAR;

void create()
{
set_name(HIW "方天化戟" NOR, ({"huaji", "ji","spear"}));
set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {

 set("long","一根长一丈八，红缨银刃金杆的方天化戟。\n");
set("unit", "根");
set("replace_file", "/d/obj/weapon/spear/huaji");
set("value", 20000);
set("wield_msg", "$N一声虎吼，托起一根红缨银刃金杆的方天化戟\n");
set("unwield_msg", "$N把手中$n背在了背后．\n");
set("weapon_prop/strength", 10);
        }
init_spear(100);
        set("is_monitored",1);
        setup();
}

