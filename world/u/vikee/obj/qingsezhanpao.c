//qingsezhanpao.c
//vikee 2000.7.

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIC"青丝战袍"NOR, ({"qingse zhanpao", "color cloth", "pao" }) );
	set("long", "此乃一叶知秋护身战袍，用尽毕生内力练制而成。\n");
	set_weight(0);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 500);
		set("armor_prop/dodge", 500);
                set("armor_prop/personality", 10);
                set("value", 50000);
              
	}
	setup();
}

