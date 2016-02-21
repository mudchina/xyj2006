// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "曩门");
  set ("long", @LONG

一座城门拔地而起，上面有一青铜大匾，书写着“比丘国”几
个大字。杨木城门大开，门上镶着无数条五寸宽铜板，钉满尖
头六刃铜钉。

LONG);

  set("exits", ([
        "north"    : __DIR__"jie12",
        "southwest"    : __DIR__"lin5",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive (who) &&
      dir == "south")
    return 0;
  return 1;
}
