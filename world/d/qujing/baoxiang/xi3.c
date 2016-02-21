// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/xi3.c

inherit ROOM;

void create ()
{
  set ("short", "西街");
  set ("long", @LONG

街心由从山里运来的石板条筑成，看上去宽敞。路两边人不少，
打扮装饰奇特。向东南方向望去可以见到许多高大的宫殿，那里
便是王宫所在地。

LONG);

  set("exits", ([
        "west"       : __DIR__"xi2",
        "east"       : __DIR__"xi4",
      ]));
  set("objects", ([
        __DIR__"npc/people" : 2,
  ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

