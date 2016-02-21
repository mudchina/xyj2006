#include <weapon.h>

inherit STICK;

void create()
{
        set_name("古藤杖", ({ "guteng zhang","zhang","gun", "bang" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("material", "wood");
                set("long", "一根轻飘飘深色古藤杖。\n");
                set("wield_msg", "$N拿起一根$n拄在手中。\n");
                set("unwield_msg", "$N将$n插回后腰。\n");
        }
        init_stick(10);
        setup();
}

