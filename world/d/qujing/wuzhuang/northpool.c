//Cracked by Roath

//northpool.c

inherit ROOM;

void create ()
{
	set ("short", "荷塘边");
	set ("long", @LONG

荷塘北边。塘中碧莲相结，荷香扑面而来。塘面纵横交错架了好
几座小木桥，不知哪一座是通往对岸的。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"wzgmaze5",
		"north" : __DIR__"huangguadi",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));

	set("outdoors", "wuzhuang");

	setup();
}
