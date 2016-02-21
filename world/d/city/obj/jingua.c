#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name(HIY"金瓜"NOR, ({ "jin gua", "gua", "hammer" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
		set("long", "这是一把沉重的金瓜，是皇城卫士的专用武器。\n");
                set("value", 3);
                set("material", "iron");
		set("wield_msg", "$N拿出一把$n，试了试重量，然後握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_hammer(15);
        setup();
}
