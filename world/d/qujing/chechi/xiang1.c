// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/xiang1.c

inherit ROOM;

void create ()
{
  set ("short", "厢廊");
  set ("long", @LONG

长长的厢廊，两边是镶花气窗，廊檐上挂有串串铜铃，随风叮
当。地上铺有一条素色布毯，厢廊的西南方向是三清殿，东边
通往厢房。

LONG);

  set("exits", ([
        "southwest"    : __DIR__"sanqing",
        "east"         : __DIR__"xiang2",
      ]));
  set("objects", ([
         __DIR__"npc/daoshi"    : 1,
      ]));
  setup();
}

