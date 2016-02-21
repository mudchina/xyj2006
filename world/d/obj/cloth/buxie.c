#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("Բ�ڲ�Ь", ({"shoes"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
		set("value", 100);
                set("material", "cloth");
                set("armor_prop/armor", 3);
        }
        setup();
}

