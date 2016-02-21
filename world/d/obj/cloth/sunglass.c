#include <armor.h>

inherit HEAD;

void create()
{
        set_name("¡ñ^¡ñ", ({ "sun glasses", "glasses" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸±");
                set("material", "glass");
		set("value", 100);
                set("armor_prop/armor", 2);
        }
        setup();
}

