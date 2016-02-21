//坤卦象征地
//坤、北方

#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "后花园");
  set ("long", @LONG

后花园中非常的清雅，看不到什么人。虽说是花园，奇怪的是不
见有花朵。种植的大多是些奇怪的草类，五颜六色的。东一堆，
西一簇，向是规划的非常仔细。隐见花园正中一座小厅，在草木
衬托之下显得非常雅致。
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
//  set("outdoors", 1);
  
  set("position", "坤");
  set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"hua_ken",
  "southeast" : __DIR__"hua_zhen",
]));
//      
        set("water", 1);
//  
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

        message_vision("$N轻轻一跳，居然跳到了小亭中。\n",me);
                me->move("/d/qujing/bibotan/furong");
                me->set_temp("enter_position", "坤");
                tell_room( environment(me), "噗嗵一声，有个人跳了进来。\n", ({me}));
                return 1;
}

