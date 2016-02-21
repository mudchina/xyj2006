// magua.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("Çà¶Ð°À", ({"qingduan ao", "ao"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("value", 250);
                set("material", "cloth");
                set("armor_prop/armor", 2);
        }
        setup();
}

