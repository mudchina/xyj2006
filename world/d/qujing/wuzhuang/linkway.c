//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "青砖道");
	set ("long", @LONG

细长的青砖道从山门连向宝殿。道上俱是一色青砖，摆法中似有
太极之意，八卦之象。道左是竹林一片，密密匝匝看之不透，右
是松海一片，但闻松涛阵阵不绝。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"secondgate",
		"northup" : __DIR__"guangchang",
//		"east" : __DIR__"song1",
//		"west" : __DIR__"zhu1",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));


	set("outdoors", "wuzhuang");

	setup();
}
