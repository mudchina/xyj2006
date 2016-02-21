#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("赤龙斩", ({"dragon blade", "blade", "dao"}) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 5000);
                set("material", "iron");
                set("long", "这是一把发着红光的弯刀。\n");
                set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
        }
        init_blade(50);
        setup();
}

