//changan city

inherit ROOM;

void create ()
{
        set ("short", "粮仓");
        set ("long", @LONG

这是一家生意兴隆的粮店。丰老板坐在柜台后面笑容可鞠地接待着客
人。活计们在一边忙忙碌碌地工作着。如果你身无分文，你还可以在
这里向丰老板打一些零工，以赚一些钱。粮店的墙上贴着一张破旧的
告示(gaoshi)。
LONG);

        set("item_desc", (["gaoshi" : "现在正紧缺人手，急需雇佣一批短工来干活。

work	开始工作。
", ]));

        set("exits", 
        ([ //sizeof() == 4
		"west" : __DIR__"beiyin4",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/feng" : 1,
        ]));

//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
}


void init()
{
//        add_action("do_work", "work");
}

int do_work(string arg)
{
        object ob;
        object me;

        me = this_player();

   if (! me->query_temp("working_in_liangdian")) {
message_vision("$N从车上卸下一袋袋的大米，又垒在墙边，累的腰酸腿疼！\n",me);
        me->add("kee",-30);
        me->add("sen",-30);
        ob = new("/obj/money/silver");
        ob->move(me);
        message_vision("丰老板笑眯眯地对$N说：辛苦啦，这是你的工钱。\n",me);
        me->set_temp("working_in_liangdian",1);
        call_out ("reset_work",1,me);
    } else
    {
        message_vision("丰老板赶紧把$N扶起来：先歇一会儿。\n",me);
    }
        return 1;
}
void reset_work (object me)
{
        me->set_temp("working_in_liangdian",0);
}

