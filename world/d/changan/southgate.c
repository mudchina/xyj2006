// Room: /changan/southgate.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "南城门");
  set ("long", @LONG

大门紧闭。门上有一张安民告示，上书：
长安南门暂闭数日。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"nbridge",
]));

  setup();
}






