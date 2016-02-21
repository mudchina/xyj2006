inherit ROOM;

void create ()
{
  set ("short", "奈何桥");
  set ("long", @LONG

这是一座仅数寸之宽，数长之长的石桥。上有寒风滚滚，下是
血浪滔滔。桥上左右无扶手，险峻之路如同匹练搭长江，桥下
之水阴气逼人，腥风扑鼻。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"bidouya",
  "north" : __DIR__"huangwai",
]));
  set("hell", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shizhe" : 2,
]));

  setup();
}
/*
void init()
{
        add_action("do_jump", "jump");
}
int do_jump(string arg)
{       
        object me;
        me=this_player();

        if ( !arg || ((arg != "bridge") ))
                return notify_fail("你要往哪跳？往桥下跳准死．．．\n");
        else

message_vision("$N不顾一切的往桥下跳去．．．\n",me);
                me->move("/d/diyu/gufen");
                me->die();
                return 1;
}

*/
