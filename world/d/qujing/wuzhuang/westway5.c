//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "西小廊");
	set ("long", @LONG

这是大殿西厢的一条长廊，向北连到后院。小廊上是木板铺地，
打扫的极为干净，走在上面发出吱吱的响声。走廊两面的木格内
雕着一些山水人物。东面是观中弟子的睡房。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"westway4",
		"north" : __DIR__"westway6",
		"east" : __DIR__"sleep",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));


//	set("outdoors", "wuzhuang");

	setup();
}
