// Room: /u/hkgroup/dream.c

inherit ROOM;

void create ()
{
  set ("short", "醉梦亭");
  set ("long", @LONG

穿林海，跨雪原，气冲霄汉。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"path1",
]));
  set("light_up", 1);
  set("no_fight", 1);

  setup();
}
