// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "泗鬼门");
  set ("long", @LONG

泗鬼门外灰蒙蒙的一片，周围一下什么也看不清了，却能听道一些
急匆匆的脚步声擦身而过。隐约脚下有条道路，也不知是通向什么
地方。北边一座大山，山后隐隐看到火光。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"huangwai",
  "west" : __DIR__"new-walk3",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/shentu" : 1,
  __DIR__"npc/yulei" : 1,
]));




  set("hell", 1);

  setup();
}

