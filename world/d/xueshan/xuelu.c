//sgzl
inherit ROOM;

void create ()
{
	set ("short", "雪路");
	set ("long", @LONG

茫茫雪野中，远方凝立着一人，手持利刃，威风凛凛，
大概便是雪山派负责迎客的掌门大师兄了。
LONG);


	set("exits", 
	([ //sizeof() == 4
		"north" : __DIR__"xuejie",
		"west" : __DIR__"wroad1",
		"east" : __DIR__"eroad1",
                "southdown" : __DIR__"xuelu2",
	]));
	
	set("objects", 
	([
                __DIR__"npc/zhangmen" : 1,
	]));


	set("outdoors", "xueshan");

	setup();
}



