// linen.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("±ø·þ", ({"bingfu", "cloth"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
		set("value", 300);
                set("unit", "¼þ");
                set("armor_prop/armor", 15);
        }
        setup();
}

