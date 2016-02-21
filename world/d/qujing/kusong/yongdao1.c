//Cracked by Roath
#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "甬道");
  set ("long", @LONG

甬道内发出一股血腥气。墙上挂着油灯，忽明忽暗的灯光隐隐照
出了前后的道路。南面是一扇石门。
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"guaishiya", 
  "northwest" : __DIR__"yongdao3",
  "northeast": __DIR__"yongdao2",
]));
  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/yao1" : 2,
]));


  create_door("south", "石门", "north", DOOR_CLOSED);


  setup();
}

