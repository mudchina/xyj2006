// shoupi.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("ЭтвТ", ({"cloth"}));
	set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "Мў");
		set("armor_prop/armor", 1);
        }
        setup();
}

