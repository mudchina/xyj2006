// Room: /d/death/road3.c

inherit ROOM;

void create()
{
        set("short", "黑暗之中");
        set("long", @LONG

也不知是到了那里，只觉得四周异常狭小．上下左右不过寸余．
连翻身都是不可能的．什么也看不到，什么也听不到．空气中
有一股腐烂的味道．
LONG
        );
set("exits", ([ /* sizeof() == 4 */
]));

        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_open", "open");
}

int do_open(string arg)
{       
        object me;
        me=this_player();

        if ( !arg || ((arg != "guancai")&&(arg != "棺材") ) )
                return notify_fail("你要打开什么？\n");
        else {
       
            message_vision("$N飞起一脚踢开棺材，爬了出去。\n\n",me);
	    me->reincarnate();
	    me->set("gin", (int)me->query("max_gin"));
            me->move("/d/diyu/gufen");
            message_vision("\n坟上的土动了动，$N顶着满头的杂草钻了出来。\n",me);
        }
                return 1;
}

