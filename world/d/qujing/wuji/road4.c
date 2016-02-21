// Room: /moon/road.c  snowcat moved to /d/qujing/wuji

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

路两边千株老柏，带雨半空青冉冉；万节修篁，含烟一壑色苍苍。林
中隐隐有钟声传来，好象是一座寺庙。
LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"road3",
  "northwest" : __DIR__"temple",
  "west" : __DIR__"road5.c",
]));

  setup();
}






