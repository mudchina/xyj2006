#include <armor.h>

inherit HEAD;

void create()
{
        set_name("魔幻经纶", ({ "mohuan jinglun", "jinglun", "hat" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "顶");
                set("long", "一顶黑红相间的法冠,传说戴上它有奇怪的魔力。\n");
                set("material", "steel");
                set("value", 1000);
		set("no_sell", 1);
               set("no_give", 1);
               set("no_put", 1);
               set("no_drop", 1);
               set("no_get", 1);
                set("armor_prop/armor", 3);
                set("armor_prop/intelligence", 10);
		set("armor_prop/personality", 1);
        }
        setup();
}

