#include <armor.h>
#include <ansi.h>
inherit NECK;

void create()
{
        set_name(HIW"ÑªÁáçç"NOR, ({ "necklace" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "´®");
                set("no_zm",1);
                set("no_give",1);
                set("material", "pearl");
		set("value", 0);
                set("no_put",1);
                set("armor_prop/armor", 50);
        }
        setup();
}

