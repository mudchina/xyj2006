// Room: /d/qujing/wudidong/firemount-wudidong3
inherit ROOM;

void create ()
{
  set ("short", "取经路");
  set ("long", @LONG

西边地平线上可以看到一个小村庄的轮廓，路两边的稻田里，人们正
在耕作。看着田里的水牛，你不由想找个人家小憩一宿，聊解旅途的
疲惫。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"firemount-wudidong2",
  "southwest" : __DIR__"entrance",
]));
  set("outdoors", "/d/qujing/wudidong");

  setup();
}
