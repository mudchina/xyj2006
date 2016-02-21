//Cracked by Roath
// Room: /d/nanhai/road1
inherit ROOM;

void create ()
{
  set ("short", "小路");
  set ("long", @LONG

这是一条通往后山的小路。
LONG);

  set("outdoors", "/d/nanhai");
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"guangchang",
  "northdown" : __DIR__"road22",
]));

  setup();
}
