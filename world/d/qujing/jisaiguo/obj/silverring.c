#include <armor.h>

inherit FINGER;

void create()
{
        set_name("银戒指", ({ "silver ring", "ring" }));
        set("weight", 500);
        set("long", "一个银光灿灿的戒指。\n");
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("value", 400);
                set("material", "gold");
		set("wear_msg", "$N戴上一个$n。\n");
                set("armor_prop/armor", 1);
        }
        setup();
}

