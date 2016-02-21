// Room: /d/jjf/side_keting.c

inherit ROOM;

void create ()
{
  set ("short", "偏厅");
  set ("long", @LONG
偏厅布置的颇为优雅，丝毫没有正厅上的严肃气氛。一张红木
大桌边上有个书柜，柜里摆了各式各样的书。墙上挂着几幅字画。
看来客人少时，这里又可以当书房用。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"keting",
]));

  setup();
}
