// Room: /d/4world/schoolrest.c
inherit ROOM;

void create()
{
  set ("short", "客房");
  set ("long", @LONG

这里是一间布置得相当雅致的厢房，从窗子可以看到北边的天井跟
庭园中各式各样的奇花异草。厢房里有几张大木床，是来客住的，
北边就回到天井。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"schoolin",
]));
  set("no_fight", 1);
        set("sleep_room",1);
        set("if_bed",1);

  setup();
}
