// Room: /u/hkgroup/cottage
inherit ROOM;

void create ()
{
  set ("short", "天然");
  set ("long", @LONG

　　　　新绿涨添□葛处，好云香护采芥人。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"village",
]));
//  set("objects", ([
//           __DIR__"npc/niu": 1,
//]));

  setup();
}
