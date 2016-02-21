#include <weapon.h>

inherit RAKE;

void create()
{
        set_name("龙齿钯", ({ "dragon rake", "pa","rake" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 5000);
                set("material", "iron");
                set("long", "一柄长长的七齿钢耙。\n");
                set("wield_msg", "$N抄起一柄$n，在头上挥舞了一圈。\n");
        }
        init_rake(50);
        setup();
}

