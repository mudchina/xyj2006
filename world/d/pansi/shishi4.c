// shishi4.c
// by shilling 97.2

inherit ROOM;

void create()
{
	set("short", "地下石室");
	set("long", @LONG
这是一个地下的秘密石室，四面可以感觉得到的只有强烈的杀气，以及
处身地底的一些难闻的气味。在微弱的灯光下，你竟然看到有个人站着那里。
继续往下好象还有路。
LONG );
	set("exits", ([
		"up" : __DIR__"fangjian2",
		"down" : __DIR__"shishi5",
	]));
	setup();
}

