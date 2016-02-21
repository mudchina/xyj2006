#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "乱石山");
  set ("long", @LONG

乱石山上乱石遍地，大的小的到处都是。坡上极干燥，所生草木
唯有红柳，如在山上笼了一团红云。远望碧波潭中浪淘滚滚，岸
边芦花如雪。
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"shigang1",
  "northdown" : __DIR__"shigang2",
]));

  setup();
}

