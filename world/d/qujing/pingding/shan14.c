// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "山道");
  set ("long", @LONG

崎岖的山道在山坡上蜿蜒，四处是荒山野岭，云雾蒙蒙一片，
远看林海郁郁苍苍。路边有不尽的古树和藤葛，西风阵阵，吹
得满天的风沙。

LONG);

  set("exits", ([
        "northeast"   : __DIR__"wulin2",
        "southwest"   : __DIR__"yalong1",
      ]));
  set("outdoors", __DIR__);

  setup();
}



