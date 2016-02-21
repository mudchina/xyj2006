
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("木桌", ({ "table","zhuo" }));
        set_weight(2000);
	set("long", "这是一张木桌子，虽不精致，倒也实用。\n" );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("material", "wood");
		set("value", 2000);
                set("no_get", 1);
		set("amount",30);
        }
        setup();
}

