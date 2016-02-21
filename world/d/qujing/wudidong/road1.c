// Room: /d/qujing/wudidong/road1.c

inherit ROOM;

void create()
{
	set("short", "村中小路");
	set("long", @LONG

这是一条村中石子小路。村里农民都起早摸黑地下地去了，路上一个
大人也没有，只有几个小童在溪边捉鱼嬉戏。路边柳条拂地，时见野
花，几只小鸡小鸭踱来踱去。一条野狗摇着尾巴跑了过来，闻了闻，
又跑了开去。
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/dog" : 1,
  __DIR__"npc/kid" : 2,
]));
	set("outdoors", "1");
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"temple-qiandian",
  "north" : __DIR__"dibaohouse",
  "west" : __DIR__"road2",
  "east" : __DIR__"entrance",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
