#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "月门");
  set ("long", @LONG

月门恰如一轮满月，将前厅和后院隔开。一般的小妖未经允许是
不许到后院的，在此并看不到几个人影。从门缝中传出淡淡的香
气，夹杂着些风火雷电的声音，平添几丝诡臆。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/qingshan" : 1,
  __DIR__"npc/niqiu" : 1,
]));
//  set("outdoors", 1);
  

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"longtai2",
  "north" : __DIR__"hua_qian",
  "east" : __DIR__"yuetai1",
]));

  create_door("north", "月牙门", "south", DOOR_CLOSED);
//      
        set("water", 1);
//  
  setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "north" ) {
        if (objectp(present("tianboer xiao", environment(me))))
        return notify_fail("天波儿笑喝道：后院是禁地，还是莫去的好！\n");
        if (objectp(present("xiaoboer tian", environment(me))))
        return notify_fail("笑波儿天喝道：后院是禁地，还是莫去的好！\n");
        }   
        return ::valid_leave(me, dir);
}

