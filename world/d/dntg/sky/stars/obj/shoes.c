#include <armor.h>

inherit BOOTS;

void create()
{
        set_name( "Ь", ({ "shoes" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
                set("long", "һ˫�಼Ь��");
                set("value", 100);
                set("material", "boots");
                set("armor_prop/dodge", 3);
        }
        setup();
}

