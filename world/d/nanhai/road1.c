//Cracked by Roath
// Room: /d/nanhai/road1
inherit ROOM;

void create ()
{
  set ("short", "小路");
  set ("long", @LONG

这是一条通往后山的小路。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xingzhe.c" : 1,
]));
  set("outdoors", "/d/nanhai");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"guangchang",
  "northdown" : __DIR__"road2",
]));

  setup();
}
