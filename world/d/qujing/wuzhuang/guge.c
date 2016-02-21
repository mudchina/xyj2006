//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "鼓阁");
	set ("long", @LONG

鼓阁内成四方，木架上摆着面大鼓，几乎占满了室内的空间，仅
周围有尺许空隙人可通过。西面有小门通到竹林之中。室内四壁
洁白，纤尘不染。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"east" : __DIR__"westway3",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));


//	set("outdoors", "wuzhuang");

	setup();
}
