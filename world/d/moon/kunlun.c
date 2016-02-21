//Cracked by Roath
// Room: /moon/kunlun.c
//cglaem...12/13/96.

inherit ROOM;

void create ()
{
  set ("short", "昆仑山区");
  set ("long", @LONG

苍茫昆仑，绵延千里。放眼望去，正所谓千里冰封，万里雪飘。西面奇峰
入云，乃是昆仑主峰玉女峰。据说西王母就隐居在玉女峰绝顶处。
LONG);

  set("outdoors", 2);
  set("exits", ([ /* sizeof() == 3 */
  "north" : "/d/xueshan/xueshan1",
  "southeast" : __DIR__"xiaolu1",
  "west" : __DIR__"yunu1",
]));

  setup();
}






