// Room: /u/hkgroup/bridge
inherit ROOM;

void create ()
{
  set ("short", "沁芳闸");
  set ("long", @LONG

　　这桥便通外河之闸，引泉而入者。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"main",
  "north" : __DIR__"yard3",
  "down" : __DIR__"cool",
]));
  set("outdoors", "/u/hkgroup");

  setup();
}
