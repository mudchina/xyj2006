// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "仵官殿");
  set ("long", @LONG

这里便是阴间地府十王之仵官王的宫殿．平时若是无事，仵官
王便会在殿上处理一些杂务．殿上一张大木桌，桌上堆了一些
文告之类，一个小青铜炉吐着淡淡的的青烟，一个青衣童子侍
立于后．
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"walk3",
]));
  set("hell", 1);
  set("out_doors", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/chuguanwang" : 1,
  __DIR__"npc/tong" : 1,
]));

  setup();
}
