//Cracked by Roath
inherit ITEM;
inherit F_FOOD;
#include <ansi.h>
void create()
{
        set_name(HIW"狗不理"NOR, ({"baozi", "dumpling"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "正宗天津狗不理包子。\n");
                set("unit", "个");
                set("value", 45);
                set("food_remaining", 3);
                set("food_supply", 20);
        }
}
