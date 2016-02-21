// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "皮货铺");
  set ("long", @LONG

门口晒着几张刚硝好的皮革，屋里摆满各式各样的皮货和野兽
皮。屋角排着几口大染缸，里面还染着一些皮货。窗子下有货
架陈列着待售的皮制品。

LONG);

  set("exits", ([
        "east"    : __DIR__"jiedao4",
      ]));
  set("objects", ([
        __DIR__"npc/sun"    : 1,
      ]));
  setup();
}

