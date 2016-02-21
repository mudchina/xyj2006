// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "宅院");
  set ("long", @LONG

方方正正的宅院，石矮墙木栅门，院子里种了一些香草葡萄，
中间有一口滚碾石磨，上面晒着一些粮食。几只鸟儿从天上飞
下来偷吃粮食。

LONG);

  set("exits", ([
        "north"    : __DIR__"zhai1",
        "west"    : __DIR__"jie7",
      ]));
  set("objects", ([
        __DIR__"obj/elong"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

