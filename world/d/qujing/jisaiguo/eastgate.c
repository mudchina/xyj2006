#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "祭赛国东门");
  set ("long", @LONG

这里就到了祭赛国的东门，道路非常的宽广，足可容得下十马并
驰。笔直的土路直通向城中，乘马和徒步赶路的人来往不绝，可
见城中之繁华。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/guard" : 2,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
//  "east" : __DIR__"pingxi",
  "west" : __DIR__"crosseast",
  "east" : __DIR__"to-baoxiang1",
]));

  setup();
}

