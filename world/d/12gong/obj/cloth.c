#include <ansi.h>
#include <armor.h>

//inherit F_UNIQUE;
inherit EQUIP;
inherit F_UNIQUE;

void create()
{
        set_name(HIM"飕云丝袍"NOR, ({"souyun sipao", "sipao", "cloth"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一件薄如婵娟，轻如蝉丝，而泛出九彩云色的丝袍。\n");
		set("no_sell", 1);
		set("no_drop", 1);
		set("no_put", 1);
                set("unit", "件");
                set("value", 1000);
                set("material", "crimsonsteel");
                		set("replace_file", "/d/obj/cloth/hufa-jiasha");

				set("armor_prop/armor", 100);
                set("armor_prop/dodge", 50);
                set("armor_prop/spells", 30);
             }
}
