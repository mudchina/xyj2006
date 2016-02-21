// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "花亭子");
  set ("long", @LONG

洞里的空厅边有一六角石花亭子，亭柱边种满了各种各样的奇
花异草，散发出异香。亭上有一圆石桌，六只圆石凳，花亭子
的东面是内宫。

LONG);

  set("exits", ([
        "north"   : __DIR__"dongting",
        "east"   : __DIR__"neigong",
      ]));
  set("objects", ([
        __DIR__"obj/momo"   : 2,
        __DIR__"npc/yao"   : 5,
        __DIR__"npc/xiezi"   : 1,
      ]));

  setup();
}



