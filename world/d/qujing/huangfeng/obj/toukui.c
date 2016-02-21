//created by smile 12/13/1998
#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIY"黄金战盔"NOR, ({ "golden bonnet", "bonnet" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "顶");
		set("long", "一顶黄金打制而成的头盔，闪闪发光。\n");
                set("material", "gold");
                set("value", 10000);
                set("armor_prop/armor", 20);
        }
        setup();
}

