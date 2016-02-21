// magua.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("Æ¤ÅÛ", ({"pipao"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
		set("value", 1000);
                set("material", "cloth");
                set("armor_prop/armor", 10);
        }
        setup();
}

