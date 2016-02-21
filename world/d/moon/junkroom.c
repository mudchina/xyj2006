//Cracked by Roath
inherit ROOM;

void create ()
{
  set ("short", "储藏室");
  set ("long", @LONG

一间不大的房间,放满了练舞的道具和一些日常的用具。
LONG);

  set("objects", ([ /* sizeof() == 4 */
  __DIR__"obj/daoyaochu" : 1,
  __DIR__"obj/bigaxe" : 2,
  "/d/obj/weapon/whip/wuchou":2,
  __DIR__"obj/snow_sword" : 2,
]));
  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"courtyard.c",
  "south" : __DIR__"wulang.c",
]));

  setup();
}
