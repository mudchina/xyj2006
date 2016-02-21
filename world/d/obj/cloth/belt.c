#include <armor.h>

inherit WAIST;

void create()
{
        set_name("Ñü´ø", ({ "belt" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸ö");
                set("material", "leather");
		set("value", 100);
                set("armor_prop/armor", 2);
        }
        setup();
}

