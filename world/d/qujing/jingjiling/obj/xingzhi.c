#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("杏花枝", ({ "xinghua zhi","zhi","jian", "sword" })
);
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("material", "wood");
                set("long", "这是一根细长的杏花枝，上面还有朵待放的杏花。\n");
                set("wield_msg", "$N轻轻的闻了闻杏花，然后将$n握在手中。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
        }
        init_sword(1);
        setup();
}

