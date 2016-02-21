//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("丹盘", ({"dan pan"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 5);
                set("no_get",1);
                set("material", "wood");
        }
        setup();
}
void init()
{
        add_action("do_prepare","hold");
}

int do_prepare(string arg)
{
        object ob = this_player();
        if( ! arg || arg != "dan pan" )
                return notify_fail("你要握着什么？\n");

        if( ob->query_temp("prepared") )
                return notify_fail("你不是已经准备好了吗？\n");

        message_vision(HIC"只见$N把丹盘卧在手中，做好接人参果的姿势。\n"NOR,ob);
        ob->set_temp("prepared",1);
        return 1;
}
