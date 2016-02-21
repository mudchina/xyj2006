
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("∞Àÿ‘µ¿≈€", ({"bagua pao", "pao", "cloth"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "º˛");
                set("value", 200);
                set("armor_prop/armor", 3);
                set("armor_prop/spells", 5);

        }
        setup();
}

