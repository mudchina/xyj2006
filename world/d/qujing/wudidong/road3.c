// Room: /d/qujing/wudidong/road3.c

inherit ROOM;

void create()
{
	set("short", "村中小路");
	set("long", @LONG

北面传来一阵阵的读书声。人说麻雀虽小，五脏俱全，果然不假。就
连这么个小村，都有学堂。你不禁对本地的村民肃然起敬。村里最老
的老张就住在南边。你不由想去拜访拜访，问问本地的风土人情。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"exit",
  "south" : __DIR__"zhanghome",
  "north" : __DIR__"xuetang",
  "east" : __DIR__"road2",
]));
	set("no_clean_up", 0);
	set("outdoors", "1");

	setup();
	replace_program(ROOM);
}
