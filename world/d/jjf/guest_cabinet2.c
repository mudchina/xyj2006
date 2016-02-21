// Room: /d/jjf/guest_cabinet2.c

inherit ROOM;

void create ()
{
  set ("short", "西厢二楼");
  set ("long", @LONG

这间卧房颇为阔朗，窗口一张紫檀木大案，文房四宝齐备，又有一盆
小小盆景，绿意盎然。转过屏风，迎面只见一幅写意山水，笔势纵横。
旁边就是卧榻，垂着水红纱帐，绣了些花鸟。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/luocheng.c" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"guest_shufang",
  "down" : __DIR__"guest_cabinet",
]));
  set("if_bed", 1);
  set("sleep_room", 1);

  setup();
}
