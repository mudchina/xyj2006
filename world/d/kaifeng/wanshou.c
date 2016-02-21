//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "万寿宫门");
  set ("long", @LONG

万寿宫门向南大开，宫门是楠木打成，边上镶有铜条。门檐上有五彩
凤一对栩栩如生展翅欲飞。门边上放着一个大大的雕玉箱，由两名宫
卫守护。

LONG);

  set("exits", ([
        "southdown" : __DIR__"guting1",
        "north" : __DIR__"sanxin",
      ]));
  set("objects", ([
        __DIR__"npc/gongwei" :  2,
        __DIR__"obj/diaoyu" :  1,
      ]));

  setup();
}

int valid_leave (object who, string dir)
{
  if (dir != "north")
    return ::valid_leave (who, dir);

  if (! who->query_temp("kaifeng_donate_silver"))
    return notify_fail ("请捐(donate)一两银子到雕玉箱里。欢迎多捐：）\n");

  return ::valid_leave (who, dir);
}

