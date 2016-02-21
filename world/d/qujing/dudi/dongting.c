// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "洞厅");
  set ("long", @LONG

一座空旷的大厅，厅子的中间燃着一堆篝火，几个小妖正在围
着篝火大口地吃肉。洞厅的西北面有光亮传来，厅南有一小道
通往花亭子。

LONG);

  set("exits", ([
        "northwest"   : __DIR__"sandong",
        "south"   : __DIR__"huating",
      ]));
  set("objects", ([
        __DIR__"npc/yao"   : 6,
      ]));

  setup();
}



