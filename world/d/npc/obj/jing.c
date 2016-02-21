#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(HIM"封虹巾"NOR, ({ "jin" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
		set("long", "一根粉红的丝带，用来束发。\n");
                set("value", 0);
                set("no_zm",1);
                set("no_give",1);
                set("no_put",1);
                set("material", "cloth");
                set("armor_prop/armor", 30);
	    }
        setup();
}

