
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "二郎庙外");
  set ("long", @LONG

这里是二郎庙前一处广场，北面一座大庙，气象恢鸿，那便是
二郎真君的庙宇。光场四周有不少善男信女，青铜炉中青烟绕
绕，看来香火极盛。南面是一大片丘陵，灌江水从陵下缓缓流
过。
LONG);


  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/laotai" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southwest" : "/d/meishan/denglong3",
  "north" : "/d/meishan/erlangmiao",
  "east" : __DIR__"tiezhu",
]));

  setup();
}

