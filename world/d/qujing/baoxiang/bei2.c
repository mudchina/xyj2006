// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/bei2.c

inherit ROOM;

void create ()
{
  set ("short", "北街");
  set ("long", @LONG

北街上人来人往，或是渔夫担鱼或是樵夫担柴，城内家的家，户
的户，只斗逍遥。熙熙攘攘，日子过得十分爽快。向北是城门，
向南是王宫所在。

LONG);

  set("exits", ([
        "north"      : __DIR__"bei1",
        "south"      : __DIR__"bei3",
      ]));
  set("objects", ([
        __DIR__"npc/people" : 2,
  ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

