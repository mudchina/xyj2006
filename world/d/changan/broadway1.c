// Room: /changan/broadway1.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "大官道");
  set ("long", @LONG

这是一条宽阔笔直的官道，足可容得下十马并驰。往南通向
南部沿海，往北则直达大唐国都长安城。西面有一条崎岖小
路，不知通向何处。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"fendui.c",
  //"west" : "/d/moon/xiaolu3",
  "south" : __DIR__"zhongnan",
  "north" : __DIR__"sbridge",
]));
  set("outdoors", 2);

  set("objects", ([ "/d/obj/weapon/throwing/shi.c" : 1, ]));
  setup();
}






