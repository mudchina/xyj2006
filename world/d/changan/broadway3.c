// Room: /changan/broadway3.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "大官道");
  set ("long", @LONG

这是一条宽阔笔直的官道，足可容得下十马并驰。往南通向
南部沿海，往北则直达大唐国都长安城。西面有一条青石路，
想来是通往西部边陲。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"wroad1",
  "south" : __DIR__"broadway4",
  "north" : __DIR__"nanyue",
]));
  set("outdoors", 1);

  set("objects", ([ "/d/obj/weapon/throwing/shi.c" : 1, ]));
  setup();
}






