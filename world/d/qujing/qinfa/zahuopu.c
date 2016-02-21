// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "杂货铺");
  set ("long", @LONG

铺面不大不小，地上摆着零零散散的日用品。低低的天花板上
悬下一些挂钩吊篮，篮子里面也放着一些待出售的货物。南面
的铺门大开，通向五鼓楼的广场。

LONG);

  set("exits", ([
        "south"    : __DIR__"wugu",
      ]));
  set("objects", ([
        __DIR__"npc/qian"    : 1,
      ]));
  setup();
}

