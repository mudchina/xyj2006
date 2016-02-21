#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "石崖");
  set ("long", @LONG

石崖上甚是平坦，打扫的也十分干净，没有什么杂物，象是有人
常在此走动。崖边有一石桌，旁有四个石凳。后面有一小屋，屋
前石碑上刻有“木仙庵”三字。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/hunter" : 2,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"ping",
  "southwest": __DIR__"huilin",
  "southeast": __DIR__"bolin",
  "south" : __DIR__"xinglin",
]));

  setup();
}


