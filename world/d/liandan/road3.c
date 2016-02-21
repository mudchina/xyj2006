// By Canoe 2001-06-21
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","神农药圃");
	set("long",@LONG
这里是一大药圃,空气中弥漫着药香。地上郁郁葱葱地
长着药材,也许能在这里发现些好药。
LONG
);
	
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"baihuagu10",
  "west":__DIR__"baihuagu11",
  "east":__DIR__"baihuagu12",
  "south":__DIR__"road2",  
]));
	setup();
}
