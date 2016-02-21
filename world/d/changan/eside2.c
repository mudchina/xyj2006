// Room: /changan/eside2.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "泾水之滨");
  set ("long", @LONG

泾水东去，绿杨城郭。漫步于此，你不由得心旷神怡，长长
地吸了一口气。而微风中一股清新气息，不知由何处飘来。
北面靠城墙有一座小土丘。
LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/qiaofu" : 1,
  __DIR__"npc/fisher" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"eside1",
  "east" : __DIR__"eside3",
  "northup" : __DIR__"xiaoqiu",
]));

  setup();
}






