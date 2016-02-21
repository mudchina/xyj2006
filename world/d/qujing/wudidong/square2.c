// Room: /d/qujing/wudidong/square2.c

inherit ROOM;

void create()
{
	set("short", "甬道");
	set("long", @LONG

甬道里潮湿阴暗，两壁挂着手臂粗细的牛油蜡烛，在阵阵阴风吹动下
忽明忽暗。前面不远处有两个洞口，不知通向哪里。远处依稀可以看
到洞口的亮光。你不由的加快了脚步。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"houdong",
  "west" : __DIR__"guanjia.c",
  "south" : __DIR__"dong2",
  "east" : __DIR__"weaponry.c",
]));
	set("indoors", "1");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
