//Cracked by Roath
// Room: /moon/xiaolu2.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "崎岖小路");
  set ("long", @LONG

小路异常难行。时而盘上高山，时而跨过深谷。一路上人烟
稀少，只有一些被你惊起的飞禽走兽。
LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/d/ourhome/npc/dog" : 1,
  "/d/lingtai/npc/youngwolf" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"xiaolu3",
  "northwest" : __DIR__"xiaolu1",
]));

  setup();
}






