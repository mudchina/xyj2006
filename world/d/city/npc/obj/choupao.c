// linen.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("³ñÅÛ", ({"choupao"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "¼þ");
                set("value", 1000);
                set("armor_prop/armor", 5);
        }
        setup();
}

