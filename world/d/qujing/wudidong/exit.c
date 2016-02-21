// Room: /d/qujing/wudidong/exit.c

inherit ROOM;

void create()
{
	set("short", "小村口");
	set("long", @LONG

举头向东望去，只见一带泥墙，几丛青篱，一条潺潺的小溪围着十几
间矮矮的茅屋，正是张家村。满山遍野的都是菜田，蜜蜂在金黄的油
菜花间飞舞。极目远望，南面有座高山，几朵白云留连不去。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"road3",
  "west" : "/d/qujing/qinfa/dalu3",
]));
	set("no_clean_up", 0);
	set("outdoors", "1");

	setup();
	replace_program(ROOM);
}
