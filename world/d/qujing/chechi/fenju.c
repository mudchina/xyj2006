//Cracked by Roath
// Room: /d/qujing/chechi/fenju.c

inherit ROOM;

void create()
{
	set("short", "振远镖局");
	set("long", @LONG

振远镖局的创始人是老英雄萧振远。萧老英雄年事已高，早已不过问
江湖是非了。现在镖局的对外事务都由萧振远的次子萧升主理。大院
左右是厢房，靠墙挂着一些兵器。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jieshi2",
]));
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  "/d/city/npc/biaotou" : 1,
]));

	setup();
	replace_program(ROOM);
}
