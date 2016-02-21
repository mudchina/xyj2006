// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/zuofang.c

inherit ROOM;

void create ()
{
  set ("short", "羊肉馆");
  set ("long", @LONG

一座沿街搭棚而建的羊肉馆，一群食客盘腿席地而坐，围着一圈陶
盆陶盘聚在一起撕着羊肉进餐。从里面的厨房里不断地传出阵阵羊
肉香味。

LONG);

  set("exits", ([
        "north"       : __DIR__"xi2",
      ]));

  set("objects", ([ 
    __DIR__"npc/laoban" : 1,
  ]));
  setup();
}

