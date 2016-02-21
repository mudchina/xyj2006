// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "门楼");
  set ("long", @LONG

一座门楼南北向开设，楼下有一通行马车的门洞。门楼两边东
西向建起了高高的石墙，门楼上有旌旗飘扬，墙上有一巨匾：
玉华县。

LONG);

  set("exits", ([
        "north"   : __DIR__"xiaolu11",
        "south"   : __DIR__"xiaojie1",
        "west"   : __DIR__"shi2",
        "east"   : __DIR__"shi3",
      ]));
  set("objects", ([
        __DIR__"npc/bing"  : 4,
      ]));
  set("outdoors", __DIR__);

  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive(who) &&
      dir == "north")
    return 0;

  return ::valid_leave(who,dir);
}



