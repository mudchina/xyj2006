// Room: /d/4world/shiwu.c
inherit ROOM;

void create()
{
  set ("short", "石屋");
  set ("long", @LONG

屋内光线暗淡，隐隐看到四周墙上画着些八卦之类的图形。家
里的主人是城内有名的阿七婆，凡有求魂告祷，看风水，算黄
道吉日的事总少不了她。也听说她会算命，不知灵不灵。
LONG);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/aqi" : 1,
]));

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"west2",
]));
  setup();
}
