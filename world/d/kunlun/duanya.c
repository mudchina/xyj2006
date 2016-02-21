inherit ROOM;

void create ()
{
  set ("short", "断崖");
  set ("long", @LONG

    这里看起来已经是无路可走了，前面是一条深深的
峡谷。
LONG);
set ("outdoors", 1);  set("exits", ([ /* sizeof() == 1 */
  "north" : "/d/moon/yunu1",
]));
setup();
}

void init()
{
        add_action("do_jump", "jump");
}
int do_jump(string arg)
{       
        object me;
        me=this_player();

        if ( !arg || ((arg != "down") ))
                return notify_fail("你要往哪跳？\n");
        else
message_vision("$N叹了口气，眼一闭，纵身往峡谷里跳去．．．\n",me);

                me->move("/d/kunlun/yaxia");
                message_vision("眼前一亮，原来这里竟然是一个世外桃源．\n", me);
                return 1;
}
