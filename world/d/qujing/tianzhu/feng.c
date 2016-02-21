// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "凤亭");
  set ("long", @LONG

这是一座绯色瓦顶的双层凤亭，亭檐上雕着飞凤望月，亭里楣
木上是凤翔万里图。凤亭外西边有一十三曲桥廊，通向宫中的
御花园。

LONG);

  set("exits", ([
        "west"   : __DIR__"yuhua",
        "north"   : __DIR__"hou4",
      ]));
  set("objects", ([
        __DIR__"npc/taijian"   : 2,
      ]));

  setup();
}


