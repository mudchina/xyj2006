//sgzl 
 
#include <room.h>
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short", "南天门");
  set ("long", @LONG

只见那南天门，碧沉沉，琉璃造就；明幌幌，宝玉妆成。
两边摆数员镇天元帅，一员员顶梁靠柱，持铣拥旄；四
下列十数个金甲神人，一个个执戟悬鞭，持刀仗剑。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"dadao6",
  "north" : __DIR__"jieyindian",
  "west" : __DIR__"tgqs4",
  "east" : __DIR__"tgqs5",
]));

  create_door("north", "南天门", "south", DOOR_CLOSED);

  set("objects", ([
  __DIR__"npc/moli-qing"   : 1,
  __DIR__"npc/tian-bing"   : 4,
]));


  set("outdoors", 1);

  setup();
}
 
