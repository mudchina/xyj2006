inherit ROOM;

void create ()
{
  set ("short", "荒郊草野");
  set ("long", @LONG

周围一下什么也看不清了，灰蒙蒙的一片。却能听道一些急匆
匆的脚步声擦身而过。隐约脚下有条道路，也不知是通向什么
地方。北边一座大山，山后隐隐看到火光。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"huangwai",
  "west" : __DIR__"roomout",
]));
  set("hell", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/niutou" : 1,
  __DIR__"npc/mamian" : 1,
]));

  setup();
}
