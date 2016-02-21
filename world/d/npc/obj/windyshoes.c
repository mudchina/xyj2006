// gogogo
#include <ansi.h>
#include <armor.h>
inherit BOOTS;

void create()
{
        set_name(WHT"¼²·çÑ¥"NOR, ({"windy shoes", "shoes" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ë«");
                set("value", 10000);
                set("no_sell", 1);
                set("no_drop", 1);
                set("material", "cloth");
                set("armor_prop/armor", 30);
                set("armor_prop/dodge", 30);
                set("armor_prop/parry", 30);
        }
        setup();
}

