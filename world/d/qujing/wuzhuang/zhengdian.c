//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "正殿");
	set ("long", @LONG

这是五庄观的正殿，宽敞素雅。四周有几扇木窗，都是上明下暗
的雕花格子。北面正中靠壁挂着五彩装成的“天地”二字，下设
一张朱红雕漆的香几，几上有一副黄金炉瓶，炉边摆着几束香。
正殿东西各有一座偏殿。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"out" : __DIR__"guangchang",
		"east" : __DIR__"epiandian",
		"west" : __DIR__"wpiandian",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		__DIR__"npc/qingfeng" : 1,
		__DIR__"npc/caoguojiu" : 1,
	]));

	set("valid_startroom", 1);
//	set("outdoors", "wuzhuang");

	setup();
}

