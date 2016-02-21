//Cracked by Roath
// Room: /d/nanhai/shanglu2
inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

蜿蜒曲折的山路，西边通往海边。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"tingjing",
  "northup" : __DIR__"shanglu",
]));
  set("outdoors", "/d/nanhai");

  setup();
}
