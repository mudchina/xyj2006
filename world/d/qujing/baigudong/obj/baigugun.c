//baigugun writted buy smile 12/08/98
#include <ansi.h>
#include <weapon.h>

inherit STICK;

void create()
{
        set_name(HIW "白骨棍" NOR, ({"baigu stick","stick"}));
        set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("value", 1000);
                set("material", "wood");
                set("wield_msg", "$N「嘿嘿」阴笑一声,拿起一根$n握在手中。\n");
        }
        init_stick(50);
        setup();
}

