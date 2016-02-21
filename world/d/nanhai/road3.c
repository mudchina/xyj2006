//Cracked by Roath
// Room: /d/nanhai/road1
inherit ROOM;

void create ()
{
  set ("short", "小路");
  set ("long", @LONG

这是一条通往后山的小路，道路至此越来越不好走，分叉也越来越多了。
LONG);

  set("objects", ([ /* sizeof() == 1 */
]));
  set("outdoors", "/d/nanhai");
  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"road4",
  "south" : __DIR__"road2",
]));

  setup();
}
