#include <weapon.h>

inherit WHIP;

void create()
{
        set_name("芦花草", ({ "luhua cao", "cao" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
		set("long", "一根细长的芦花草，随风飘摆。\n");
                set("value", 0);
                set("material", "iron");
                set("wield_msg", "$N拿出一根细长的芦花草握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_whip(1);
        setup();
}

