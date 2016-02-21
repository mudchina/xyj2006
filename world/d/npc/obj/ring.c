#include <armor.h>
#include <ansi.h>
inherit FINGER;

void create()
{
        set_name(HIW"°×½ð½äÖ¸"NOR, ({ "ring" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸ö");
                set("material", "gold");
		set("value", 0);
                set("no_give",1);
                set("no_zm",1);
                set("no_put",1);
                set("armor_prop/armor", 20);
        }
        setup();
}

