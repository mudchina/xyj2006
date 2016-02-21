#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "怪石崖");
  set ("long", @LONG

前方的怪石如一堵高墙挡在路上。崖上挂着一簇簇的乱葛藤萝，
大部分已经焦黄枯萎。崖下一扇大石门，门边有个大的石碣，写
了“号山枯松涧火云洞”八个大字。
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kusongjian",
  "north" : __DIR__"yongdao1", 
]));

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/xiaoyao" : 2,
  __DIR__"npc/kuairufeng": 1,
]));



  set("outdoors",1);
  create_door("north", "石门", "south", DOOR_CLOSED);
  
  
  setup();
}
 

