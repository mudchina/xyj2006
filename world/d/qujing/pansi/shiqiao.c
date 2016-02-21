// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "石桥");
  set ("long", @LONG

山溪上一座石桥悠悠架起，两边古树森齐，桥下潺潺流水通长
溪，桥东面是一望无际的乔木树林，桥西北面是茅草屋，清清
雅雅若仙庵。

LONG);

  set("exits", ([
        "east"    : __DIR__"qiaolin3",
        "northwest"    : __DIR__"maowu",
      ]));
  set("objects", ([
        __DIR__"npc/girl1"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

