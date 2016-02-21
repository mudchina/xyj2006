// created by snowcat.c 4/4/1997
// room: /d/nuerguo/xiaolu3.c

inherit ROOM;

void create ()
{
  set ("short", "小路");
  set ("long", @LONG

这是一条又细又长的山间小径，一会儿高，一会儿低。路的
两边是不知名的野花野草。你快速地走着，觉得山势有一点
陡峭。

LONG);

  set("exits", ([
    "southup"   : __DIR__"xiaolu2",
    "northup"   : __DIR__"xiaolu4",
  ]));
  set("objects", ([
"/d/sea/npc/beast/beast7":1,
]));

  set("outdoors", __DIR__"");

  setup();
}






