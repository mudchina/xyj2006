#include <armor.h>

inherit SURCOAT;

void create()
{
        set_name("竹篓", ({ "zhu lou", "lou" }) );
        set_weight(1000);
        set_max_encumbrance(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("material", "bamboo");
		set("value", 50);
		set_max_items(5);
                set("armor_prop/armor", 1);
		set("wear_msg", "$N将$n背到了背后。\n");
                set("long", "一个绿竹篓，可以背在肩上。\n");
        }
        setup();
}

