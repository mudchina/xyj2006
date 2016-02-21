// by Repoo
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIR"众神之殿门口"NOR);
  set ("long", @LONG
  
  一个宽阔的广场中间屹立着一座古老的神殿，殿上有块匾。
上书：众神之殿。其间不时有光彩在流动。

在神殿四周东西南北向各有两棵树，一枯一荣。充满了怪异。
这个屹立在广场中间的神殿应该是可以进去的。
 
LONG);
  set("exits", ([ /* sizeof() == 1 */
    //  "enter" : __DIR__"shendian",
]));
  set("objects", ([
]));
  set("outdoors", 1);
  setup();
}
void init()
{
        add_action("do_enter", "enter");
        set("no_clean_up", 1);
}

int do_enter()
{
        object me;
        me=this_player();

  if(me->query_temp("fahua/read") == "done")
   {
   me->move("/d/shendian/shendian");
    return 1;
   }
     else
    {
                 return notify_fail("你是怎么来到这里的？\n");
   }
}
