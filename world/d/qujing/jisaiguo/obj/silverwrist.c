#include <armor.h>

inherit WRISTS;

void create()
{
        set_name("银手镯", ({ "silver wrist", "wrist" }));
        set("weight", 500);
        set("long", "一对银光灿灿的手镯。\n");
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "对");
                set("value", 400);
                set("material", "gold");
		set("wear_msg", "$N把$n套到手腕上。\n");
                set("armor_prop/armor", 1);
        }
        setup();
}

