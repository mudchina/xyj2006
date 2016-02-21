// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "岭道");
  set ("long", @LONG

高山峻岭曲折盘绕，林原莽莽荒道坎坷。你走在一条荒芜的岭
道上，时而有峭壁直立时而又有涧水长流。正是野润烟光淡，
石翡山色翠。

LONG);

  set("exits", ([
        "northwest"    : __DIR__"ling1",
        "eastup"    : __DIR__"ling4",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

