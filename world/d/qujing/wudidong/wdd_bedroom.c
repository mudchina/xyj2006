// Room: /d/qujing/wudidong/wdd_bedroom.c

inherit ROOM;

void create()
{
	set("short", "卧房");
	set("long", @LONG

这里是无底洞的卧房，四面地上睡着几个老鼠精。洞中散发着一股令
人作呕的臊气，不知道哪个小妖带东西进来吃了。
LONG
	);
	set("sleep_room", "1");
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dong2",
]));
	set("no_clean_up", 0);
	set("no_magic", "1");
	set("no_fight", "1");

	setup();
	replace_program(ROOM);
}
