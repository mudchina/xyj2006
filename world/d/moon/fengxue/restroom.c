//restroom.c

inherit ROOM;

void create ()
{
  set ("short", "枫雪宫休息室");
  set ("long", @LONG

这是供枫雪天地会的成员或客人休息的地方。靠墙放着一张
简陋的木床。
LONG);

  set("sleep_room", 1);
  set("if_bed", 1);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"living",
]));

  setup();
}

