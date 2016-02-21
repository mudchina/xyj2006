// Room: /d/jjf/sw_garden.c

inherit ROOM;

void create()
{
	set("short", "花园");
	set("long", @LONG
一个小花园，虽然比不上富豪大院里的万紫千红，但也布置得
精致可人。秦府里显然不乏高雅之士。春天里桃花盛开，夏日池塘
里荷花田田，秋天里菊花争艳，冬天则是一片香雪海。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"nw_garden",
  "east" : __DIR__"se_garden",
  "southwest" : __DIR__"stone_road2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
