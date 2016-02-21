// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/shatan5.c

inherit ROOM;

void create ()
{
  set ("short", "沙滩");
  set ("long", @LONG

这里气候干燥，土地龟裂。中间是一片沙滩，被人踩出一条大路，
路上压有几条大车轱辘碾出的深深痕迹，路边零星散有一些残破
的砖石木料。这里气候干燥，土地龟裂。

LONG);

  set("exits", ([
        "northeast"    : __DIR__"shatan4",
        "southwest"    : "/d/qujing/tongtian/xiaolu3",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

