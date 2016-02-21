#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "乱石冈");
  set ("long", @LONG

乱石山上乱石遍地，大的小的到处都是。坡上极干燥，所生草木
唯有红柳，如在山上笼了一团红云。南边向上去是山顶，东边潭
水碧绿，如同暖玉般卧在山中。
LONG);
  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/shanyao" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"shishan",
  "northeast" : __DIR__"shipo3",
]));

  setup();
}

