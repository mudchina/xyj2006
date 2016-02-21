// Room: /u/mimi/zhuziguo/piandian.c  snowcat moved to /d/qujing/wuji

inherit ROOM;

void create()
{
  set("short", "前殿");
  set("long", @LONG

只见两边红漆栏杆里面高坐这一对金刚，装塑的威依恶丑：一个
铁面钢髯，一个燥眉圆眼，金甲连环光灿烂，明盔绣带映飘风。

LONG);
  set("no_clean_up", 0);
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
    "out" : __DIR__"temple",
    "north" : __DIR__"zheng",
  ]));

  setup();
  replace_program(ROOM);
}
