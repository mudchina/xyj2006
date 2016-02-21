// Room: /d/qujing/wudidong/dong1.c

inherit ROOM;

void create ()
{
  set ("short", "洞门");
  set ("long", @LONG

下落半晌，方始着地。落脚处甚是窄狭，黑沉沉阴森森也看不甚清楚，
只见拱门边上立着块大碑(shibei)，笔迹却颇为娟秀。门那边隐隐传来
阵阵笑语，又似有日光透入。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"dong2",
  "up" : __DIR__"dong",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "shibei" : "
\t\t\t陷
\t\t\t空
\t\t\t山
\t\t\t无
\t\t\t底
\t\t\t洞
 
",
]));
  set("outdoors", 0);

  setup();
}
