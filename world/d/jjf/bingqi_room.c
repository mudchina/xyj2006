// Room: /d/jjf/bingqi_room.c

inherit ROOM;

void create ()
{
  set ("short", "干戈隅");
  set ("long", @LONG
进门后，右手墙壁上挂了一幅肖像，两旁供着两柄长枪。一个
小童刚刚打扫过房间，屋里一尘不染。尤其是两柄枪，被擦得光可
鉴人。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"main_cabinet",
]));

  setup();
}
