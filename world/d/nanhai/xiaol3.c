// Room: /d/nanhai/xiaol3.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG

这是一条通往后山的小路，道路至此越来越不好走，分叉也越来越多了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"xiaol2",
  "northeast" : __DIR__"road4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
