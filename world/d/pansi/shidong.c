// shidong.c
// by shilling 97.2

inherit ROOM;

void create()
{
	set("short", "石洞");
	set("long", @LONG
这是一个比较大的圆形石洞，光亮从左边的窗口透了过来，细看那窗的
时候，发现原来是镶在石壁上的一块大水晶透过水晶向外看去，只见鱼虾水
族来回游动，原来你竟处身水底之中！
LONG );
	set("exits", ([
		"south" : __DIR__"damen",
		"north" : __DIR__"shishi3",
		"east" : __DIR__"shiji2",
		"west" : __DIR__"shiji1",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
