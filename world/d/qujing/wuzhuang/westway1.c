//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "西小廊");
	set ("long", @LONG

这是大殿西厢的一条长廊，向北连到后院。小廊上是木板铺地，
打扫的极为干净，走在上面发出吱吱的响声。走廊两面的木格内
雕着一些山水人物。南面有一座高台。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"southup" : __DIR__"wangxian",
		"north" : __DIR__"westway2",
		"east" : __DIR__"guangchang",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));


//	set("outdoors", "wuzhuang");

	setup();
}
