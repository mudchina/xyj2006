//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "讲经堂");
	set ("long", @LONG

经堂是平时镇元大仙与观中道士讲经时而用，堂上有一宝座，座
前放有三四十个锦面软垫。此外堂中没有其它摆设，是镇元大仙
为妨分神特意而为。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"wpiandian",
		"eastup": __DIR__"yanzhen",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		__DIR__"npc/zhangmen" : 1,
	]));


//	set("outdoors", "wuzhuang");

	setup();
	call_other("/obj/board/jiangjing_b", "???");
}
