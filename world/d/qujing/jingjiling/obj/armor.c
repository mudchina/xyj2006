#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("烟里火比甲", ({"smoky armor","jia","armor"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
            set("long", "一件女子穿的红色软甲。\n");
                set("value", 8000);
                set("material", "wood");
                set("armor_prop/armor", 25);
		set("armor_prop/personality", 3);
		set("armor_prop/dodge", 5);
		set("female_only", 1);
             }
                         setup();
}

