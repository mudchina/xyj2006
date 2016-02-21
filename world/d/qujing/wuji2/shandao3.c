// snowcat moved to /d/qujing/wuji

inherit ROOM;

void create ()
{
  set ("short", "山道");
  set ("long", @LONG

山道崎岖不平，沿着山势上下左右盘绕，地形十分险恶。群峦环绕，难辨
东西南北。大风吹来，有点令人寒颤。
LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"guankou",
  "northeast" : __DIR__"street1",
]));

  setup();
}

