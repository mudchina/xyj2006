#include <weapon.h>

inherit STICK;
inherit F_UNIQUE;

void create()
{
        set_name("菩提杖", ({"puti zhang", "zhang"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
		set("no_sell", 1);
		set("long", "一把淡绿色的玉棒，入手滑腻，颇有些份量。\n");
                set("value", 20000);
                set("material", "steel");
                set("wield_msg", "$N「呼」地一声抽出一把$n握在手中。\n");
		set("replace_file", "/d/obj/weapon/stick/qimeigun");
        }
        init_stick(80);
        setup();
}

