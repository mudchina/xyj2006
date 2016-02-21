// Room: /d/qujing/wudidong/well.c

inherit ROOM;

void create()
{
	set("short", "井底");
	set("long", @LONG

拨开井水一直游到底，你发现井底其实是干的。东边有一道石缝，里
面似乎有两盏红灯，也许有什么神圣住在这里？
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"houyuan",
  "east" : __DIR__"dragon-room",
]));
	set("no_clean_up", 0);
	set("outdoors", 1);

	setup();
	replace_program(ROOM);
}
