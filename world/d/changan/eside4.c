// Room: /changan/eside4.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "泾水之滨");
  set ("long", @LONG

泾水东去，绿杨城郭。漫步于此，你不由得心旷神怡，长长
地吸了一口气。而微风中一股清新气息，不知由何处飘来。
LONG);

  set("exits", ([ /* sizeof() == 3 */
//  "south" : "/d/erlang/guanjiang",
  "west" : __DIR__"eside3",
  "east" : __DIR__"eside5",
]));
  set("outdoors", 1);

  setup();
}






