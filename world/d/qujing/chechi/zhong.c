// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/zhong.c

inherit ROOM;

void create ()
{
  set ("short", "中场");
  set ("long", @LONG

中场在皇宫的南面，用大块石头铺成，向北是皇宫的入口，飘着
车迟国的旌旗。每天钟鸣时分，有士兵出场演武操练。东面是东
场，西面是西场。

LONG);

  set("exits", ([
        "west"         : __DIR__"xi",
        "north"        : __DIR__"gongmen",
        "east"         : __DIR__"dong",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

int valid_leave (object who, string dir)
{
  if ((! interactive(who)) &&
       dir == "north" &&
       who->query("people")=="people")
    return 0;
  return 1;
}
