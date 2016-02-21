#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "平西大路");
  set ("long", @LONG

这是一条宽阔笔直的大官道，足可容得下十马并驰。往西直通向
西域诸国，东边就到了祭赛国。南边一条羊肠小路，不知通向何
方，荆棘从生，好像很少有人走过。
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"westgate",
  "west" : __DIR__"pingxi1",
  "southwest" : "/d/qujing/bibotan/yangchang3",
]));

  setup();
}

