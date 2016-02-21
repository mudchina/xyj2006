#include <armor.h>
inherit BOOTS;

void create()
{
        set_name("Ì¤ÔÆÑ¥", ({ "cloudy shoes", "shoes" }) );
        set_weight(1700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ë«");
                set("value", 4500);
                set("material", "cloth");
                set("armor_prop/armor", 2);
                set("armor_prop/dodge", 10);
        }
        setup();
}

