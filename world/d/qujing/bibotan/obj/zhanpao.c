#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("锦绣战袍", ({ "zhanpao" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一件丝织锦袍。\n");
                set("material", "cloth");
                set("unit", "件");
                set("armor_prop/armor", 20);
		set("armor_prop/dodge", 10);
		set("armor_prop/personality", 3);
                set("armor_prop/spirituality", 3);
        }
        setup();
}

