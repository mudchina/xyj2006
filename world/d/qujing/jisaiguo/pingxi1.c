#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "平西大路");
  set ("long", @LONG

这是一条宽阔笔直的大官道，足可容得下十马并驰。往西直通向
西域诸国，东边就到了祭赛国。
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"pingxi",
  "northwest" : "/d/qujing/xiaoxitian/lindao6",
]));

  setup();
}

