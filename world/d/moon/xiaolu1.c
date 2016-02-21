//Cracked by Roath
// Room: /moon/xiaolu1.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "崎岖小路");
  set ("long", @LONG

小路异常难行。时而盘上高山，时而跨过深谷。一路上人烟稀少，只有一
些被你惊起的飞禽走兽。
LONG);

  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"kunlun",
  "southeast" : __DIR__"xiaolu2",
]));

  set("objects", ([ /* sizeof() == 2 */
  "/d/xueshan/npc/xiaozuanfeng" : 1,
]));

  setup();
}






