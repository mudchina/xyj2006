inherit ROOM;

void create ()
{
  set ("short", "小路");
  set ("long", @LONG
    四周是一片茂密的树林，不时传出几声猛兽的叫声。
只有林中一条小路不知通向何处。
LONG);

  set("outdoors", 2);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"xiaolu2",
  "east" : __DIR__"yaxia",
]));

  setup();
}
