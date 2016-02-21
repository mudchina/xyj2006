#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "乱石坡");
  set ("long", @LONG

乱石坡乱石遍地，大的小的到处都是。坡上极干燥，所生草木唯
有红柳，如在山上笼了一团红云。向东可看到碧波潭，一汪潭水
被四面围在山中。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/shanyao" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"xiaolu4",
  "northwest" : __DIR__"shipo2",
]));

  setup();
}

