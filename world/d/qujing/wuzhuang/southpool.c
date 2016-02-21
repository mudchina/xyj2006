//Cracked by Roath

//southpool.c

inherit ROOM;

void create ()
{
	set ("short", "荷塘边");
	set ("long", @LONG

荷塘南边。塘中碧莲相结，荷香扑面而来。塘面纵横交错架了好
几座小木桥，不知哪一座是通往对岸的。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"southwest" : __DIR__"shuoyaopu",
		"southeast" : __DIR__"mudanting",
		"north" : __DIR__"wzgmaze1",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));

	set("outdoors", "wuzhuang");

	setup();
}
