// Room: /changan/sbridge.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "泾水桥南");
  set ("long", @LONG

已经到了泾水桥南。往南是一条宽阔笔直的官道，足可容得
下十马并驰。往北则见宫城巍峨，正是大唐国都长安城。长
安乃历代建都之所，素有“三州花似锦，八水绕城流”之称。
LONG);

  set("objects", ([ /* sizeof() == 1 */
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"broadway1",
  "north" : __DIR__"bridge",
]));

  setup();
}






