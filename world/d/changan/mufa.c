// Room: /changan/mufa.c

inherit ROOM;

void create ()
{
  set ("short", "海中孤筏");
  set ("long", @LONG

孤筏在海中漂流，四周是白茫茫的一片汪洋。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"aolaiws.c",
]));
set("zuo_trigger", 0);
  set("outdoors", 1);

  setup();
}
