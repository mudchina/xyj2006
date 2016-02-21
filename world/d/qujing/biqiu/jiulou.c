// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "酒楼");
  set ("long", @LONG

酒楼里摆着几张桌子，上面有几碟小菜几盘炒豆。柜台上放着
几坛老酒，香气扑鼻令人垂涎。屋角有一木炭烤架，架子上的
肉熏得紫红紫红。

LONG);

  set("exits", ([
        "southeast"    : __DIR__"jie4",
      ]));
  set("objects", ([
        __DIR__"npc/kanduli"    : 1,
      ]));
  setup();
}

