// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "密洞");
  set ("long", @LONG

这里光线极为微弱，你勉强地看见洞里隐隐约约的一些东西，
却又看得不是十分清楚。你不禁伸出手来扶着洞壁，小心地摸
索着行动。

LONG);

  set("exits", ([
        "down" : __DIR__"houdong",
      ]));
  set ("sleep_room",1);

  setup();
}



