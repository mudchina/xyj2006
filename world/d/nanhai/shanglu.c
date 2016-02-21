//Cracked by Roath
// Room: /d/nanhai/shanglu
inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

蜿蜒曲折的山路，北上就是普陀山的山门。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shanglu2",
  "northup" : __DIR__"gate",
]));
  set("outdoors", "/d/nanhai");

  setup();
}
