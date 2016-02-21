//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "延真楼");
	set ("long", @LONG

延真楼上乃是镇元大仙的私居。中有一供台，上有一玄色七彩丝
的剑鞘。台后挂着幅中堂，上书一个“道”字。小楼三面俱是雕
花扇窗，于周围景致看的清清楚楚。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"eastdown": __DIR__"shuofa",
		"up" : __DIR__"chengyun",
		"westdown": __DIR__"jiangjing",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));


//	set("outdoors", "wuzhuang");

	setup();
}
