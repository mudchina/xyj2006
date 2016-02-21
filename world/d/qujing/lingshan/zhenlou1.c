//Cracked by Roath
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "珍楼");
  set ("long", @LONG

珍楼下有无数奇珍异宝陈列楼中，靠西有一排麒麟皮凤背纹长
椅，以供雷音寺贵宾休息。东边是殿门通向大雄宝殿，往上是
珍楼的二楼。

LONG);

  set("exits", ([
        "east"   : __DIR__"daxiong",
        "up"   : __DIR__"zhenlou2",
      ]));
  set("objects", ([
        __DIR__"npc/baixiong" : 1,
        __DIR__"npc/xiantong" : 2,
     ]));

  setup();
}

