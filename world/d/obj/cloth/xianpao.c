#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("оиеш", ({"xian pao", "pao", "cloth"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "╪Ч");
                set("value", 2000);
                set("material", "cloth");
                set("armor_prop/armor", 10);
                set("armor_prop/dodge", 5);
                set("armor_prop/spells", 5);
             }
	setup();
}

