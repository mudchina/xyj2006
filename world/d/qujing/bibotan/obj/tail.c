#include <weapon.h>

inherit WHIP;

void create()
{
        set_name("豹尾鞭", ({ "whip"}) );
        set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
		set("long", "一根细长的豹子尾巴。\n");
                set("value", 4000);
                set("material", "iron");
                set("wield_msg", "$N从腰中解下一条$n握在手里。\n");
                set("unwield_msg", "$N将$n缠到腰中。\n");
        }
        init_whip(25);
        setup();
}

