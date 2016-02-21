// jinjia.c 金甲
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("战甲", ({"armor"}));
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", "一件战甲．\n");
                set("material", "steel");
                set("value", 20000);
                set("armor_prop/armor", 55);
		set("armor_prop/dodge", -5);
        }
        setup();
}


