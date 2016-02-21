#include <armor.h>

inherit NECK;

void create()
{
        set_name("银项链", ({ "silver necklace", "necklace" }));
        set("weight", 500);
        set("long", "一串银光灿灿的项链，是少女们喜爱的饰物。\n");
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("value", 400);
                set("material", "gold");
		set("wear_msg", "$N戴上一条$n。\n");
                set("armor_prop/armor", 1);
        }
        setup();
}

