#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "药铺");
  set ("long", @LONG

祭赛国中人人好武，有个碰破擦伤在所难免，所以药铺的生意也
是相当不错。当家的大夫原是宫中的御医，还是有两把刷子的。
来看病抓药的人把门槛都踏平了。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/doctor" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"westmarket",
]));

  setup();
}


