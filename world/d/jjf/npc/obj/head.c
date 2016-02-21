#include <armor.h>

inherit HEAD;

void create()
{
        set_name("钢盔", ({"gang kui", "gangkui", "kui", "helmet", "head" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "顶");
                set("material", "steel");
		set("long", "一顶结实的钢盔。\n");
		set("value", 1000);
                set("armor_prop/armor", 5);
        }
        setup();
}

