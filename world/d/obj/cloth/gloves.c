#include <armor.h>

inherit HANDS;

void create()
{
        set_name("ÊÖÌ×", ({ "gloves" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ë«");
                set("material", "cloth");
		set("value", 100);
                set("armor_prop/armor", 2);
        }
        setup();
}

