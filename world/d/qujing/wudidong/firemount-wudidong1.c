// Room: /d/qujing/firemount/firemount-wudidong1
inherit ROOM;

void create ()
{
  set ("short", "取经路");
  set ("long", @LONG

离开了比丘国，你又踏上了西行之路。面前是一片一望无际的平野，
视野内不见一道炊烟。又不知要度过多少个无人伴随的旅途之夜，又
不知要独自面对多少毒虫野兽，妖魔鬼怪了。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"firemount-wudidong2",
  "southeast" : "/d/qujing/biqiu/lin3",
]));
  set("outdoors", "/d/qujing/wudidong");

  setup();
}
