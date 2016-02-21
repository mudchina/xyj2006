// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG

这里是长长的走廊，两边的石壁拥挤狭窄，走廊顶上垂下长短
不一的钟乳石，地上长着一些石笋。走廊的一头通向里面的过
道，另一头通向大厅。

LONG);

  set("exits", ([
        "east"   : __DIR__"da",
        "southwest"   : __DIR__"guo",
      ]));
  set("objects", ([
        __DIR__"npc/yao"  : 2,
      ]));

  setup();
}



