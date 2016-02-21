// Room: /d/nanhai/xiaol2.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG

这是一条通往后山的小路。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"xiaol",
  "north" : __DIR__"xiaol3",
]));
	set("asdlk", "asdf");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
