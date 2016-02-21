//Cracked by Roath
// Room: /moon/road.c

inherit ROOM;

void create ()
{
  set ("short", "小路");
  set ("long", @LONG

两边佳木笼葱，奇花烂灼，一带清流，从花木深处曲折泻于石隙之下。往
北看去，路势渐趋平坦开阔。
LONG);

  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road3",
  "south" : __DIR__"road1.c",
]));
  set("objects",(["/d/obj/flower/yehua.c":1,]));

  setup();
}






