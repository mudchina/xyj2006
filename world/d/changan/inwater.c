inherit ROOM;

void create ()
{
  set ("short", "泾水");
  set ("long", @LONG

周围是齐腰深的河水，从四周的景色来看大概是在长安城南，泾
水之中．流水清澈见底，远处还有几条小船．
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"eside1",
]));
  set("objects", ([ /* sizeof() == 2 */
  "/d/sea/npc/long7.c" : 1,
]));

  setup();
}
