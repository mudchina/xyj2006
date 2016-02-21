// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "秦广殿");
  set ("long", @LONG

这里便是阴间地府十王之秦广王的宫殿．平时若是无事，秦广
王便会在殿上处理一些杂务．殿上一张大木桌，桌上堆了一些
文告之类，一个小青铜炉吐着淡淡的的青烟，一个青衣童子侍
立于后．
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"walk5",
]));
  set("hell", 1);
  set("out_doors", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/qinguangwang" : 1,
  __DIR__"npc/tong" : 1,
]));

  setup();
}
