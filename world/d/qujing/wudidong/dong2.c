// Room: /d/qujing/wudidong/dong2.c

inherit ROOM;

void create()
{
	set("short", "前洞");
	set("long", @LONG

好一个福地洞天！一座二滴水的门楼，团团都是松林。亭台楼阁，
门垂翠柏，宅近青山。前洞住的尽是小妖，各自忙忙奔走。西面
便是厨房，传出阵阵香气，不时有人出入。前面有条黑乎乎的甬
道，直奔后洞而去。
LONG
	);
	set("outdoors", 0);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"wdd_bedroom",
  "south" : __DIR__"dong1",
  "west" : __DIR__"kitchen",
  "north" : __DIR__"square2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
