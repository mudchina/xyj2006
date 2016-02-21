// jinjia.c 金甲
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("金环锁子甲", ({"golden armor","jinjia", "jia", "armor"}));
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", "一件金线织就的宝甲．\n");
                set("material", "steel");
                set("value", 10000);
                set("armor_prop/armor", 60);
		set("armor_prop/dodge", -5);
        }
        setup();
}


