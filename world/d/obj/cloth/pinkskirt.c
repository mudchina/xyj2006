#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("五色梅浅红裙", ({ "pink skirt", "skirt" }) );
        set_weight(2700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一袭长裙，上面绣了几道水波．\n");
                set("unit", "袭");
                set("value", 3000);
                set("material", "cloth");
                set("armor_prop/armor", 5);
                set("armor_prop/dodge", 10);
        }
        setup();
}

