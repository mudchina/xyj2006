#include <weapon.h>

inherit HAMMER;
inherit F_FOOD;

void create()
{
        set_name("烤羊腿", ({ "yangtui", "tui" }) );
        set_weight(850);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一只烤得香喷喷的羊腿。\n");
                set("unit", "只");
                set("value", 100);
                set("food_remaining", 8);
                set("food_supply", 40);
                set("wield_msg", "$N抓起一根$n，握在手中当武器。\n");
                set("material", "bone");
        }
        init_hammer(3);
        setup();
}

int finish_eat()
{
        if( !query("weapon_prop") ) return 0;
        set_name("羊腿骨头", ({ "bone" }) );
        set_weight(150);
        set("long", "一根啃得精光的羊腿骨头。\n");
        return 1;
}

