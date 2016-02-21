// Room: /d/huanggong/guangchang.c
inherit ROOM;

void create ()
{
  set ("short", "朝天场");
  set ("long", @LONG

皇宫前的大广场，长宽俱有二十余长。地下乃是从终南山运来
的青砖铺就，与宫殿的红墙黄瓦交相辉映。有重大事件或节日
时皇帝便在此会见群臣。北边是一排排的宫圉楼阁，东西是群
臣上朝前休息的朝房。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"baihu.c",
  "south" : __DIR__"damen",
  "east" : __DIR__"qinglong.c",
  "northup" : __DIR__"baiyujie.c",
]));
  set("outdoors", "/d/huanggong");

  setup();
}
