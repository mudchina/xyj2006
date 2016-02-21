// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "厨廊");
  set ("long", @LONG

廊里有一天然石灶，冒着柴烟，上有一口大铜锅炖着什么肉。
旁边是方方正正的石桌，上有石碗石盘。两块大石头摆在桌边
俨然一对石凳。

LONG);

  set("exits", ([
        "east"    : __DIR__"shiyuan",
      ]));
  set("objects", ([
        __DIR__"obj/doufu"    : 1,
        __DIR__"obj/mianjin"    : 1,
      ]));
  setup();
}

