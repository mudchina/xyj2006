// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/xi4.c

inherit ROOM;

void create ()
{
  set ("short", "西街");
  set ("long", @LONG

这里差不多是市中心了，路面宽敞，人们走来走去，非常热闹。北
面有一门面挂着各式各样的锡器，东南方向可以远远地看见王宫的
群宫群殿。

LONG);

  set("exits", ([
        "west"       : __DIR__"xi3",
        "north"      : __DIR__"xiqi",
        "northeast"  : __DIR__"gongmen",
      ]));
  set("objects", ([
        __DIR__"npc/people" : 2,
  ]));

  set("outdoors","/d/qujing/baoxiang");

  setup();
}

