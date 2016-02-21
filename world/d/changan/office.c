// Room: /u/wuliao/housingoffice
inherit ROOM;

void create ()
{
  set ("short", "房管所");
  set ("long", @LONG
泾水河边的居民逐渐增多，因此特别在此设立房管所，临时由
一个不知名的老头负责。
LONG);


	set("no_fight", 1);
	set("no_magic", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"officer" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"ph",
]));

  setup();
}
