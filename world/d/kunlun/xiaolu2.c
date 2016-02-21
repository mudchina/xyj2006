inherit ROOM;

void create ()
{
  set ("short", "小路");
  set ("long", @LONG
    小路一直延伸上去，几乎看不到路的尽头。
LONG);

  set("outdoors", 2);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"xiaolu3",
  "east" : __DIR__"xiaolu1",
]));

  setup();
}
