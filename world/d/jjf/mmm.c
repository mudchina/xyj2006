// Room: /d/jjf/mishi.c

inherit ROOM;

void create()
{
	set("short", "小屋");
	set("long", @LONG

看起来小屋很久没有人来了，到处都是灰尘．正前方有一张
大木桌，桌上供着一个牌位，两边烛台上的香烛早已燃尽．
LONG
	);
	set("item_desc", ([ /* sizeof() == 2 */
  "table" : "桌上都是灰，什么也看不清．
",
  "牌位" : "牌位上写着：表弟罗成之位．
",
]));
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"front_yard2",
]));
	set("objects", ([ /* sizeof() == 1 */
  "/d/obj/book/spearbook" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
