// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/shatan3.c

inherit ROOM;

void create ()
{
  set ("short", "沙滩");
  set ("long", @LONG

这里气候干燥，土地龟裂。中间是一片沙滩，被人踩出一条大路，路上压
有几条大车轱辘碾出的深深痕迹，路边零星散有一些残破的砖石木料。这
里气候干燥，土地龟裂。
LONG);

  set("outdoors", "/d/qujing/chechi");
  set("exits", ([ /* sizeof() == 2 */
  "southeast" : "/d/qujing/wuji/shandao5",
  "north" : __DIR__"shatan2",
]));

  setup();
}
