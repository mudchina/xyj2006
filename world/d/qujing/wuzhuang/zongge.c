//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "钟阁");
	set ("long", @LONG

钟阁乃是一四方小室，内悬一口巨种，几乎占满了室内的空间，
仅周围有尺许空隙人可通过。东边有小门通到松林中。室内四壁
洁白，纤尘不染。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"west" : __DIR__"eastway3",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));


//	set("outdoors", "wuzhuang");

	setup();
}
