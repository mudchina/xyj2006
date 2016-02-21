// Room: /u/none/newtoy/ironbridge
inherit ROOM;

void create ()
{
  set ("short", "铁板桥");
  set ("long", @LONG

　　瀑布泉中原来是座铁板桥。
　　桥下之水，冲贯于石窍之间，倒挂流出去，遮闭了桥门。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "down" : __DIR__"dragonpalace",
  "out" : __DIR__"fall",
  "cave" : __DIR__"cave",
]));

  setup();
}
