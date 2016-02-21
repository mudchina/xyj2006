//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "殿前广场");
	set ("long", @LONG

这里是宝殿之前的一个广场。从此纵看宝殿，气象雄浑，威势不
俗。檐上有各种明兽祥云的浮雕，向南的窗户乃是太极之形，中
部镂空镶以五彩琉璃。场上铺的均是四方青石，向南可看到山门
前的往来，东西有小廊通往后殿。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"southdown" : __DIR__"linkway",
		"enter" : __DIR__"zhengdian",
		"east" : __DIR__"eastway1",
		"west" : __DIR__"westway1",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		__DIR__"npc/tieguaili" : 1,
	]));


	set("outdoors", "wuzhuang");

	setup();
}
