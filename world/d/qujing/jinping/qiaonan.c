// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "桥南");
  set ("long", @LONG

桥南临街，往北可见桥上张灯结彩，一阵阵酥香油味从桥那边
顺风飘过来。河水从西而来自桥下潺潺流过，向东流去。往南
便是城里。

LONG);

  set("exits", ([
        "north"   : __DIR__"qiao",
        "south"   : __DIR__"xiaojie2",
      ]));
  set("outdoors", __DIR__);

  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive (who) &&
      dir == "north")
    return 0;

  return ::valid_leave (who, dir);
}


