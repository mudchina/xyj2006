// Room: /d/jjf/sleep
inherit ROOM;

void create ()
{
  set ("short", "模糊中");
  set ("long", @LONG

模模糊糊中，你来到一个陌生的地方。这里四面都是云彩，但你看不到天
空。脚下都是雾，但你看不到地面。也不知这里是真，是幻。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"sleep-2",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/pangu.c" : 1,
]));
  set("light_up", 1);
  set("valid_startroom", 1);

  setup();
}
