//Cracked by Roath
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("雷公杵", ({"leigong chu", "chu"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 10000);
		set("no_sell", 1);
                set("material", "wood");
                set("long", "一把尖头雷公杵。\n");
                set("wield_msg", "$N抽出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰后。\n");
        }
        init_staff(60);
        setup();
}

