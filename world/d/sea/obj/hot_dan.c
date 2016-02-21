#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name(HIR"红丹瓶"NOR, ({"hongdan ping", "ping", "skin"}));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个红色的小丹瓶，掂在手里重重的。\n");
                set("unit", "个");
		set("no_sell",1);
                set("value", 10000);
                set("max_liquid", 10);
        }

        // because a container can contain different liquid
        // we set it to contain wine at the beginning
        set("liquid", ([
                "type": "longgong_hot",
                "name": "玄火酒",
                "remaining": 10,
                "drunk_apply": 5,
        ]));
}

