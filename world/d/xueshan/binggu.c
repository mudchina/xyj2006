//sgzl
inherit ROOM;

void create ()
{
	set ("short", "雪山从中");
	set ("long", @LONG

你信步到了一处高山丛中。但见山势险峻，抬头望不到山顶。
待向上攀援时，天候骤寒，铅云低压，北风渐紧，接著天空
竟飘下一片片的雪花。
LONG);


	set("exits", 
	([ //sizeof() == 4
		"northup" : __DIR__"xuelu1",
	]));
	
	set("objects", 
	([ //sizeof() == 1
	]));


	set("outdoors", "xueshan");

	setup();
}



