//Cracked by Roath
// Room: /moon/yunu1.c
//cglaem...12/13/96.

inherit ROOM;

void create ()
{
  set ("short", "玉女峰底");
  set ("long", @LONG

这里是玉女峰底。仰头望去，冰雪的反光刺得你眼都睁不开。眯着眼使劲
看，亦只见头顶不远处白云缭绕，哪里看得清楚。
LONG);

  set("outdoors", 2);
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"kunlun",
  "westup" : __DIR__"yunu2",
   "south" : "/d/kunlun/duanya",
]));

  setup();
}






