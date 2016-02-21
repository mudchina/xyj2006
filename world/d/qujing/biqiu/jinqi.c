// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "金器店");
  set ("long", @LONG

这是一家专营金器的金器店，在比丘国十分有名。店内各种金
器镶金铜器玲琅满目光彩照人，同时也兼卖其它贵重首饰玉器
如意古董。

LONG);

  set("exits", ([
        "northwest"    : __DIR__"jie9",
      ]));
  set("objects", ([
        __DIR__"npc/lasulusi"    : 1,
      ]));
  setup();
}

