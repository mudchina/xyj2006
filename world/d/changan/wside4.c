// Room: /changan/wside4.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "泾水之滨");
  set ("long", @LONG

泾水东去，绿杨城郭。漫步于此，你不由得心旷神怡，长长
地吸了一口气。而微风中一股清新气息，不知由何处飘来。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wside5",
  "east" : __DIR__"wside3",
]));
  set("outdoors", 1);

  setup();
}






