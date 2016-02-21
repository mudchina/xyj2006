#include <armor.h>
inherit BOOTS;

void create()
{
        set_name("花褶靴", ({ "flower boots", "boots" }) );
        set_weight(1700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
		set("long",
"一双皮靴，上等牛皮制成。做功考究，裁剪精致，看上去气派不凡。\n");
                set("value", 800);
                set("material", "cloth");
                set("armor_prop/armor", 2);
		set("armor_prop/personality", 1);
        }
        setup();
}

