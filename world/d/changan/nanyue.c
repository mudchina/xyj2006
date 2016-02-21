// Room: /changan/nanyue.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "南岳");
  set ("long", @LONG

一路行来，已到衡山地界。衡山古称南岳，雄踞南天，气势磅礴。南以回
雁峰为首，北以岳麓山为足，大小七十二峰逶迤盘绕八百余里。然则此地
自古民风剽悍，盗匪随处横行，在此行走可得小心为是。
LONG);

 set("objects", ([ /* sizeof() == 1 */
   __DIR__"npc/huang" : 1,
]));
set("outdoors", 2);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"broadway2",
  "south" : __DIR__"broadway3",
  "southeast" : "/d/meishan/guanjiang1",
  "northwest" : "/d/southern/emei/guandao3",
]));

  setup();
}






