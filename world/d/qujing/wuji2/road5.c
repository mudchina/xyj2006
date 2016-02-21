// Room: /u/mimi/zhuziguo/road5  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

路两边千株老柏，带雨半空青冉冉；万节修篁，含烟一壑色苍苍。北
边林中隐隐有钟声传来，好象是一座寺庙。
LONG);

  set("outdoors", __DIR__"");
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shanji" : 1,
]));
  set("exits", ([ /* sizeof() == 4 */
  "southup" : __DIR__"hilltop",
  "east" : __DIR__"road4",
  "north" : __DIR__"temple.c",
  "westdown" : __DIR__"road6",
]));

  setup();
}

