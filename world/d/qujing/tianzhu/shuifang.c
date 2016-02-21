// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "水房");
  set ("long", @LONG

水房上的烟囱冒着淡淡的白烟，房里一个大水灶正在烧着开水，
靠墙放着一些水桶和一口大水缸。门口有几把小凳，供路客来
打水顺便歇歇脚。

LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao81",
      ]));
  set("resource", ([
    "water" : 1,
  ]));

  setup();
}


