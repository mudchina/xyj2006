//Cracked by Roath
// Room: /d/nanhai/gate
inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "山门");
  set ("long", @LONG

这里是南海普陀山的山门，山门上写着：

     净瓶甘露年年盛，斜插垂杨岁岁青。
     落伽山上慈悲主，潮音洞里活观音。

真个仙山宝地，福岛洞天！

LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhike" : 1,
]));
  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"xiaoyuan",
  "southdown" : __DIR__"shanglu",
]));

  create_door("north", "石门", "south", DOOR_CLOSED);
set("valid_startroom", 1);
setup();

"/obj/board/wall_b"->foo();
}

