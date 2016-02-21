// pao.c
#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(HIW "ฯษาย" NOR, ({"xian yi", "yi"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ผþ");
                set("value", 0);
                set("material", "cloth");
                set("armor_prop/armor", 30);
                set("armor_prop/armor_vs_force", 200);
                set("armor_prop/dodge", 30);
                set("armor_prop/spells", 10);
             }
	setup();
}

