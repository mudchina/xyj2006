// shoe.c
#include <armor.h>
inherit BOOTS;

void create()
{
        set_name("云履", ({ "shoes" }) );
        set_weight(1700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
		set("long", "一双千层底的云履，是道士们的一般装束。\n");
                set("value", 100);
                set("material", "cloth");
                set("armor_prop/armor", 2);
        }
        setup();
}


