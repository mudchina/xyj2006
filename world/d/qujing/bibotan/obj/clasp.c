#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
        set_name(YEL "银簪" NOR, ({ "clasp" }) );
        set_weight(900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一根三寸多长的银簪，是女子用来卡头发的。\n");
                set("material", "silver");
                set("unit", "根");
                set("value", 300);
                set("armor_prop/armor", 1 );
		set("wear_msg", "$N轻轻的将$n插在头发上。\n");
		set("remove_msg", "$N轻轻的将$n从头发上取了下来。\n");
		set("female_only", 1);
        }
        setup();
}

