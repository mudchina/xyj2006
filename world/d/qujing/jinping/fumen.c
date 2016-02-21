// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "府门");
  set ("long", @LONG

一座高墙飞檐的门楼耸立在眼前，门楼下有一回廊。回廊由
青雕石基双彩盘花柱撑起，两边是各种花草仙石，往南有一
入口，东边则临街。

LONG);

  set("exits", ([
        "east"   : __DIR__"xiaojie4",
        "south"   : __DIR__"datang",
      ]));
  set("objects", ([
        __DIR__"npc/guan"   : 1,
      ]));

  setup();
}


