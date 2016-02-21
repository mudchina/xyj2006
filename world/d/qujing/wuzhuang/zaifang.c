//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "斋房");
	set ("long", @LONG

斋房分为两半，北边有斋厨，炉上的大锅里热气腾腾。南边摆
了一张木桌，几条木凳，几位道长正在进斋。靠墙的架子上放
着各类瓜果，都是观中自己种的。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"east" : __DIR__"eastway5",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));


//	set("outdoors", "wuzhuang");

	setup();
}
