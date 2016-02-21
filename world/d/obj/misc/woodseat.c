
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("小木凳", ({ "seat","deng" }));
        set_weight(200);
	set("long", "一只由树干切成的小木凳。\n" );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("material", "wood");
		set("value", 20);
		set("no_get", 1);
		set("amount",30);
        }
        setup();
}

