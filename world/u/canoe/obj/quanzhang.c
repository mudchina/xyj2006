// 和平权杖
// by canoe

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"和平权杖" NOR, ({"staff" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
              set("long","世界和平万岁！！\n");
                set("value", 0);
        }
        setup();
}

void init()
{
        add_action("do_use","use");
}

int do_use(string arg)
{
        object me,*ob;
        int i;

        me = this_player();

        if( !arg || arg!="staff" )
                return notify_fail("what do you wanna use?\n");

        //if( me->is_fighting() )
                //return notify_fail("it's so irony, you are fighting ya!!\n");

        ob = all_inventory(environment(me));
 message_vision(HIY "$N咳嗽一声，威严地举起了和平权杖，权杖发出柔和的祥光！\n" NOR,me);

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || !ob[i]->is_fighting() ) continue;
       message_vision(CYN "在权杖的祥光下，$N满脸愧疚地停止了战斗。\n"NOR ,ob[i]);
             ob[i]->remove_all_killer();
                add("num",1);
        }
                if(!query("num")) write("没都没有人打架，你发什麽疯？\n");
                        else delete("num");
                return 1;
}
