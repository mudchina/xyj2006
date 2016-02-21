//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "后殿");
	set ("long", @LONG

后殿亦是宽敞素雅，只是空空荡荡地没放什么东西。再往北就是
五庄观的后院了。东西各有一条小廊通向正殿。北面门外，隐闻
花香鸟语，大概是个花园。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"north" : __DIR__"houyuan",
		"east" : __DIR__"eastway6",
		"west" : __DIR__"westway6",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));


//	set("outdoors", "wuzhuang");

	setup();
}
