#include <armor.h>

inherit WRISTS;

void create()
{
        set_name("Í¸Ã÷Ë¿¾î", ({ "si juan", "si", "juan" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ìõ");
                set("material", "silk");
		set("value", 1000);
                set("armor_prop/dodge", 1);
        }
        setup();
}

