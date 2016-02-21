// ironarmor.c
#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
        set_name(YEL"黄金战甲"NOR, ({"gold armor", "jia", "armor"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
	        set("long", "上古十二神甲之：黄金甲。\n");
                set("value", 0);
                set("no_put",1);
                set("no_zm",1);
//                set("no_give",1);
                set("material", "gold");
                set("armor_prop/armor", 150);
		set("armor_prop/dodge", -10);
             }
        setup();
}

