// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "南洞");
  set ("long", @LONG

南洞里几块大石上晾着兽皮之类的东西，洞穴里鬼旋风打转，
发出呜呜的声响。洞顶低垂，从上挂下钟乳石，洞的北面通向
洞的出口。

LONG);

  set("exits", ([
        "north"   : __DIR__"dongmen",
      ]));
  set("objects", ([
        __DIR__"npc/yao1"   : 2,
        __DIR__"npc/jinjiao"   : 1,
      ]));

  setup();
}


