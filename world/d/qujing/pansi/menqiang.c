// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "门墙");
  set ("long", @LONG

山岭上斜斜地竖立一座石头门墙，墙上骑着七彩墙头小草。门
前遍地野花香艳艳，满旁兰蕙密森森。中间是一竹檐门洞，有
一小径向下通去。

LONG);

  set("exits", ([
        "west"    : __DIR__"qiaolin7",
        "southdown"    : __DIR__"zhuogou",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

