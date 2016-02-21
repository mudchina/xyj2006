// tongjia.c
#include <ansi.h>
inherit EQUIP;

void create()
{
        set_name(YEL "熟铜甲" NOR, ({"tong jia","tongjia","jia","armor"}));
        set_weight(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
	    set("long", "一件金灿灿的熟铜甲。\n");
                set("value", 10000);
                set("material", "iron");
                set("armor_type", "cloth");
                set("armor_prop/armor", 50);
             }
}
