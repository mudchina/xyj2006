//Cracked by Roath
// Room: /moon/road.c

inherit ROOM;

void create ()
{
  set ("short", "回廊");
  set ("long", @LONG

曲折游廊，阶下石子漫成甬路，西边是一间茶蘼爬满了的小
屋，花香馥郁。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"courtyard.c",
  "south": __DIR__"huilang.c",
  "west" : __DIR__"wangmu_room.c",
]));
  set("objects", ([ 
           __DIR__"npc/fairy4" : 1,
  
        ]));
  setup();
}






