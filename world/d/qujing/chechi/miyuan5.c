// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/miyuan.c

inherit ROOM;

void create ()
{
  set ("short", "秘院");
  set ("long", @LONG

这里是一座秘密的四方庭院，四周是高墙。院内阴气习习，罂
粟盛开。南边是藏经楼的后墙，墙下有一暗通道。

LONG);

  set("exits", ([
        "south"    : __DIR__"cangjing",
      ]));

  set("objects", ([
         __DIR__"npc/langli"    : 1,
         __DIR__"npc/chaili"    : 1,
         __DIR__"npc/beili"    : 1,
         __DIR__"npc/mali"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

