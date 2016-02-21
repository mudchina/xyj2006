#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
   set_name(HIY"金帝巧克力"NOR+"", ({"chocolate", "ice", "qiaokeli"}));
                  set("unit", "块");
                  set("long", MAG"金帝巧克力，只给最爱的人。\n"NOR);
                set("value", 0);
                set("drug_type", "零食");
        setup();
}

int do_eat(string arg)
{
object me = this_player();
        if (!id(arg))
                return notify_fail("你要吃什么？\n");
message_vision(MAG"$N一口将巧克力吃了下肚，顿时心静神怡，不觉得陶醉了起来！\n"NOR, this_player())
;
me->set("water",1000);
me->set("food",1000);
        destruct(this_object());
        return 1;
        }

