//Cracked by Roath
#include <weapon.h>
inherit DAGGER;

void create()
{
        set_name("齿阙环", ({"chique huan", "huan", "dagger"}));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄圆铁环，边上有刺口。\n");
                set("value", 500);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
        }
        init_dagger(10);
        setup();
}

