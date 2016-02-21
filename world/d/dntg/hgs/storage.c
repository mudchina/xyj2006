// Room: /d/4world/storage.c
inherit ROOM;

void create ()
{
  set ("short", "储藏室");
  set ("long", @LONG

这是间堆满杂物的储藏室，几个架子上货物都是按类排放。有些棉
被衣物，也有些刀枪棍棒。屋里倒是很干净，象是有人经常打扫。
西边是练武场。
LONG);
  set("objects", ([ /* sizeof() == 1 */
  "/d/obj/weapon/hammer/stonehammer" : 1,
]));

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"school2",
]));

  setup();
}
