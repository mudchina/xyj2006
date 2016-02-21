// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/xi2.c

inherit ROOM;

void create ()
{
  set ("short", "西街");
  set ("long", @LONG

西街上人流不息，城内家的家，户的户，只斗逍遥。大都是渔夫
或樵夫，丰衣足食，日子十分爽快。向西是出城之路，向东可以
抵达宝象国王宫。南边有家饭馆，飘出烤羊肉香。

LONG);

  set("exits", ([
        "west"       : __DIR__"xi1",
        "east"       : __DIR__"xi3",
        "south"      : __DIR__"yangrou",
      ]));

  set("objects", ([
        __DIR__"npc/people" : 2,
  ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

