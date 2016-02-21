// Room: /d/qujing/wudidong/firemount-wudidong2
inherit ROOM;

void create ()
{
  set ("short", "小山头");
  set ("long", @LONG

爬上一个小山头，西边已能看到片片碧绿的稻田。而回首东望，火焰
山已经只剩一个模糊的轮廓了。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"firemount-wudidong3",
  "eastdown" : __DIR__"firemount-wudidong1",
]));
  set("outdoors", "/d/qujing/wudidong");

  setup();
}
